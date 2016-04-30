
#include <stdio.h>
#include "my_driver.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
  printf("%d\n", MY_DRIVER_WRITE);
  printf("%d\n", sizeof(driver_arg_t*));
  return 0;
}

