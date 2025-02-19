#include "click.h"

void *click(gpointer user_data) {
  GtkWidget *combo_box = GTK_WIDGET(user_data);
  unsigned int id =
      get_winid(gtk_combo_box_get_active(GTK_COMBO_BOX(combo_box)));
  Window target_window = id;
  size_t time = 0, quantity = 0, symbols = 0;
  get_file(&time, "../config/time.conf", 1);
  get_file(&quantity, "../config/qrepets.conf", 60);
  get_file(&symbols, "../config/qclick.conf", 10);
  Display *display = XOpenDisplay(NULL);
  if (display == NULL) {
    fprintf(stderr, "ERROR DISPLAY");
    return NULL;
  }
  user_click **clicks = read_event(symbols);
  for (size_t i = 0; i < quantity; i++) {
    for (size_t j = 0; j < symbols; j++) {
      if (clicks[i]->type == actions_key) {
        char str[2];
        str[0] = clicks[i]->keyboard.key;
        str[1] = '\0';
        KeyCode keycode = XKeysymToKeycode(display, XStringToKeysym(str));
        XSetInputFocus(display, target_window, RevertToPointerRoot,
                       CurrentTime);
        XFlush(display);
        XTestFakeKeyEvent(display, keycode, True, 0);
        XFlush(display);
        XTestFakeKeyEvent(display, keycode, False, 0);
        XFlush(display);
        g_usleep(time * 1000000);
      } else if (clicks[i]->type == actions_mouse) {
        XSetInputFocus(display, target_window, RevertToPointerRoot,
                       CurrentTime);
        XFlush(display);
        int x = clicks[i]->mouse.x;
        int y = clicks[i]->mouse.y;
        XTestFakeMotionEvent(display, 0, x, y, CurrentTime);
        XFlush(display);
        XTestFakeButtonEvent(display, 1, TRUE, CurrentTime);
        XFlush(display);
        XTestFakeButtonEvent(display, 1, FALSE, CurrentTime);
        XFlush(display);
        g_usleep(time * 1000000);
      }
    }
  }
  if (clicks) {
    for (size_t i = 0; i < symbols; i++)
      if (clicks[i]) free(clicks[i]);
    free(clicks);
  }
  if (display) XCloseDisplay(display);
  return NULL;
}