#ifndef _MY_DRIVER_H
#define _MY_DRIVER_H

#include <linux/ioctl.h>

typedef struct {
	int w;
	unsigned int src;
  unsigned int dst;
} driver_arg_t;

#define MY_DRIVER_MAGIC 'q'
#define MY_DRIVER_WRITE _IOW(MY_DRIVER_MAGIC, 1, driver_arg_t *)
#endif

