#include <linux/module.h>
#include <linux/init.h>

MODULE_AUTHOR("Stupid author");
MODULE_LICENSE("GPL");

static int init(void)
{
	pr_warn("%s(): Hello, world!\n", __func__); 
	return 0;
}

static void extt(void)
{
	pr_warn("%s(): Goodbue, world!\n", __func__); 
}

module_init(init);
module_exit(extt);
