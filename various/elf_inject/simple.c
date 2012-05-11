#include <linux/module.h>
#include <linux/init.h>

MODULE_AUTHOR("Stupid author");
MODULE_LICENSE("GPL");

int evil(void)
{
	pr_warn("%s(): Injected\n", __func__);
	return 0;
}

int init(void)
{
	pr_warn("%s(): Hello, world!\n", __func__); 
	return 0;
}

void extt(void)
{
	pr_warn("%s(): Goodbue, world!\n", __func__); 
}

module_init(init);
module_exit(extt);
