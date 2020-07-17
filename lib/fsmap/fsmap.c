#include "fsmap.h"

const char *fsmap_get_curdir(void) {
  char buff[FILENAME_MAX];
  return getcwd(buff, FILENAME_MAX);
}
