// Up water

#include "engine/surface_collision.h"

extern u8 gDisableGravity;

void bhv_hmc_ctl_loop()
{
    gDisableGravity = 0;
    if (gMarioStates->controller->buttonPressed & Z_TRIG)
    {
        if (o->oAction == 0)
            play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
        
        o->oAction = 1;
    }
    else
    {
        o->oAction = 0;
    }
    gMarioStates->controller->buttonDown &= ~Z_TRIG;
    gMarioStates->controller->buttonPressed &= ~Z_TRIG;

    gCollisionFlags |= COLLISION_FLAG_WATER;
    int gm0 = gIsGravityFlipped;
    int gm1 = gGravityMode;
    gIsGravityFlipped = 0;
    gGravityMode = 0;

    f32 marioY = gm0 ? (8825.f - gMarioStates->pos[1]) : gMarioStates->pos[1];

    struct Surface* floor = NULL;
    f32 floorHeight = find_floor(gMarioStates->pos[0], marioY, gMarioStates->pos[2], &floor);
    if (floorHeight == FLOOR_LOWER_LIMIT)
    {    
        gIsGravityFlipped = gm0;
        gGravityMode = gm1;
        gCollisionFlags &= ~COLLISION_FLAG_WATER;
        set_gravity(0);
        return;
    }

    struct Surface* ceil = NULL;
    f32 ceilHeight = find_ceil(gMarioStates->pos[0], floorHeight, gMarioStates->pos[2], &ceil);

    gIsGravityFlipped = gm0;
    gGravityMode = gm1;
    gCollisionFlags &= ~COLLISION_FLAG_WATER;

    s32 grav = 0;
    if (floorHeight - 50.f < marioY && marioY < ceilHeight)
    {
        if (!gIsHM)
        {
            if (gMarioStates->controller->buttonPressed & B_BUTTON)
            {
                if (o->oF4 == 0)
                    play_sound(SOUND_OBJ_MIPS_RABBIT_WATER, gGlobalSoundSource);
                
                o->oF4 = 1;
            }
            else
            {
                o->oF4 = 0;
            }

            gMarioStates->controller->buttonDown &= ~B_BUTTON;
            gMarioStates->controller->buttonPressed &= ~B_BUTTON;
            gDisableGravity = 1;
            gMarioStates->action = ACT_JUMP;

            f32 raisevel = 4.f;
            gMarioStates->vel[1] += raisevel;

            f32 maxvel = 60.f;
            if (gMarioStates->vel[1] > maxvel)
                gMarioStates->vel[1] = maxvel;
        }
        else
        {
            grav = 1;
        }
    }

    set_gravity(grav);
}
