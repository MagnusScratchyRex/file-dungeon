#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>
#include "lib/fsmap/fsmap.h"

#define MOVING_WINDOW 410

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
  int roomx = COLS / 2;
  int roomy = LINES / 2;
  int roomsize = 20;
  WINDOW *room = subwin(stdscr, roomsize, roomsize, roomy, roomx);
  box(room, ACS_VLINE, ACS_HLINE);
  struct dirent *dir;
  int i = 1;
  while ((dir = readdir(curdir)) != NULL) {
    mvwprintw(room, i, 1, "%s\n", dir->d_name);
    i++;
  }

  while (1) {
    wrefresh(room);
    if (getch() != MOVING_WINDOW) {
      break;
    }
  }

  endwin();
  return EXIT_SUCCESS;
}
