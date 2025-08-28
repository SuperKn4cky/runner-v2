#include "maths.h"

t_bunny_position accurate_to_position(t_accurate_pos accurate_pos)
{
    t_bunny_position pos;

    pos.x = accurate_pos.x;
    pos.y = accurate_pos.y;
    return pos;
}

t_accurate_pos position_to_accurate(t_bunny_position pos)
{
    t_accurate_pos accurate_pos;

    accurate_pos.x = pos.x;
    accurate_pos.y = pos.y;
    return accurate_pos;
}

double deg_to_rads(double degrees) { return (degrees * (2 * M_PI)) / 360; }

float get_ratio(int a, int b, int x)
{
    float ratio;
    float tmp;

    if (a == b) {
        return 1;
    }
    tmp = (b - a);
    return (ratio = (x - a) / tmp);
}

int get_value(int a, int b, float ratio)
{
    float tmp;
    int   value;

    tmp = (ratio * (b - a) + a);
    value = tmp;
    return (value);
}
