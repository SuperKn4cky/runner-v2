#include "map.h"
#include "player.h"

bool is_wall(map *map, t_accurate_pos pos)
{
    char cell = get_cell(map, pos);
    if (cell != '0') {
        return true;
    }
    return false;
}

unsigned int get_cell(map *map, t_accurate_pos pos)
{
    int x = (int)pos.x;
    int y = (int)pos.y;

    if (!map || !is_within_bounds(map, pos)) {
        return 99;
    }

    return map->grid[y * map->width + x];
}

bool is_within_bounds(map *map, t_accurate_pos pos)
{
    if (!map)
        return false;

    unsigned int x = (int)pos.x;
    unsigned int y = (int)pos.y;

    return (x < map->width && y < map->height);
}