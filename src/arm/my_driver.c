/*
 * Device driver for the VGA driver Emulator
 *
 * Graham Gobieski and Kevin Kwan
 * gsg2120, kjk2150
 *
 * References:
 * http://www.linuxforu.com/tag/linux-device-drivers/
 */

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/io.h>

#include "my_driver.h"
#include "hps.h"
#include "hps_0.h"

/* Memory region visible through the lightweight HPS-FPGA bridge */
#define HW_REGS_BASE ALT_LWFPGASLVS_OFST
#define HW_REGS_SIZE 0x200000
#define HW_REGS_MASK (HW_REGS_SIZE - 1)
#define PRED_WIDTH 7

static void __iomem *registers; /* Base of mapped memory */
static dev_t firstdev;
static struct class *cl;
static struct cdev c_dev;

static void *driver_registers; /* Start of registers for drivers */

/* Low-level write routine: digit assumed to be in range; remember the state */
static void write_edge(int w, unsigned int src, unsigned int dst) {
  unsigned int combo_vert = (src << PRED_WIDTH) | dst;
	iowrite32(combo_vert, driver_registers);
  iowrite32(w, driver_registers + sizeof(int));
}

static int my_open(struct inode *i, struct file *f) {
  return 0;
}

static int my_close(struct inode *i, struct file *f) {
  return 0;
}

/* Handle ioctls(): write to the display registers or read our state */
static long my_ioctl(struct file *f, unsigned int cmd, unsigned long arg) {
  driver_arg_t da;

  if (copy_from_user(&da, (driver_arg_t *) arg, sizeof(driver_arg_t)))
    return -EACCES;

  write_edge(da.w, da.src, da.dst);
  return 0;
}

static struct file_operations my_fops = {
  .owner = THIS_MODULE,
  .open = my_open,
  .release = my_close,
  .unlocked_ioctl = my_ioctl
};

/* Initialize the driver: map the hardware registers, register the
 * device and our operations, and display a welcome message */
static int __init my_driver_init(void) {

  printk(KERN_INFO "Forex Driver: init\n");

  if ( (registers = ioremap(HW_REGS_BASE, HW_REGS_SIZE)) == NULL ) {
    printk(KERN_ERR "driver: Mapping hardware registers faidriver\n");
    return -1;
  }

  driver_registers = registers +
    ((unsigned long) MY_DRIVER_BASE & (unsigned long) HW_REGS_MASK);

  if (alloc_chrdev_region(&firstdev, 0, 1, "forex_driver") < 0) goto unmap;
  if ((cl = class_create(THIS_MODULE, "chardrv")) == NULL) goto unregister;
  if (device_create(cl, NULL, firstdev, NULL, "forex_driver") == NULL) goto del_class;
  cdev_init(&c_dev, &my_fops);
  if (cdev_add(&c_dev, firstdev, 1) == -1) goto del_device;

  return 0;

  /* Clean up if something went wrong */
  unmap:      iounmap(registers);
  del_device: device_destroy(cl, firstdev);
  del_class:  class_destroy(cl);
  unregister: unregister_chrdev_region(firstdev, 1);
  return -1;
}

/* Disable the driver; undo the effects of the initialization routine */
static void __exit my_driver_exit(void) {
  printk(KERN_INFO "forex driver: exit\n");

  cdev_del(&c_dev);
  device_destroy(cl, firstdev);
  class_destroy(cl);
  unregister_chrdev_region(firstdev, 1);
  iounmap(registers);
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Graham Gobieski gsg2120, Kevin Kwan kjk2150, etc.");
MODULE_DESCRIPTION("FOREX Driver");

