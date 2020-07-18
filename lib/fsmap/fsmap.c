#include "fsmap.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

const char *fsmap_get_curdir(void) {
  char buff[FILENAME_MAX];
  return getcwd(buff, FILENAME_MAX);
}

void fsmap_display_stats(const char *file) {
  struct stat fstat;
  stat(file, &fstat);
  printf("st_dev: %ld\n" \
         "st_ino: %ld\n" \
         "st_mode: %d\n" \
         "st_nlink: %ld\n" \
         "st_uid: %d\n" \
         "st_gid: %d\n" \
         "st_rdev: %ld\n" \
         "st_size: %ld\n" \
         "st_atime: %ld\n" \
         "st_mtime: %ld\n" \
         "st_ctime: %ld\n" \
         "st_blksize: %ld\n" \
         "st_blocks: %ld\n",
         fstat.st_dev,
         fstat.st_ino,
         fstat.st_mode,
         fstat.st_nlink,
         fstat.st_uid,
         fstat.st_gid,
         fstat.st_rdev,
         fstat.st_size,
         fstat.st_atime,
         fstat.st_mtime,
         fstat.st_ctime,
         fstat.st_blksize,
         fstat.st_blocks);
}
