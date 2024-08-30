# Device Drivers
- A device driver in Linux is a specialized piece of software that allows the operating system to communicate with hardware devices.Device drivers act as intermediaries between the hardware and the higher-level software, translating general input/output instructions into device-specific operations.
- Device drivers are typically written in C or C++ and are compiled into kernel modules, which are loaded into the kernel when the system boots.

### Why Would I need a device driver?
- when you need to add support for a device that is not currently supported by the Linux kernel.

- when a piece of hardware requires direct communication with the operating system, but no existing driver supports that hardware. For example, if you develop a custom embedded system with a unique sensor, you would need to write a device driver to allow the Linux kernel to interact with that sensor.

- when you want to optimize the performance of a device by writing a custom driver that takes advantage of specific hardware features or capabilities.

## How to write a driver!?

Driver.c 

```C
dev_t device_number;
struct file_operation fops;
struct cdev mycdev;

ssize_t mywrite(file,buff,size,){
    copy_from_user(buff); //Retrieve data from physical user
}
```

# Now I have written a Device Driver, How to match it with the physical HW which was inserted!?

- Before it we need to understand what is the difference between: Platform Device - Platform Driver - Platform Bus.
    - Platform Devices: These are typically devices integrated into the system's board or System on Chip (SoC), and their configuration is fixed and known in advance. Examples include GPIO controllers, I2C controllers, SPI devices, UARTs, etc
    - Platform Drivers: These are device drivers that handle platform devices. The kernel matches platform drivers to platform devices based on the device name. When a match occurs, the platform driver's probe() function is called, where it initializes the device.
        - probe() : This function is called when the driver is loaded. It is used to initialize the device and to register the device with the kernel.
    - Platform Bus: It acts as a conduit for the communication between the platform devices and their drivers. The platform bus manages platform devices by matching them with the corresponding platform drivers
        - The platform bus doesn't discover devices on its own (unlike the PCI bus or USB bus). Instead, platform devices are registered explicitly by the kernel during boot or through device tree declarations (on ARM architectures).

### Why Use the Platform Bus?
- Many devices in embedded systems are not connected to dynamic buses (like PCI or USB), where devices can be hot-plugged and discovered automatically. These devices may be integrated directly into the system (e.g., I2C, SPI devices, or memory-mapped devices), and thus need to be handled in a fixed way.

## As a conclusion --> The platform bus is essential for dealing with non-discoverable devices commonly found in embedded systems. It provides a simple way for the Linux kernel to manage these devices and allow the corresponding drivers to initialize and control them.

- what is device tree source --> It's a description of connected device on my HW put inside meta data and this dts call probe function and inside probe function we write out logic of initializing.
probe function will not be called until I write insmod to the deivce so it will be matched or compatible with dts and then dts call probe function of the device 
```c
//node name
lcd{
compatible = "lcd1234";
}
```
- what is device tree ?
- device tree is a data structure that describes the hardware components of a system, including their connections and properties. It is used by the Linux kernel to discover and configure hardware devices.
- device tree is typically represented as a binary file, known as a device tree blob (DTB)

- what is device tree overlays ?
- device tree overlays are used to add or modify hardware components on a system without modifying the underlying device
- device tree overlays are typically used in embedded systems where hardware components are added or modified after the initial device tree is created
- device tree overlays are represented as a separate binary file, known as a device tree overlay blob 

- So instead of having driver for every device 