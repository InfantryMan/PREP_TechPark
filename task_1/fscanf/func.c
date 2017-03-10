#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

#define SIZEBUF 1024

void count_a (FILE *fp, const char *word, int *mas_a) {
  char buf [SIZEBUF];
  int a_one = 0;
  static int i = 0;

  while (fscanf(fp, "%s", buf) != EOF) {
    if (strcmp(buf,word) == 0)
      a_one ++;
    printf("%s\n", buf);
  }
  mas_a[i++] = a_one;
  printf ("i = %d, a_one = %d\n", i , a_one);
  a_one = 0;
}

double average (int *mas_a, int a_size) {
  int a_sum = 0;
  for (int i = 0; i < a_size; i++)
    a_sum += mas_a[i];
  return ((double)(a_sum)/(double)(a_size));
}

double dispersion (int *mas_a, int a_size) {
  double a_average = average (mas_a, a_size);
  double a_total = 0;
  printf ("a_average = %f\n", a_average);
  for (int i = 0; i < a_size; i++)
    a_total += pow(((double)mas_a[i] - a_average), 2);
  return (sqrt((a_total / (a_size - 1))));
}


