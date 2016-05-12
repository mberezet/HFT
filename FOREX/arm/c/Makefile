ifneq (${KERNELRELEASE},)

# KERNELRELEASE defined: we are being compiled as part of the Kernel
        obj-m := vga_led.o

else

# We are being compiled as a module: use the Kernel build system

	KERNEL_SOURCE := /usr/src/linux
        PWD := $(shell pwd)

default: module my_driver

CFLAGS = -Wall

OBJECTS = my_driver.o #vga_led.o

my_driver: $(OBJECTS)
	cc $(CFLAGS) -o my_driver $(OBJECTS) -lusb-1.0 -lm -pthread

my_driver.o : my_driver.c vga_led.h usbkeyboard.h
#vga_led.o : vga_led.c vga_led.h

module:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules

clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
	${RM} my_driver

socfpga.dtb : socfpga.dtb
	dtc -O dtb -o socfpga.dtb socfpga.dts

endif
