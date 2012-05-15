#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

extern int init(void);

int evil(void)
{
	pr_warn("%s(): Injected\n", __func__);
	return init();
}
