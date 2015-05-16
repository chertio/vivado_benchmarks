#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include "hls_linear_algebra.h"

const unsigned LOWER_TRIANGULAR = true;

namespace prims {

template<typename T_M,
		 typename T_V,
		 int RCA>
int forward_substitution(T_M L[RCA][RCA],
						 T_V b[RCA],
						 T_V x[RCA]) {

	// with assumption of REAL-TIME execution it's the task for
	// the algorithm designer to ensure correct runtime for all
	// inputs

	l_row_loop : for (int r=0; r<RCA; r++) {
		x[r] = b[r];
		l_col_loop : for (int c=0; c<r; c++) {
			x[r] -= L[r][c]*x[r];
		}
		x[r] /= L[r][r];
	}

	return 1;
}

template<typename T_M,
		 typename T_V,
		 int RCA>
int backward_substitution(T_M L[RCA][RCA],
						  T_V b[RCA],
						  T_V x[RCA]) {
	// expects LOWER TRIANGULAR matrix and
	// indexes into it to obtain its transpose
	l_col_loop : for (int c=RCA-1; c>-1; c--) {
		x[c] = b[c];
		l_row_loop : for (int r=RCA-1; r>c; r--) {
			x[c] -= L[r][c]*x[r];
		}
		x[c] /= L[c][c];
	}
}

template<typename T_IN,
		 typename T_OUT,
		 int RCA>
	int chol_decomp_generic(T_IN  A[RCA][RCA],
                				T_OUT L[RCA][RCA]){

  T_IN  a_i[RCA][RCA];
  T_OUT l_i[RCA][RCA];

  // Copy input data to local memory
  a_row_loop : for (int r=0;r<RCA;r++) {
    a_col_loop : for (int c=0;c<RCA;c++) {
      a_i[r][c] = A[r][c];
    }
  }

  // Call Cholesky
  if ( hls::cholesky<LOWER_TRIANGULAR, RCA, T_IN, T_OUT>(a_i, l_i) ) {
    // Error - matrix was not symmetric positive definite
    return 1;
  }

  // Copy local memory contents to output
  l_row_loop : for (int r=0;r<RCA;r++) {
    l_col_loop : for (int c=0;c<RCA;c++) {
      L[r][c] = l_i[r][c];
    }
  }

  return 0;
}

}
#endif
