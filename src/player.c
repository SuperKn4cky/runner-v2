#include "player.h"
#include "maths.h"

bool player_init(player *player, t_bunny_position spawn, double spawn_angle)
{
    if (!player)
        return false;

    player->pos = position_to_accurate(spawn);
    player->angle = spawn_angle;
    player->move_speed = 0.1;
    player->rotation_speed = 0.05;
    player->jump_height = 1.0;
    player->vertical_speed = 0.0;
    player->gravity = 9.81;
    player->is_jumping = false;
    player->is_falling = false;

    return true;
}