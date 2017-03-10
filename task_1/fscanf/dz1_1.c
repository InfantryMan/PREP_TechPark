#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include "func.h"

int main (int argc, char *argv []) {
  if (argc < 3) {
    printf ("Usage: %s no names of files\n", argv[0]);
    return EXIT_FAILURE;
  }
  else
    if (argc == 3) {
      printf ("Usage: %s the number of files must be > 1\n", argv[0]);
      return EXIT_FAILURE;
    }

  int *mas;
  if ((mas = (int*) malloc ((argc-2)*sizeof(int))) == NULL) {
    printf("No memory available\n");
    return EXIT_FAILURE;
  }

  FILE *fp;
  for (int i = 0; i < argc - 2; i++) {
    if ((fp = fopen(argv[i + 2],"r")) == NULL) {
      printf("File %s can't be opened\n", argv[i + 2]);
      return EXIT_FAILURE;
    }
    count_a (fp, argv[1], mas);
  }

  printf ("Dispersion = %f\n", dispersion(mas, argc - 2));

  free ((void *)mas);
  fclose(fp);
  return EXIT_SUCCESS;	
}
