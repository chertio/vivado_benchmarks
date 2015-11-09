#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include "hls_linear_algebra.h"
#include "my_cholesky.h"

const unsigned LOWER_TRIANGULAR = true;

namespace prims {

template<typename T_M,
		 typename T_V,
		 int RCA>
int forward_substitution(T_M L[RCA][RCA],
						 T_V b[RCA][1],
						 T_V x[RCA][1]) {

	// with assumption of REAL-TIME execution it's the task for
	// the algorithm designer to ensure correct runtime for all
	// inputs

	l_row_loop : for (int r=0; r<RCA; r++) {
		x[r][0] = b[r][0];
		l_col_loop : for (int c=0; c<r; c++) {
			x[r][0] -= L[r][c]*x[c][0];
		}
		x[r][0] /= L[r][r];
	}

	return 0;
}

template<typename T_M,
		 typename T_V,
		 int RCA>
int backward_substitution(T_M L[RCA][RCA],
						  T_V b[RCA][1],
						  T_V x[RCA][1]) {
	// expects LOWER TRIANGULAR matrix and
	// indexes into it to obtain its transpose
	l_col_loop : for (int c=RCA-1; c>-1; c--) {
		x[c][0] = b[c][0];
		l_row_loop : for (int r=RCA-1; r>c; r--) {
			x[c][0] -= L[r][c]*x[r][0];
		}
		x[c][0] /= L[c][c];
	}
	return 0;
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
  if ( my::cholesky<LOWER_TRIANGULAR, RCA, T_IN, T_OUT>(a_i, l_i) ) {
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

template<typename T_IN,
		 typename T_OUT,
		 int RCA>
	int chol_decomp_simple(T_IN A[RCA][RCA],
						   T_OUT L[RCA][RCA]){
	l_row_loop : for (int r=0; r<RCA; r++) {

		// calculate the rest of the row
		l_col_loop: for (int c=0; c<r; c++) {
			L[r][c] = A[r][c];
			l_rc_loop: for (int k=0; k<c; k++) {
				L[r][c] -= L[r][k]*L[c][k];
			}
			L[r][c] /= L[c][c];
		}

		// calculate the diagonal element
		L[r][r] = A[r][r];
		l_rr_loop: for (int k=0; k<r; k++) {
			L[r][r] -= L[r][k]*L[r][k];
		}
		L[r][r] = sqrt(L[r][r]);
	}
	return 0;
}

template<typename T_IN,
		 typename T_OUT,
		 typename T_RHS,
		 int RCA>
int chol_fwbw_solve_generic(T_IN A[RCA][RCA],
					T_RHS b[RCA][1],
					T_RHS x[RCA][1]) {
	  T_IN  a_i[RCA][RCA];
	  T_OUT l_i[RCA][RCA];
	  T_RHS b_i[RCA][1];

	  T_RHS x_intermediate[RCA][1];	// after the fw subst
	  //T_RHS x_final[RCA][1];		// after the bw subst

	  // Copy input data to local memory
	  /*a_row_loop : for (int r=0;r<RCA;r++) {
	    a_col_loop : for (int c=0;c<RCA;c++) {
	      a_i[r][c] = A[r][c];
	    }
	  }*/

	  /*b_in_row_loop : for (int r=0;r<RCA;r++)
		  b_i[r][0] = b[r][0];*/

	  // solve
	  //my::cholesky<LOWER_TRIANGULAR, RCA, T_IN, T_OUT>(A, l_i);
	  chol_decomp_simple(A, l_i);
	  forward_substitution(l_i, b, x_intermediate);
	  backward_substitution(l_i, x_intermediate, x);

	  // how does this get synthesized??
	  // is it necessary to have it?
	  //if (  ) {
	    // Error - matrix was not symmetric positive definite
	    //return 1;
	  //}

	  // Copy local memory contents to output
	  /*x_final_row_loop : for (int r=0;r<RCA;r++)
		  x[r][0] = x_final[r][0];*/

	  return 0;
}



}
#endif
