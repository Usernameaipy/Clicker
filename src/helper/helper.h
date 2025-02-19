#ifndef Gtk_Gtk_h
#define Gtk_Gtk_h
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif
#ifndef HELPER_H
#define HELPER_H
#include <stdbool.h>
#include <stdio.h>
bool get_string(FILE *, char *, size_t);
bool check_file(FILE *);
bool open_fl_rplus(const char *, FILE **);
bool get_file(size_t *, const char *, size_t);
unsigned int get_winid(gint);
#endif