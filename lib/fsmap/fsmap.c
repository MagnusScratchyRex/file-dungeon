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

enum filetypes { TEXT = 0 , AUDIO = 1, VIDEO = 3, IMAGE = 4, EXEC };
static const char *text_extensions[6] = { "txt", "c", "h", "md", "rb", "py" };
static const char *audio_extensions[] = { "mp3", "ogg", "wav", "flac" };
static const char *video_extensions[] = { "mp4", "mkv", "flv" };
static const char *image_extensions[] = { "png", "jpg", "jpeg", "svg", "webp" };
static const char **extensions[4] = {
  text_extensions,
  audio_extensions,
  video_extensions,
  image_extensions
};

int fsmap_guess_filetype(const char *filepath) {

  /*
  printf("TEXT:\n");
  for (int i = 0; i < 6; i++) {
    printf("%s\n", extensions[TEXT][i]);
  }

  printf("AUDIO:\n");
  for (int i = 0; i < 4; i++) {
    printf("%s\n", extensions[AUDIO][i]);
  }
  */

  return filepath == NULL;
}
