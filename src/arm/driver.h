//Graham Gobieski and Kevin Kwan
//gsg2120, kjk2150
#ifndef _DRIVER_H
#define _DRIVER_H

#include <linux/ioctl.h>

typedef struct {
	int w;
	unsigned int src;
  unsigned int dst;
} driver_arg_t;

#endif
