#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZEBUF 3

const int count_a(FILE *fp, const char *word, int *mas_a) {
  char *new_buf;
  int bufsize = SIZEBUF;
  char *buf = (char*) malloc(bufsize + 1);
  int a_one = 0, c;
  static int j = 0;
  int i = 0;

  if (buf == NULL) {	
    printf("No memory available\n");
    return EXIT_FAILURE;
  }
  new_buf = buf;
  while((c = fgetc(fp)) != EOF) {
    if(!(ispunct(c)) && !(isspace(c))) {
      buf[i] = c;
      i ++;
      if(i == bufsize) {
        bufsize = bufsize << 1;
        new_buf = buf;
        if((buf = (char*) realloc(new_buf, bufsize)) == NULL) {
          printf("No memory available\n"); 
          free(new_buf);
          return EXIT_FAILURE;
        }
      }
    }
    else {
      buf[i] = '\0';
      if(strcmp(buf,word) == 0)
        a_one ++;	
      if(i > 0)
        printf("%s\n", buf);	
      i = 0;
    }
  }
  mas_a[j++] = a_one;
  printf("j = %d, a_one = %d\n", j , a_one);
  a_one = 0;
  free (buf);
}

const double average(int *mas_a, int a_size) {
  int a_sum = 0;

  for(int i = 0; i < a_size; i ++)
    a_sum += mas_a[i];
  return((double)(a_sum)/(double)(a_size));
}

const double dispersion(int *mas_a, int a_size) {
  double a_average = average(mas_a, a_size);
  double a_total = 0;

  printf("a_average = %f\n", a_average);
  for(int i = 0; i < a_size; i++)
    a_total += pow(((double)mas_a[i] - a_average), 2);
  return(sqrt((a_total /(a_size - 1))));
}


