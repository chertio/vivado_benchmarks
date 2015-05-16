#include "base_primitives.h"
#include "rig_cholesky.h"
#include "bench_cholesky.h"
#include "hls/linear_algebra/utils/x_hls_matrix_utils.h"
#include "hls/linear_algebra/utils/x_hls_matrix_tb_utils.h"
#include "hls_linear_algebra.h"

int cholesky_simple_test() {
	
	int cholesky_success = 0;
	
    MATRIX_IN_T A [ROWS_COLS_A][ROWS_COLS_A];
    MATRIX_OUT_T L [ROWS_COLS_A][ROWS_COLS_A];
    MATRIX_IN_T Ar[ROWS_COLS_A][ROWS_COLS_A];

    A[0][0] = 115.0; A[0][1] =  -7.0; A[0][2] = -12.0; A[0][3] = -14.0; A[0][4] =  26.0; A[0][5] =   0.0;
    A[1][0] =  -7.0; A[1][1] = 120.0; A[1][2] =  17.0; A[1][3] = -23.0; A[1][4] =  -6.0; A[1][5] =  -3.0;
    A[2][0] = -12.0; A[2][1] =  17.0; A[2][2] = 124.0; A[2][3] =  -2.0; A[2][4] = -12.0; A[2][5] =   0.0;
    A[3][0] = -14.0; A[3][1] = -23.0; A[3][2] =  -2.0; A[3][3] = 108.0; A[3][4] =  -5.0; A[3][5] =  -6.0;
    A[4][0] =  26.0; A[4][1] =  -6.0; A[4][2] = -12.0; A[4][3] =  -5.0; A[4][4] = 127.0; A[4][5] = -10.0;
    A[5][0] =   0.0; A[5][1] =  -3.0; A[5][2] =   0.0; A[5][3] =  -6.0; A[5][4] = -10.0; A[5][5] = 119.0;

    cholesky_success = chol_decomp(A,L);

    // Now re-create A: Ar = L * L'
    hls::matrix_multiply<hls::NoTranspose,hls::Transpose,ROWS_COLS_A,ROWS_COLS_A,ROWS_COLS_A,ROWS_COLS_A,ROWS_COLS_A,ROWS_COLS_A,float,float>(L, L, Ar);

    printf("A = \n");
    hls::print_matrix<ROWS_COLS_A, ROWS_COLS_A, float, hls::NoTranspose>(A, "   ");

    printf("L = \n");
    hls::print_matrix<ROWS_COLS_A, ROWS_COLS_A, float, hls::NoTranspose>(L, "   ");

    printf("A reconstructed = \n");
    hls::print_matrix<ROWS_COLS_A, ROWS_COLS_A, float, hls::NoTranspose>(Ar, "   ");

    // Generate error ratio and compare against threshold value
    // - LAPACK error measurement method
    // - Threshold taken from LAPACK test functions
    int fail = 0;
    if ( difference_ratio<ROWS_COLS_A, ROWS_COLS_A>(Ar,A) > 30.0 ) {
      fail = 1;
    }
    
    return (cholesky_success|fail);
}
