#ifndef Gtk_Gtk_h
#define Gtk_Gtk_h
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif
#ifndef X11_LIBS
#define X11_LIBS
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#endif
#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <X11/extensions/Xcomposite.h>
#include <X11/extensions/Xrender.h>
#endif
#ifndef INPUT_H
#define INPUT_H
#include <stdlib.h>

#include "../file_changer/save_event.h"
#include "../helper/helper.h"
#include "user_click.h"
void *input(gpointer);
void record_mouse_click(Display *, XEvent *, unsigned int, user_click **,
                        size_t *, size_t);
void record_key_press(Display *, XEvent *, unsigned int, user_click **,
                      size_t *, size_t);
#endif