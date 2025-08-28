#include "display.h"

void display_cleanup(display *display)
{
    bunny_stop(display->ds_win);
    display->ds_win = NULL;
    display->ds_px = NULL;
}

void display_refresh(display *display)
{
    bunny_blit(&display->ds_win->buffer, &display->ds_px->clipable, NULL);
    bunny_display(display->ds_win);
}

bool display_init(display *display)
{
    display->ds_win = bunny_start(800, 600, false, "Runner v2");
    if (!display->ds_win) {
        return false;
    }
    display->ds_px = bunny_new_pixelarray(800, 600);
    if (!display->ds_px) {
        display_cleanup(display);
        return false;
    }
    bunny_set_mouse_visibility(display->ds_win, false);
    clear_pixelarray(display->ds_px, 0x000000FF);
    display_refresh(display);
    return true;
}