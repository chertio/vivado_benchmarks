# Vivado_HLS examples and tests

A set of Vivado_HLS projects testing the capabilities of the
tool. Each subdirectory contains a project.

Having only the necessary files in the repository is preferred,
but it's unclear how the GUI/tool manages projects so some
trial and error might be necessary to figure out necessary
and avoid generated files.

Project organization
 - base_* : common and generic code,
 - rig_*  : modules for code setup for test and synthesis
            (e.g. function template instantiations due to the restriction
            on top_function not being a template),
 - bench_*: testbench modules needed due to observed restrictions on
            acceptable code in _Source_ section files.
