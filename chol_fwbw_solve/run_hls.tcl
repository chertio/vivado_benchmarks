############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project chol_fwbw_solve
set_top chol_fwbw_solve
add_files base_primitives.cpp
add_files rig_chol_fwbw_solve.cpp
add_files rig_cholesky.cpp
add_files -tb bench_chol_fwbw_solve.cpp
add_files -tb bench_cholesky.cpp
add_files -tb testbench.cpp
open_solution "solution1"
set_part {xc7vx690tffg1761-2}
create_clock -period 10 -name default
source "directives.tcl"
csim_design -clean
csynth_design
cosim_design
#export_design -format ip_catalog
