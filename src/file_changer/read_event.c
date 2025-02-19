#include "read_event.h"

user_click **read_event(size_t quantity) {
  user_click **tmp = (user_click **)malloc(sizeof(user_click *) * quantity);
  if (tmp) {
    FILE *read_file = fopen("../bin/clicks", "rb");
    if (read_file) {
      for (size_t i = 0; i < quantity; i++) {
        tmp[i] = (user_click *)malloc(sizeof(user_click));
        if (!tmp[i] || !fread(tmp[i], sizeof(user_click), 1, read_file))
          continue;
      }
    }
    if (read_file) fclose(read_file);
  }
  return tmp;
}