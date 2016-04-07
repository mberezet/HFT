main: Bellman.sv Const.svh Container.sv CycleDetect.sv
	verilator  --unroll-count 9999 -Wall --cc --trace Bellman.sv

test: Bellman.sv Const.svh Container.sv CycleDetect.sv testbench/Bellman_TB.cpp
	verilator  --unroll-count 9999 -Wall --cc --trace Container.sv --exe testbench/Bellman_TB.cpp
	make -j -C obj_dir/ -f VContainer.mk VContainer
	./obj_dir/VContainer

.PHONY: clean
clean:
		rm -rf *.o a.out obj_dir
