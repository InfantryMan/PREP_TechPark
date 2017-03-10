#include "matrix.h"

Matrix* create_matrix_from_file(FILE* file) { 
  int row, col, num_not_null;
  double val;

  if  (fscanf(file, "%d %d %d", &row, &col, &num_not_null) != 3) {
    printf("Error in fscanf\n");
    return NULL;
  }

  Matrix* matrix = create_matrix(row, col);

  for (int i = 0; i < num_not_null; i++) {
    if (fscanf(file, "%d %d %lf", &row, &col, &val) != 3) {
      super_errno = 1;
      return NULL;
    }
    set_elem(matrix, row, col, val);
    if (super_errno == 4)
      return NULL;
  }
  return matrix;
}

Matrix* create_matrix(int row, int col) {
  Matrix *matrix = (Matrix*) malloc(sizeof(Matrix) * (row * col + 1)); // +1 for size parametrs in 0 byte

  if (matrix == NULL) {
    super_errno = 2;
    return NULL;
  }
  matrix[0].row = row; //in 0 byte save rows and columns
  matrix[0].col = col;
  matrix[0].val = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      matrix[j + 1 + i * col].col = j;
      matrix[j + 1 + i * col].row = i;
      matrix[j + 1 + i * col].val = 0;
    } 
  return matrix;
}

void free_matrix(Matrix* matrix) {
  free ((Matrix*) matrix);
}

double get_elem(Matrix* matrix, int row, int col) {
  return (matrix[row * get_cols(matrix) + col + 1].val);
}

void set_elem(Matrix* matrix, int row, int col, double val) {
  if ((row >= matrix[0].row - 1) || (row < 0) || (col >= matrix[0].col) || (col < 0)){
    super_errno = 4;
    return;
  }
  matrix[row * get_cols(matrix) + col + 1].val = val;
}

void print_matrix(Matrix* matrix) {
  int cols = get_cols(matrix);
  int rows = get_rows(matrix);
  for (int i = 0; i < rows; i++) {
    for (int j = 1; j < cols + 1; j++) 
      printf("%.3lf ", matrix[i * get_cols(matrix) + j].val);
    printf("\n");
  }
  printf("\n");
}

int get_rows(Matrix* matrix) {
  return matrix[0].row;
}

int get_cols(Matrix* matrix) { 
  return matrix[0].col;
}

Matrix* matrix_multiplication(Matrix* matrix1, Matrix* matrix2) {
  int rows_1 = get_rows(matrix1);
  int cols_1 = get_cols(matrix1);
  int rows_2 = get_rows(matrix2);
  int cols_2 = get_cols(matrix2);
  
  if (cols_1 != rows_2) {
   super_errno = 3; 
   return NULL;
  }
  
  Matrix* matrix = create_matrix(rows_1, cols_2);
  
  for (int i = 0; i < rows_1; i++)
    for (int j = 1; j < cols_2 + 1; j++)
      for (int ij = 1; ij < cols_1 + 1; ij++)
        matrix[cols_2 * i + j].val += matrix1[i*cols_1+ij].val * matrix2[j + cols_2*(ij-1)].val;

  return matrix;
}

void super_strerror(int errn) {
  switch (errn) {
    case 1:
      printf("Error in fscanf\n");
      break;
    case 2:
      printf("No memory available\n");
      break;
    case 3:  
      printf("Columns in matrix1 != rows in matrix 2\n");
      break;
    case 4:
      printf("Incorrect input of rows or columns\n");
  }
}
