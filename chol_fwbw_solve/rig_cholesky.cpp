#include "base_primitives.h"
#include "rig_cholesky.h"

int chol_decomp(MATRIX_IN_T A[ROWS_COLS_A][ROWS_COLS_A], MATRIX_OUT_T L[ROWS_COLS_A][ROWS_COLS_A]) {
	return prims::chol_decomp_generic(A,L);
}
