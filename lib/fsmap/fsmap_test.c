#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "fsmap.h"

// one: return 1.
int one(const void *unused) {
  // Trick the compiler with -Werror=unused-variable/-Werror=unused-parameter to
  // return 1 anyway (because true == 1). Got ya, compiler!
  const void *ptr = unused;
  return (ptr == unused);
}

int main(void) {
  // Display a list the files of the the current working directory followed by
  // their file extension and filetype
  struct dirent **entries;
  int nentries = scandir("./", &entries, (int (*)(const struct dirent *))one,
      alphasort);
  if (nentries >= 0) {
    for (int i = 0; i < nentries; i++) {
      printf("filename='%s', extension='%s', filetype=%d\n",
          entries[i]->d_name,
          fsmap_get_file_extension(entries[i]->d_name),
          fsmap_guess_filetype(entries[i]->d_name));
    }
  } else {
    perror("Couldn't open the directory");
  }
  return EXIT_SUCCESS;
}
