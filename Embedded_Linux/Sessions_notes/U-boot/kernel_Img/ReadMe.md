# Explanation of the .config file and its importance
The .config file is a plain text file located in the root of the kernel source directory. It is generated and modified using various kernel configuration tools. It serves as a blueprint for the kernel build process, specifying which components are built into the kernel, and which are built as modules.

### What is the difference between Modules and Drivers? 
- Drivers: A driver is a piece of software that allows the kernel to interact with hardware devices. It Can be compiled directly into the kernel (=y in the .config file) or built as loadable modules (=m in the .config file).
- Modules: A module is a piece of code that can be loaded and unloaded into the kernel at runtime. It provides flexibility by allowing certain functionalities to be included in the kernel only when needed. Such as USB Module

## Structure of the .config File
- =y: The feature is built into the kernel.
- =m: The feature is built as a loadable module.
- =n: The feature is not included.

### You can Initially create it 
Initial Creation: The .config file can be created based on Architecture 
``` bash
make vexpress_defconfig
```

# Steps to build Kernel Img
To build a kernel image, you need to know what your bootloader expects, for example:
 U-boot:Traditionally, U-Boot has required uImage , but newer versions can load a zImage file using the bootz command.

Here is an example of building a zImage file:
``` bash
$ make -j 4 ARCH=arm CROSS_COMPILE=arm-cortex_a8-linux-
gnueabihf- zImage
```
- j 4: Runs 4 jobs in parallel to speed up the build process. This should typically match the number of CPU cores you have.
- ARCH=arm: Specifies the architecture.
- CROSS_COMPILE=arm-cortex_a8-linux-gnueabihf-: Specifies the cross-compiler prefix.

### Tip
A small number of kernels for all ARM devices ,The kernel selects the correct platform by passing device tree through bootloader.

### Problem happens
Issue with uImage for Multi-Platform ARM Kernels

Multi-platform support in ARM kernels allows a single kernel binary to run on different platforms by using the machine number or device tree provided by the bootloader. This feature was introduced in Linux 3.7.
The Problem

    Relocation Address: The uImage header includes a relocation address, which is usually 0x8000 bytes from the start of physical RAM.
    Multi-Platform Conflict: Different platforms might have different starting addresses for physical RAM, causing a conflict because the uImage format can only have one relocation address.

### Solution

You can still create a uImage from a multi-platform build, but you need to specify the LOADADDR (load address) for the specific SoC (System on Chip) you are targeting.
To find the load address (LOADADDR) for your specific SoC:

    Look in the Makefile located at arch/$ARCH/mach-[your SoC]/Makefile.boot.
    Find the zreladdr-y value.

### Build Artifacts:
A kernel build generates two files in the top-level directory:
- VmLinux--> The kernel as elf binary which used for debugging cuz it contains debbuging symbols 
- system.map--> Contains symbol table in human readable form.

# Building a kernel for QEMU
- First Thing you need to Clone Linux github repo and change direction to Linux
- Second step is to Set CROSS_COMPILE = arm-unknown-linux-gnueabi , ARCH=arm
- 3rd: Build Kernel Image, Modules, Device tree Blobs
### Here Explaination of 3rd Step: 
- compile the kernel to create the zImage, which is the compressed kernel image suitable for booting on the ARM Versatile PB platform
- Kernel modules are loadable parts of the kernel that can be loaded and unloaded dynamically. This step compiles any kernel modules specified in your configuration
- Device Tree Blobs (DTBs) describe the hardware layout to the kernel. The kernel uses this information to initialize and manage hardware devices correctly
### By These steps u must have the Kernel Image.

