#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

extern int __init init(void);

int __init evil(void)
{
	pr_warn("%s: %s(): Injected\n", __FILE__, __func__);
	return init();
}
