#ifndef PLAYER_H_
#define PLAYER_H_

#include "types.h"
#include <lapin.h>

typedef struct {
    t_accurate_pos pos;
    double         move_speed;
    double         rotation_speed;
    double         view_angle;
    unsigned int   current_level;
    double         jump_height;
    double         vertical_speed;
    double         gravity;
    bool           is_jumping;
    bool           is_falling;
} player;

bool player_init(player *p, t_bunny_position spawn);
void player_start_jump(player *p, double initial_speed);
void player_update_vertical_position(player *p, double delta_time);
void player_reset_vertical_movement(player *p);

#endif /* !PLAYER_H_ */
