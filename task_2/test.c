#include <assert.h>

#include "matrix.h"

int main () {
  FILE* fp = fopen("test1.txt", "r");
  assert(fp);
  Matrix* matrix = create_matrix_from_file(fp);
  fp = fopen("test2.txt", "r");
  assert(fp);
  free_matrix(matrix);
  FILE* fp1 = fopen("test3.txt", "r");
  assert(fp1);
  Matrix* matrix1 = create_matrix_from_file(fp);
  Matrix* matrix2 = create_matrix_from_file(fp1); 
  matrix_multiplication(,create_matrix_from_file(fp1));
  fclose(fp);
  fclose(fp1);
} 



