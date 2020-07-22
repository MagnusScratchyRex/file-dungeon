#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "fsmap.h"

const char *fsmap_get_curdir(void) {
  char buff[FILENAME_MAX];
  return getcwd(buff, FILENAME_MAX);
}

bool fsmap_is_dotfile(const char *filepath) {
  return (*(fsmap_get_filename(filepath)) == '.');
}

const char *fsmap_get_filename(const char *filepath) {
  const char *ptr = filepath;
  const char *filename = filepath;
  while (*ptr != '\0') {
    if (*ptr == '/') {
      filename = ptr + 1; // Get the character just after the '/'
    }
    ++ptr;
  }
  return filename;
}

const char *fsmap_get_file_extension(const char *filepath) {
  const char *filename = fsmap_get_filename(filepath);
  const char *extension; 
  if (fsmap_is_dotfile(filename)) {
    extension = strchr(filename + 1, '.');
  } else {
    extension = strchr(filename, '.');
  }
  return extension == NULL ? NULL : extension + 1;
}
