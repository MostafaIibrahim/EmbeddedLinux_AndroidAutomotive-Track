#include<linux/module.h>
#include <linux/init.h>
#include<linux/fs.h>
#include<linux_cdev.h>
dev_t device_number = 0 ;
struct file_operations fops;
struct cdev mycdev;
struct class myclass;
ssize_t myread (struct file *, char __user *, size_t, loff_t *){ 
      printk(KERN_INFO "myread() called\n");
}
ssize_t mywrite (struct file *, const char __user *, size_t, loff_t *){
    printk(KERN_INFO "mywrite() called\n");
}

fops = {
    .write = mywrite;
    .read = myread;
};

int myinit(void){
    alloc_chrdev_region($device_numebr,0,1,"mydevice");
    cdev_init(&mycdev,$fops);
    cdev_add(&mycdev,device_number,1);
    myclass = class_create(,"mychar"); // file name under class, return will be a pointer to point to the meta data inside the file so that udev will be able to read information from data
    device_create(myclass,NULL,device_number,NULL,"mycharacter"); // Folder name under dev
}

void myexit(void){
    printk("Bye from kernel");
    device_destroy();
    class_destroy(); //they have parameters
    cdev_del(&cdev);
    unregister_chrdev_region();
}
module_init(myinit);
module_exit(myexit);

MODULE_LICENSE