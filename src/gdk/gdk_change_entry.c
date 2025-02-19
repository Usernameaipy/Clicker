#include "gdk_change_entry.h"

void change_entry(GtkEntry *entry, gpointer user_data) {
  FILE *file = NULL;
  const char *filename = (char *)user_data;
  if (open_fl_rplus(filename, &file)) {
    fclose(file);
    file = fopen(filename, "w");
    if (file) {
      fprintf(file, "%lu",
              (long unsigned)atoi((char *)gtk_entry_get_text(entry)));
      fclose(file);
    }
  } else {
    size_t temp;
    get_file(&temp, filename,
             (long unsigned)atoi((char *)gtk_entry_get_text(entry)));
  }
}