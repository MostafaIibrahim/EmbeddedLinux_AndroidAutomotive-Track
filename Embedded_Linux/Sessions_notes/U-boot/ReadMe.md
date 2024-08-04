# Das Uinversal Boot (U-boot)
U-Boot (Universal Boot Loader) is an open-source primary bootloader used in embedded devices to initialize and load the operating system kernel.It is highly versatile and can be adapted to various hardware architectures.
It is considered a secondary bootloader in the boot sequence of embedded systems.
## Here a breakdown about Bootloader stages

### 1- Primary Bootloader (First Stage Bootloader - FSBL):
 - The primary bootloader is often a small piece of code stored in ROM or a non-volatile memory that runs immediately after the system is powered on or reset.
 - Its main job is to initialize the minimum hardware such as SRAM (cache memory) required to load the secondary bootloader. This includes setting up the CPU and memory.

### 2- Secondary Bootloader (Second Stage Bootloader - SSBL):
 - The secondary bootloader runs in SRAM and it's functionality is limited by size of SRAM. It is responsible for initializing additional hardware such as DRAM and preparing the system to load the operating system.
 - Bios runs in SRAM and loads U-boot -In our situation- in DRAM then jump to it.

### 3- Tertiary Bootloader (Third Stage Bootloader - TSBL):
- Here we run full bootloader (U-boot) in DRAM, This u-boot loads the kernal into DRAM, It can load the kernel from various sources such as SD cards or over Network (e.g.,TFTP).
-  At the end of the TP stage, Kernal is ready to run in memory.

# Let's get starting in using Customizing the U-boot
### 1-First step: clone from U-boot repo
```
git clone https://source.denx.de/u-boot/u-boot.git
```
### 2-Go to u-boot directory
```
cd u-boot/

```
### 3-Building with GCC
For building U-Boot you need a GCC compiler for your host platform. If you are not building on the target platform you further need a GCC cross compiler.

- 

- 3-1-Get your machine configuration from U-boot/configs
```
ls configs/ | grep [your machine] 
```
- We are working on Qemu emulator which is Vexpress Cortex A9 
```
ls configs/ | grep vexpress_ca9x4_defconfig
```
- 


