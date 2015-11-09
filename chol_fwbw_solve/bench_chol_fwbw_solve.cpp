#include "base_primitives.h"
#include "rig_chol_fwbw_solve.h"
#include "bench_chol_fwbw_solve.h"
#include "hls/linear_algebra/utils/x_hls_matrix_utils.h"
#include "hls/linear_algebra/utils/x_hls_matrix_tb_utils.h"
#include "hls_linear_algebra.h"

namespace cfbs {

int simple_test() {
int solve_success = 0;

MATRIX_IN_T A [ROWS_COLS_A][ROWS_COLS_A];
VECTOR_RHS_T b[ROWS_COLS_A][1];
VECTOR_RHS_T m[ROWS_COLS_A][1];
VECTOR_RHS_T br[ROWS_COLS_A][1];

A[0][0] = 115.0; A[0][1] =  -7.0; A[0][2] = -12.0; A[0][3] = -14.0; A[0][4] =  26.0; A[0][5] =   0.0;
A[1][0] =  -7.0; A[1][1] = 120.0; A[1][2] =  17.0; A[1][3] = -23.0; A[1][4] =  -6.0; A[1][5] =  -3.0;
A[2][0] = -12.0; A[2][1] =  17.0; A[2][2] = 124.0; A[2][3] =  -2.0; A[2][4] = -12.0; A[2][5] =   0.0;
A[3][0] = -14.0; A[3][1] = -23.0; A[3][2] =  -2.0; A[3][3] = 108.0; A[3][4] =  -5.0; A[3][5] =  -6.0;
A[4][0] =  26.0; A[4][1] =  -6.0; A[4][2] = -12.0; A[4][3] =  -5.0; A[4][4] = 127.0; A[4][5] = -10.0;
A[5][0] =   0.0; A[5][1] =  -3.0; A[5][2] =   0.0; A[5][3] =  -6.0; A[5][4] = -10.0; A[5][5] = 119.0;

b[0][0] = 1.0;
b[1][0] = 2.0;
b[2][0] = 100.0;
b[3][0] = -25.0;
b[4][0] = 77.0;
b[5][0] = -17.0;

// Get m = A*b
hls::matrix_multiply<hls::NoTranspose,hls::NoTranspose,ROWS_COLS_A,ROWS_COLS_A,ROWS_COLS_A,1,ROWS_COLS_A,1,float,float>(A, b, m);

solve_success = chol_fwbw_solve(A,m,br);

printf("b = \n");
hls::print_matrix<ROWS_COLS_A, 1, float, hls::NoTranspose>(b, "   ");

printf("b reconstructed = \n");
hls::print_matrix<ROWS_COLS_A, 1, float, hls::NoTranspose>(br, "   ");

// Figure out how to test
// See a numerical linear algebra book for proper test condition
int fail = 0;

return (solve_success|fail);
}

}
