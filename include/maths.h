#ifndef MATHS_H_
#define MATHS_H_

#include "types.h"
#include <lapin.h>

double           deg_to_rads(double degrees);
t_bunny_position accurate_to_position(t_accurate_pos accurate_pos);
t_accurate_pos   position_to_accurate(t_bunny_position pos);
float            get_ratio(int a, int b, int x);
int              get_value(int a, int b, float ratio);

#endif /* !MATHS_H_ */