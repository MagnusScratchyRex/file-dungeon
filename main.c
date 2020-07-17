#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>

int main(int argc, const char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "fd: not enough argument.\n");
    return EXIT_FAILURE;
  }
  
  initscr();

  DIR *current_dir = opendir(argv[1]);
  if (current_dir == NULL) {
    fprintf(stderr, "fd: unable to open %s.\n", argv[1]);
    return EXIT_FAILURE;
  }
  
  struct dirent *dir;
  while ((dir = readdir(current_dir)) != NULL) {
    printw("%s\n", dir->d_name);
    refresh();
  }

  getch();
  endwin();

  return EXIT_SUCCESS;
}
