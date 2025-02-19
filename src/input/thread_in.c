#include "thread_in.h"

void thread_in(GtkWidget *button, gpointer user_data) {
  g_thread_new("input", input, user_data);
}