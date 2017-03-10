#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include "func.h"

int main(int argc, char *argv []) {

  if(argc < 3) {
    printf("Usage: %s no names of files\n", argv[0]);
    return EXIT_FAILURE;
  }

  else
    if(argc == 3) {
      printf("Usage: %s the number of files must be > 1\n", argv[0]);
      return EXIT_FAILURE;
    }

  int *mas = (int*) malloc((argc-2) * sizeof (int));

  if (mas == NULL) {
    printf("No memory available\n");
    return EXIT_FAILURE;
  }

  for(int i = 0; i < argc - 2; i++) {
    FILE *fp = fopen (argv[i + 2], "r");
    if (fp == NULL) {
      printf("File %s can't be opened\n", argv[i + 2]);
      return EXIT_FAILURE;
    }
    count_a(fp, argv[1], mas);
    free(fp);
  }

  printf("Dispersion = %f\n", dispersion(mas, argc - 2));

  free((void *)mas);
  return EXIT_SUCCESS;	
}
