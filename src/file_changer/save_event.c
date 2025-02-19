#include "save_event.h"

bool save_event(user_click **clicks, size_t size) {
  bool res = false;
  FILE *save_file = fopen("../bin/clicks", "wb");
  if (save_file) res = true;
  if (res) {
    for (size_t i = 0; i < size && res; i++) {
      if (fwrite(clicks[i], sizeof(user_click), 1, save_file) != 1) {
        res = false;
        fclose(save_file);
      }
    }
    fclose(save_file);
  }
  return res;
}