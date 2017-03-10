#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Matrix {
  int row;
  int col;
  double val;
} Matrix;

int super_errno;
Matrix* create_matrix_from_file(FILE* file);
Matrix* create_matrix(int row, int col);
void free_matrix(Matrix* matrix);
double get_elem(Matrix* matrix, int row, int col);
void set_elem(Matrix* matrix, int row, int col, double val);
int get_rows(Matrix* matrix);
int get_cols(Matrix* matrix);
Matrix* matrix_multiplication(Matrix* matrix1, Matrix* matrix2);
void print_matrix(Matrix* matrix);
void super_strerror(int errn);
#endif //_MATRIX_H_
