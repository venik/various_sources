#include <linux/module.h>
#include <linux/init.h>

#include <linux/fs.h>
#include <linux/proc_fs.h> 
#include <linux/uaccess.h> 


#include <linux/netfilter.h>
#include <linux/netfilter/xt_owner.h>
//#include <linux/netfilter_ipv4/x_tables.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter/xt_socket.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>

static char *name_node = "my_proc_entry";
static char *string_in_kernel_space = "Kernel space";

static struct proc_dir_entry *pde;

ssize_t my_read(struct file *fd, char __user *u_buf, size_t size, loff_t *offt)
{
	static int odd = 0;
	printk( KERN_INFO "read: %d\n", size );
	if( 0 == odd ) {
		int res = copy_to_user( (void*)u_buf, string_in_kernel_space, strlen(string_in_kernel_space));
		odd = 1;
		put_user('\n', u_buf + strlen(string_in_kernel_space)); 
		res = strlen(string_in_kernel_space) + 1;
		printk( KERN_INFO "return bytes :  %d\n", res );
		return res;
	}
	odd = 0;
	printk( KERN_INFO "EOF\n" );

	return 0;
};

ssize_t my_write(struct file *fd, const char __user *u_buf, size_t size, loff_t *offt)
{
	return -EIO;
};

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = &my_read,
	.write = &my_write,
};

static bool my_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	return false;
}

static struct xt_match my_mt_reg __read_mostly = {
	/*
	 * This module masquerades as the "owner" module so that iptables
	 * tools can deal with it.
	 */
	.name       = "owner",
	.revision   = 1,
	.family     = NFPROTO_UNSPEC,
	.match      = my_mt,
	.matchsize  = sizeof(struct xt_owner_match_info),
	.me         = THIS_MODULE,
};

static int __init
hello_init(void)
{
	int	ret = 0;

	/* make proc */
	pde = create_proc_entry(name_node, S_IFREG | S_IRUGO | S_IWUGO, NULL);
	if(!pde) {
		ret = ENOMEM;
		printk( KERN_ERR "can't create /proc/%s\n", name_node ); 
	      	goto err_node; 
	}

	pde->proc_fops = &fops;

	/* init xt */
	xt_register_match(&my_mt_reg);

	printk( "[%s] Succesully init\n", name_node); 

err_node:
	return ret;
}

static void __exit
hello_exit(void)
{
	remove_proc_entry(name_node, NULL);
	xt_unregister_match(&my_mt_reg);
	
	printk( "[%s] Succesully removed\n", name_node); 
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Alex Nikiforov");
MODULE_LICENSE("GPL");
