#ifndef _MY_DRIVER_H
#define _MY_DRIVER_H

#include <linux/ioctl.h>

typedef struct {
	int w;
	unsigned int src;
  unsigned int dst;
} driver_arg_t;

#endif

