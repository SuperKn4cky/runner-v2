#ifndef LINE_H_
#define LINE_H_

#include <lapin.h>

struct line {
    int              width_diff;
    int              height_diff;
    float            ratio;
    t_bunny_position position;
    t_bunny_position pos_a;
    t_bunny_position pos_b;
    t_bunny_position good_pos_a;
    t_bunny_position good_pos_b;
};

#endif // LINE_H_
