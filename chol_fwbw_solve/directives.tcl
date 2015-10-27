############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
set_directive_unroll "cholesky_basic_my/col_loop"
set_directive_unroll "cholesky_basic_my/diag_loop"
set_directive_unroll "cholesky_basic_my/off_diag_loop"
set_directive_unroll "cholesky_basic_my/sum_loop"
set_directive_unroll "forward_substitution/l_row_loop"
set_directive_unroll "forward_substitution/l_col_loop"
set_directive_unroll "backward_substitution/l_col_loop"
set_directive_unroll "backward_substitution/l_row_loop"
set_directive_inline -recursive "chol_fwbw_solve"
