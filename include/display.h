#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "types.h"
#include <lapin.h>

typedef struct {
    t_bunny_window     *ds_win;
    t_bunny_pixelarray *ds_px;
} display;

bool display_init(display *d);
void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);
void display_refresh(display *d);
void display_cleanup(display *d);

#endif /* !DISPLAY_H_ */
