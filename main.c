#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>
#include "lib/fsmap/fsmap.h"

int main(void) {
  initscr();

  // Open the current directory.
  const char *curdir_name = fsmap_get_curdir();
  DIR *curdir = opendir(curdir_name);
  if (curdir == NULL) {
    fprintf(stderr, "fd: unable to open %s.\n", curdir_name);
    return EXIT_FAILURE;
  }
  
  // Display all entries in the current directory.
  struct dirent *dir;
  while ((dir = readdir(curdir)) != NULL) {
    printw("%s\n", dir->d_name);
    refresh();
  }

  getch();
  endwin();

  return EXIT_SUCCESS;
}
