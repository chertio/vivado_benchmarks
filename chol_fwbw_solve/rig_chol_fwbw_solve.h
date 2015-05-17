#ifndef RIG_CHOL_FWBW_SOLVE_H
#define RIG_CHOL_FWBW_SOLVE_H

#include "base_primitives.h"

namespace cfbs {

const unsigned ROWS_COLS_A = 6;

typedef float MATRIX_IN_T;
typedef float MATRIX_OUT_T;
typedef float VECTOR_RHS_T;

}

int chol_fwbw_solve(const cfbs::MATRIX_IN_T A[cfbs::ROWS_COLS_A][cfbs::ROWS_COLS_A],
					const cfbs::VECTOR_RHS_T b[cfbs::ROWS_COLS_A][1],
					cfbs::VECTOR_RHS_T x[cfbs::ROWS_COLS_A][1]);

#endif
