#include "player.h"
#include "map.h"
#include "maths.h"

bool player_init(player *player, struct map *map)
{
    if (!player || !map)
        return false;

    player->pos = position_to_accurate(map->player_spawn);
    if (get_cell(map, player->pos) == 1) {
        fprintf(stderr, "Error: Player spawn position is inside a wall.\n");
        return false;
    }
    player->angle = map->spawn_angle;
    player->move_speed = 0.1;
    player->rotation_speed = 0.05;
    player->jump_height = 1.0;
    player->vertical_speed = 0.0;
    player->gravity = 9.81;
    player->is_jumping = false;
    player->is_falling = false;

    return true;
}