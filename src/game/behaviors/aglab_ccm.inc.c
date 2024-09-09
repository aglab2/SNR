extern u8 sDeferGravSwap;

void bhv_ccm_flipper_loop()
{
    if (o->oDistanceToMario < 100.f)
    {
        sDeferGravSwap = 1;
        o->activeFlags = 0;
    }

    if ((o->oTimer % 8) == 0)
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX = o->oPosX + random_f32_around_zero(50.f);
        spark->oPosY = o->oPosY  + random_f32_around_zero(50.f);
        spark->oPosZ = o->oPosZ + random_f32_around_zero(50.f);
    }
}
