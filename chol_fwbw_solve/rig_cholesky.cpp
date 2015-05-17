#include "base_primitives.h"
#include "rig_cholesky.h"

int chol_decomp(chol::MATRIX_IN_T A[chol::ROWS_COLS_A][chol::ROWS_COLS_A], chol::MATRIX_OUT_T L[chol::ROWS_COLS_A][chol::ROWS_COLS_A]) {
	return prims::chol_decomp_generic(A,L);
}
