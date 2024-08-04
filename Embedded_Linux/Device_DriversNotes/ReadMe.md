# The role of device drivers

- One of Kernal Function is to encapsulate -Hide Complexities- the many hardware interfaces of a computer system and present them in a consistent manner to user space programs. Which means that user applications can interact with hardware through a standardized set of functions and commands, without needing to know the details of the specific hardware they are working with.

- Device driver is a piece of code that mediates between the kernel above and the hardware below.

- A device driver may be written to control physical devices such as a UART or an MMC controller, or it may represent a virtual device such as the null device ( /dev/null ) or a ramdisk. One driver may control multiple devices of the same kind.

- There are main three types of Device drivers:
    1. Character --> This is unbuffered I/O -such as serial port- data is sent one byte at a time over a communication channel which means data transferred directly without any buffering and It is the first choice when implementing custom device drivers..
    2. Block --> This is for mass storage items
    3. Network --> This is like Block but for transmitting and receiving networks 

# Let's talk about Character Device driver and how it works

- Character devices are identified in the user space by a special file called (a device node). This Filename is mapped to Device driver using Major and Minor number associated with it.
The major number --> This identifies the specific device driver that should handle the device file. Essentially, it tells the kernel which driver to use for operations on this device.
The minor number --> Tells device driver which interface is being accessed 

- the device nodes can be created in several ways:
    - devtmpfs : The device node is created when the device driver registers a new device interface using a base name supplied by the driver ( ttyAMA ) and an instance number.
    - udev or mdev (without devtmpfs ): Essentially the same as with devtmpfs , except that a user space daemon program has to extract the device name from sysfs and create the node. 
    - mknod : If you are using static device nodes, they are created manually using mknod

### Example to Clarify it
- Let's use a practical example of a simple character device driver that handles multiple devices. Suppose you have a driver that manages two serial ports, /dev/ttyS0 and /dev/ttyS1.

    - Major Number:
        Both /dev/ttyS0 and /dev/ttyS1 use the same major number, say 4. This tells the kernel that both these device files are handled by the same device driver (the serial port driver).

    - Minor Number:
        The minor number differentiates between /dev/ttyS0 and /dev/ttyS1. For example:
            /dev/ttyS0 might have a minor number of 64.
            /dev/ttyS1 might have a minor number of 65.
### How It Works
- When an application performs I/O operations on /dev/ttyS0:
    - The kernel uses the major number 4 to find the corresponding driver.
    
    - It then passes the minor number 64 to the driver, indicating that operations are targeted at the first serial port.

- the kernel checks whether the major and minor numbers fall into a range registered by a character device driver. If so, it passes the call to the driver; otherwise, the open call fails. The device driver can extract the minor number to find out which hardware interface to use.

# The Anatomy of device driver 
- Let's Create a device driver called dummy--> This creates 4 devices that can be accessed by /dev/dummy0 to /dev/dummy3

1. Include Headers 
``` C
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/device.h>
```
2. We will define Major, Minor Numbers which was explained before, and device Name
``` C
#define DEVICE_NAME "dummy"
#define MAJOR_NUM 42
#define NUM_DEVICES 4
```
- static struct class *dummy_class; --> we will find why was it created 
3. We will define four dummy function for charcter device driver interface --> dummy_open(), dummy_release(), dummy_read(), dummy_write().

4. We need to initialize a file_operations structure and define the dummy_init() and dummy_exit() functions, which are called when the driver is loaded and unloaded cuz it's dynamic module.
 1. Create file_operation called dummy_fops which is an instance of type struct file_operations that has owner of the file and assign all function interfaces 
 ``` c
 struct file_operations dummy_fops = {
.owner = THIS_MODULE,
.open = dummy_open,
.release = dummy_release,
.read = dummy_read,
.write = dummy_write,
};
``` 
 2. Define init function 
 ``` c
 int __init dummy_init(void) {
int ret;
int i;
printk("Dummy loaded\n");
ret = register_chrdev(MAJOR_NUM, DEVICE_NAME, &dummy_fops);
if (ret != 0) /*--> So if ret = 1 it means it was created before? */
    return ret;
dummy_class = class_create(THIS_MODULE, DEVICE_NAME);
for (i = 0; i < NUM_DEVICES; i++) {
    device_create(dummy_class, NULL, MKDEV(MAJOR_NUM, i), NULL, "dummy%d", i);
    }
return 0;}
```
- Function Description: it will be placed at section __init which will be in RAM 
    - When the module is loaded, the dummy_init() function is called. You can see the point at which it becomes a character device when is makes the call to register_chrdev passing a pointer to struct file_operations , which contains pointers to the four functions that the driver implements.
    - So register tell the kernel about the Major number of the device but it doesn't say anything about the class of drvier, and so it will not create an entry in /sys/class, and without it -/sys/class- the device manager cannot create device node.
    - So we needed for loop to create number of required devices. The result is that the /sys/class/dummy directory is created when the driver is initialized, containing subdirectories dummy0 to dummy3 .
 3. define exit function
 ``` c
 void __exit dummy_exit(void) {
int i;
for (i = 0; i < NUM_DEVICES; i++) {
device_destroy(dummy_class, MKDEV(MAJOR_NUM, i));
}
class_destroy(dummy_class);
unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
printk("Dummy unloaded\n");
}
```
 - Function Description: The dummy_exit() function has to release the resources claimed by dummy_init() , which here means freeing up the device class and major number.

5. At the end of the code, the macros called module_init and module_exit specify the functions to be called when the module is loaded and unloaded:
``` c
module_init(dummy_init);
module_exit(dummy_exit);
```
6. The closing three macros named MODULE_* add some basic information about the module:
``` c
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chris Simmonds");
MODULE_DESCRIPTION("A dummy driver");
```

- This illustrate how the linkage between a device node and driver code works; how the device class is created, allowing a device manager to create device nodes automatically when the driver is loaded; and how the data is moved between the user and kernel spaces.

# Compiling Kernel Module 
- At this point we have some driver code that I want to compile and test on the target.
- We can ---> 1. Copy it to kernel source tree and modify makefile
              2. or Compile it as a module out of tree

- If we wantt it out of tree so we need to create a simple make file
``` makefile
LINUXDIR := $(HOME)/MELP/build/linux
obj-m := dummy.o
all: 
    make ARCH=arm CROSS_COMPILE=arm-cortex_a8-linux-gnueabihf- -c $(LINUXDIR) M=$(shell pwd)
clean:
    make -C $(LINUXDIR) M=$(shell pwd) clean
```
LINUXDIR --> Directory of target device that will run module on.
- Obj-m := dummy.o --> This code will invoke kernel build rule to take source file,dummy.c,and create kernel module,dummy.ko

### The Module will only load on the kernel it was compiled with.

- For building a driver in Kernel source tree:- 
    1. Choose a directory appropriate to the type of driver you have. The driver is a basic character device, so I would put dummy.c in --> drivers/char
    2. Edit makefile and add 
        ```makefile
        obj-m += dummy.o
        ```
        To build driver as module
        or add
        ```makefile
        obj-y += dummy.o
        ```
        To build it as builtin.

# Loading Kernel Module
- To Talk with kernel during runtime to insert module or remove it we use system calls:-
1. insmod --> Insert module 
2. rmmod --> Remove module
3. modprobe --> mix between insmod and rmmod, We give option to work as insmod or rmmod
- We use sodo with it.

### Device Driver has a job of handling devices and representing them to user space.