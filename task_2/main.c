#include "matrix.h"

int main (int argc, char *argv[]) {
  super_errno = 0;
  if (argc < 2) {
    printf("Usage: %s no name of files\n", argv[0]);
    return EXIT_FAILURE;
  }
  else
    if (argc < 3)  {
      printf("Usage: %s the number of files must be >1\n", argv[0]);
      return EXIT_FAILURE;
    }

  FILE *fp_1 = fopen(argv[1], "r");
  if (fp_1 == NULL) {
    printf("File %s can't be opened\n", argv[1]);
    return EXIT_FAILURE;
  }

  Matrix* matrix_1 = create_matrix_from_file(fp_1);  
  if (matrix_1 == NULL || super_errno == 1) {
    fclose(fp_1);
    super_strerror(super_errno);
    return EXIT_FAILURE;
  }
  if (matrix_1 == NULL || super_errno == 2 || super_errno == 4) {
    fclose(fp_1);
    free_matrix(matrix_1);
    super_strerror(super_errno);
    return EXIT_FAILURE;
  }   
  fclose(fp_1);


  for (int i = 2; i < argc; i++) {
    FILE *fp_2 = fopen(argv[i], "r");
    if (fp_2 == NULL) {
      printf("File %s can't be opened\n", argv[i]);
      return EXIT_FAILURE;
    }
    Matrix* matrix_2 =  create_matrix_from_file(fp_2);
    if (matrix_2 == NULL || super_errno == 1) {
      fclose(fp_2); 
      super_strerror(super_errno);
      return (EXIT_FAILURE);
    }
    if (matrix_2 == NULL || super_errno == 2 || super_errno == 4) {
      free_matrix(matrix_1);
      free_matrix(matrix_2);
      fclose(fp_2);
      super_strerror(super_errno);
      return (EXIT_FAILURE);
    }
    fclose(fp_2);
    Matrix* matrix_3 = matrix_1;
    matrix_1 = matrix_multiplication(matrix_1, matrix_2);
    if (matrix_1 == NULL || super_errno == 3) {
      free_matrix(matrix_1);
      free_matrix(matrix_2);
      super_strerror(super_errno);
      return (EXIT_FAILURE);
    }
    free_matrix(matrix_3);
    free_matrix(matrix_2);    
  }
  print_matrix(matrix_1);
  free_matrix(matrix_1);
}
