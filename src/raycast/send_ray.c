#include "map.h"

t_accurate_pos move_forward(const t_accurate_pos *start, double angle, double len)
{
    t_accurate_pos current_pos;

    current_pos.x = (cos(angle) * len) + start->x;
    current_pos.y = ((sin(angle) * len) * -1) + start->y;
    return (current_pos);
}

ray_result send_ray(map *map, const t_accurate_pos *start, double angle)
{
    t_accurate_pos current_pos;
    double         step, distance;

    ray_result result = {0};

    if (!map || !start)
        return (result);

    step = 0.005;
    distance = 0;
    current_pos = move_forward(start, angle, step);
    while (!is_wall(map, current_pos)) {
        current_pos = move_forward(&current_pos, angle, step);
        distance += step;
    }
    result.pos = current_pos;
    result.distance = distance;
    return (result);
}
