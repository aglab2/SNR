#ifndef BOB_HEADER_H
#define BOB_HEADER_H

#include "types.h"

extern const Trajectory bob_seg7_metal_ball_path0[];
extern const Trajectory bob_seg7_metal_ball_path1[];
extern const Trajectory bob_seg7_trajectory_koopa[];

// script
extern const LevelScript level_bob_entry[];

#include "levels/bob/header.inc.h"

#include "levels/bob/bob_init/geo_header.h"

#include "levels/bob/bob_init/collision_header.h"

#include "levels/bob/bob_move/geo_header.h"

#include "levels/bob/bob_move/collision_header.h"

#endif
