#include "helper.h"

bool get_string(FILE *file, char *string, size_t len) {
  bool flag = false;
  if (fgets(string, len, file)) flag = true;
  return flag;
}

bool check_file(FILE *file) {
  bool ret = false;
  if (file != NULL) {
    long curs = ftell(file);
    int ch = fgetc(file);
    fseek(file, curs, SEEK_SET);
    ret = (ch != EOF) ? true : false;
  }
  return ret;
}

bool open_fl_rplus(const char *fl, FILE **file) {
  bool res = false;
  *file = fopen(fl, "r+");
  if ((*file) != NULL) {
    res = true;
  }
  return res;
}

bool get_file(size_t *value, const char *filename, size_t stdval) {
  bool res = false;
  FILE *file = NULL;
  if (open_fl_rplus(filename, &file)) {
    fscanf(file, "%lu", value);
    fclose(file);
    res = true;
  } else {
    file = fopen(filename, "w");
    if (file) {
      fprintf(file, "%lu", stdval);
      fclose(file);
      res = true;
    }
  }
  return res;
}

unsigned int get_winid(gint pos) {
  FILE *file = NULL;
  bool flag = open_fl_rplus("../config/id.conf", &file);
  if (flag) flag = check_file(file);
  unsigned int res;
  if (flag) {
    for (int i = 0; i < (int)pos + 1 && flag != false; i++)
      if (fscanf(file, "%x", &res) != 1) flag = false;
  }
  if (file != NULL) fclose(file);
  return res;
}