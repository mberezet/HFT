main: Bellman.sv Relax.sv Sort.sv Comp.sv Const.svh
	verilator  --unroll-count 9999 -Wall --cc --trace Bellman.sv

.PHONY: clean
clean:
		rm -rf *.o a.out obj_dir
