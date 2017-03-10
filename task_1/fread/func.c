#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#define SIZEBUF 3

const int count_a (FILE *fp, const char *word, int *mas_a) {
    char *buf, *new_buf;
	int bufsize = SIZEBUF;
    int a_one = 0, c, count = 0;
	static int j = 0;
	
    if ((buf = (char *) malloc (bufsize + 1)) == NULL) {	
		printf("No memory available\n");
		return EXIT_FAILURE;
	}
	new_buf = buf;
    while ((c = fgetc(fp)) != EOF) {
        if (!(ispunct(c)) && !(isspace(c))) {
			*new_buf = c;
			count ++;
			if (count == bufsize) {
				bufsize = bufsize << 1;
				if ((buf = (char*) realloc (buf, bufsize)) == NULL) {
					printf("No memory available\n");
				 	return EXIT_FAILURE;
				}
				new_buf = buf + count;
			}
			new_buf ++;
			
		}
		else {
			*new_buf = '\0';
			new_buf = buf;
			if (strcmp(new_buf,word) == 0)
                a_one ++;	
                if (count > 0)
				    printf("%s\n", buf);	
			    count = 0;
		}
    }
    mas_a[j++] = a_one;
    printf ("j = %d, a_one = %d\n", j , a_one);
    a_one = 0;
}

const double average (int *mas_a, int a_size) {
    int a_sum = 0;
    
    for (int i = 0; i < a_size; i++)
        a_sum += mas_a[i];
    return ((double)(a_sum)/(double)(a_size));
}

const double dispersion (int *mas_a, int a_size) {
    double a_average = average (mas_a, a_size);
    double a_total = 0;
    
    printf ("a_average = %f\n", a_average);
        for (int i = 0; i < a_size; i++)
            a_total += pow(((double)mas_a[i] - a_average), 2);
    return (sqrt((a_total / (a_size - 1))));
}


