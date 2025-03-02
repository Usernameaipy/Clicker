#include "input.h"

void* input(gpointer user_data) {
  Display* display = XOpenDisplay(NULL);
  int screen = DefaultScreen(display);
  int screen_width = DisplayWidth(display, screen);
  int screen_height = DisplayHeight(display, screen);
  XVisualInfo vinfo;
  XMatchVisualInfo(display, DefaultScreen(display), 32, TrueColor, &vinfo);
  XSetWindowAttributes attr;
  attr.colormap = XCreateColormap(display, DefaultRootWindow(display),
                                  vinfo.visual, AllocNone);
  attr.border_pixel = 0;
  attr.background_pixel = 0x10000000;
  Window window =
      XCreateWindow(display, DefaultRootWindow(display), 0, 0, screen_width,
                    screen_height, 0, vinfo.depth, InputOutput, vinfo.visual,
                    CWColormap | CWBorderPixel | CWBackPixel, &attr);
  XSelectInput(display, window, ButtonPressMask | KeyPressMask);
  XMapWindow(display, window);
  XFlush(display);
  size_t quantity;
  size_t len_now = 0;
  get_file(&quantity, "../config/qclick.conf", 10);
  user_click** clicks = (user_click**)malloc(sizeof(user_click*) * quantity);
  XEvent event;
  GtkWidget* combo_box = GTK_WIDGET(user_data);
  unsigned int id =
      get_winid(gtk_combo_box_get_active(GTK_COMBO_BOX(combo_box)));
  while (len_now < quantity) {
    XNextEvent(display, &event);
    if (event.type == ButtonPress) {
      record_mouse_click(display, &event, id, clicks, &len_now, quantity);
    }
    if (event.type == KeyPress) {
      record_key_press(display, &event, id, clicks, &len_now, quantity);
    }
  }
  save_event(clicks, quantity);
  if (clicks) {
    for (size_t i = 0; i < quantity; i++)
      if (clicks[i]) free(clicks[i]);
    free(clicks);
  }
  XDestroyWindow(display, window);
  XCloseDisplay(display);
  return NULL;
}

void record_mouse_click(Display* dsp, XEvent* event, unsigned int id,
                        user_click** clicks, size_t* len_now, size_t quantity) {
  if (*len_now < quantity) {
    user_click* temp = (user_click*)malloc(sizeof(user_click));
    if (temp) {
      temp->type = actions_mouse;
      temp->mouse.x = event->xbutton.x;
      temp->mouse.y = event->xbutton.y;
      clicks[*len_now] = temp;
      *len_now += 1;
    }
  }
}

void record_key_press(Display* dsp, XEvent* event, unsigned int id,
                      user_click** clicks, size_t* len_now, size_t quantity) {
  if (*len_now < quantity) {
    user_click* temp = (user_click*)malloc(sizeof(user_click));
    if (temp) {
      temp->type = actions_key;
      temp->keyboard.key = (KeyCode)XLookupKeysym(&event->xkey, 0);
      clicks[*len_now] = temp;
      *len_now += 1;
    }
  }
}