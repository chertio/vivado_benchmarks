#include "bench_cholesky.h"
#include "bench_chol_fwbw_solve.h"

int main (void){
	int cholesky_simple_test_success = chol::simple_test();
	int chol_fwbw_solve_simple_test_success = cfbs::simple_test();

	return (cholesky_simple_test_success 			| \
			chol_fwbw_solve_simple_test_success);
}
