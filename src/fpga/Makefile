main: Bellman.sv Relax.sv Sort.sv Comp.sv Const.svh
	verilator  --unroll-count 9999 -Wall --cc --trace Bellman.sv

test: Bellman.sv Relax.sv Sort.sv Comp.sv Const.svh testbench/Bellman_TB.cpp
	verilator  --unroll-count 9999 -Wall --cc --trace Bellman.sv --exe testbench/Bellman_TB.cpp
	make -j -C obj_dir/ -f VBellman.mk VBellman
	./obj_dir/VBellman 

.PHONY: clean
clean:
		rm -rf *.o a.out obj_dir
