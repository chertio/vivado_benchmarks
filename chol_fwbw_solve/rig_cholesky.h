#include "base_primitives.h"

#ifndef CHOLESKY_RIG_H
#define CHOLESKY_RIG_H

namespace chol {

const unsigned ROWS_COLS_A = 6;

typedef float MATRIX_IN_T;
typedef float MATRIX_OUT_T;
//typedef float VECTOR_RHS_T;

}

int chol_decomp(chol::MATRIX_IN_T A[chol::ROWS_COLS_A][chol::ROWS_COLS_A], chol::MATRIX_OUT_T L[chol::ROWS_COLS_A][chol::ROWS_COLS_A]);


#endif
