#include <asm/uaccess.h>

static char *str_hello = "Hello from /dev\n";

size_t hello_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	int 	err = 0;

	size_t	len = strlen(str_hello);

	err = copy_to_user(buf, str_hello, len);
	if (err)
		return -EFAULT;

	return len;
}
