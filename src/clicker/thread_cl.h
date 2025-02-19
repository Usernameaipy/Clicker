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
#ifndef THREAD_CL_H
#define THREAD_CL_H
#include "click.h"
void thread_cl(GtkWidget*, gpointer);
#endif