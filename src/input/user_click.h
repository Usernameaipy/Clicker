#ifndef Gtk_Gtk_h
#define Gtk_Gtk_h
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif
#ifndef USER_CKICK_H
#define USER_CKICK_H
typedef enum action_type { actions_mouse, actions_key } action_type;
typedef struct {
  action_type type;
  union {
    struct {
      int x;
      int y;
    } mouse;
    struct {
      KeyCode key;
    } keyboard;
  };
} user_click;
#endif