#include <linux/module.h>
#include <linux/init.h>

MODULE_AUTHOR("Stupid author");
MODULE_LICENSE("GPL");

int evil(void)
{
	pr_warn("Injected\n");
	return 0;
}

int hello_init(void)
{
	pr_warn("Hello, world!\n"); 
	return 0;
}

void hello_exit(void)
{
	pr_warn("Goodbue, world!\n"); 
}

module_init(hello_init);
module_exit(hello_exit);
