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
    extension = strchr(filename + 1, '.'); // Don't take the beginning dot
  } else {
    extension = strchr(filename, '.');
  }
  return (extension == NULL ? NULL : extension + 1);
}

// Extensions array end with NULL to mark as a stop for the pointer in
// fsmap_guess_filetype
static const char *text_extensions[] = { "txt", "c", "h", "md", "rb", NULL };
static const char *audio_extensions[] = { "mp3", "ogg", "wav", "flac", NULL };
static const char *video_extensions[] = { "mp4", "mkv", "flv", NULL };
static const char *image_extensions[] = { "png", "jpg", "jpeg", "svg", NULL };

#define NB_FILETYPES 4 // Filetypes that can be found via file extensions

// Each extension arrays must stay in the same order as the one defined in the
// filetype enum.
static const char **extensions[NB_FILETYPES] = {
  text_extensions,
  audio_extensions,
  video_extensions,
  image_extensions
};


filetype fsmap_guess_filetype(const char *filepath) {
  // TODO: check for executable first
  const char *ext = fsmap_get_file_extension(filepath);
  if (ext == NULL) {
    return UNKNOWN;
  }

  const char *ptr;
  for (int i = 0; i < NB_FILETYPES; i++) {
    int k = 0;
    ptr = extensions[i][k];
    while (ptr != NULL) {
      if (strcmp(ptr, ext) == 0) {
        return i;
      }
      k++;
      ptr = extensions[i][k];
    }
  }

  return UNKNOWN;
}
