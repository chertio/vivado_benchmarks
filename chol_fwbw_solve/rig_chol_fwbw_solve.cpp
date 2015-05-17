#include "base_primitives.h"
#include "rig_chol_fwbw_solve.h"

int chol_fwbw_solve(cfbs::MATRIX_IN_T A[cfbs::ROWS_COLS_A][cfbs::ROWS_COLS_A],
					cfbs::VECTOR_RHS_T b[cfbs::ROWS_COLS_A][1],
					cfbs::VECTOR_RHS_T x[cfbs::ROWS_COLS_A][1]) {
	return prims::chol_fwbw_solve_generic<cfbs::MATRIX_IN_T, cfbs::MATRIX_OUT_T, cfbs::VECTOR_RHS_T, cfbs::ROWS_COLS_A>(A, b, x);
}
