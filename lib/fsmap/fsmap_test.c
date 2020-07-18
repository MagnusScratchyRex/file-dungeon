#include <stdlib.h>
#include <stdio.h>
#include "fsmap.h"

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    //FILE *f = fopen(argv[i], "r");
    //if (f == NULL) {
    //  fprintf(stderr, "%s: unable to open %s;\n", __FILE__, argv[i]);
    //  return EXIT_FAILURE;
    //}

    fsmap_display_stats(argv[i]);
    return EXIT_SUCCESS;
  }
}
