main: Bellman.sv Const.vh Container.sv CycleDetect.sv AdjMat.sv Vertmat.sv FOREX.sv
	verilator  --unroll-count 9999 -Wno-lint --cc --trace FOREX.sv

test: Bellman.sv Const.vh Container.sv CycleDetect.sv AdjMat.sv Vertmat.sv FOREX.sv testbench/Bellman_TB.cpp
	verilator  --unroll-count 9999 -Wno-lint --cc --trace FOREX.sv --exe testbench/Bellman_TB.cpp
	make -j -C obj_dir/ -f VFOREX.mk VFOREX
	./obj_dir/VFOREX

.PHONY: clean
clean:
		rm -rf *.o a.out obj_dir
