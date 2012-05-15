#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

int evil(void)
{
	pr_warn("%s(): Injected\n", __func__);
	return 0;
}
