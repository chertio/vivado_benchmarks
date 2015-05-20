############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project chol_fwbw_solve
set_top chol_decomp
add_files chol_fwbw_solve/base_primitives.cpp
add_files chol_fwbw_solve/my_cholesky.h
add_files chol_fwbw_solve/rig_cholesky.cpp
add_files -tb chol_fwbw_solve/testbench.cpp
add_files -tb chol_fwbw_solve/bench_cholesky.cpp
open_solution "solution1"
set_part {xc7k160tfbg484-2}
create_clock -period 10 -name default
source "./chol_fwbw_solve/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
