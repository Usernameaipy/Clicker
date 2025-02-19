#include "thread_cl.h"

void thread_cl(GtkWidget *button, gpointer user_data) {
  g_thread_new("click", click, user_data);
}