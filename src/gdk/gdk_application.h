#ifndef Gtk_Gtk_h
#define Gtk_Gtk_h
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif
#ifndef GDK_APPLICATION_H
#define GDK_APPLICATION_H
#include "../clicker/thread_cl.h"
#include "../helper/helper.h"
#include "../input/thread_in.h"
#include "gdk_change_entry.h"
#include "get_windata.h"
void an_activate(GtkApplication *);
void create_combo_box(GtkWidget *);
#endif