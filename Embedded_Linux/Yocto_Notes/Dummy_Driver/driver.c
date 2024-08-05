#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>

MODULE_AUTHOR("MOSTAFA");
MODULE_DESCRIPTION("A dummy Driver");
MODULE_LICENSE("GPL");

static int mykernel_init(void){
    /* For user spcace printing */
    // printf("Hello from dummy User Space\n");

    /* For Kernel Space */
    printk("Hello from dummy Kernel Space\n");

    return 0;

}

static void mykernel_exit(void){
    printk("bye bye from kernel Space\n");
}
module_init(mykernel_init);
module_exit(mykernel_exit);