#include <linux/module.h>
#include <linux/init.h>

MODULE_AUTHOR("Alex Nikiforov");
MODULE_LICENSE("GPL");

static int __init
hello_init(void)
{
	printk( "Hello, world!" ); 
	return 0;
}

static void __exit
hello_exit(void)
{
	printk( "Goodbue, world!" ); 
}

module_init(hello_init);
module_exit(hello_exit);
