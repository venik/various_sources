#include <linux/fs.h> 
#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/cdev.h> 
#include <linux/device.h> 

#include "dev.h"

#define EOK 0
#define DEVCOUNT 1
#define MODNAME "hello_mod"
#define DEVNAME "zz0"

MODULE_AUTHOR("Alex Nikiforov");
MODULE_LICENSE("GPL");

static int hopen = 0;
static int major;

static struct class *hello_class;

static int hello_open(struct inode *inode, struct file *filp)
{
	if (hopen) return -EBUSY;

	hopen = 1;
	
	return EOK;
}

static int hello_release(struct inode *inode, struct file *filp)
{
	hopen = 0;
	return EOK;
}

static const struct file_operations hello_fops = {
	.read = hello_read,
	.open = hello_open,
	.release = hello_release,
	.owner = THIS_MODULE,
};

static struct cdev hcdev;

static int __init
hello_init(void)
{
	dev_t		dev;
	int 		ret;
	struct device	*ddev;
	
	printk( "Hello, world!" ); 
	
	/* create device */
	ret = alloc_chrdev_region(&dev, 0, DEVCOUNT, MODNAME);
	if (ret) {
		printk(KERN_ERR"Cannot register hello device");
		goto error;
	}
	major = MAJOR(dev);

	/* character device part */	
	cdev_init(&hcdev, &hello_fops);
	hcdev.owner = THIS_MODULE; 
	hcdev.ops = &hello_fops;   	// FIXME

	ret = cdev_add(&hcdev, dev, DEVCOUNT);
	if (ret) {
		printk(KERN_ERR"Cannot add character device");
		goto error_region;
	}
	
	hello_class = class_create(THIS_MODULE, "hello_class");
	if (IS_ERR(hello_class)) {
		printk(KERN_ERR "Error creating hello class.\n");
		ret = PTR_ERR(hello_class);
		goto error_region;
	}
	
	ddev = device_create(hello_class, NULL, dev, NULL, DEVNAME);
	if (IS_ERR(ddev)) {
		printk(KERN_ERR "Error. Cannot create the character device\n");
		ret = PTR_ERR(ddev);
		goto error_region;
	}

	printk( KERN_INFO "=============== module installed [%d:%d] ptr ddev = 0x%p str = %s\n",
			MAJOR(dev), MINOR(dev), ddev, ddev->kobj.name); 
	return ret;

error_region:
	cdev_del(&hcdev);
	unregister_chrdev_region(MKDEV(major, 0), DEVCOUNT);

error:
	return ret;
}

static void __exit
hello_exit(void)
{
	/* destroy class */
	device_destroy(hello_class, MKDEV(major, 0));
	class_destroy(hello_class);

	/* char */
	cdev_del(&hcdev);
	unregister_chrdev_region(MKDEV(major, 0), DEVCOUNT);
	printk( KERN_INFO "=============== module removed ==================\n" ); 

}

module_init(hello_init);
module_exit(hello_exit);
