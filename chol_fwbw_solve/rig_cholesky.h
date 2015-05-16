#include "base_primitives.h"

#ifndef CHOLESKY_RIG_H
#define CHOLESKY_RIG_H

const unsigned ROWS_COLS_A = 6;

typedef float MATRIX_IN_T;
typedef float MATRIX_OUT_T;
//typedef float VECTOR_RHS_T;

int chol_decomp(MATRIX_IN_T A[ROWS_COLS_A][ROWS_COLS_A], MATRIX_OUT_T L[ROWS_COLS_A][ROWS_COLS_A]);

#endif
