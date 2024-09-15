# Load Image from Virtual SD Card
### What have we done so far!?
- Let's first summarize what we have done to make our image run properly without a customization tool. We first created our cross-compiler using the tool Crosstool-NG, and then we created our target bootloader, which was U-Boot.
- Now after cloning our kernel and having zImage we want to boot using our kernel Image through Virtual SD Card

1. We will Create virtual SD card 
``` bash
touch sd.img
```
2. Write zeros to this file of size = 1M
``` bash 
dd if=/dev/zero of=sd.img bs=1M count=1024
``` 
![Write_to_File](./Source_Img.png)
3. Drivide it into partitions --> FAT16 (Primary - Loadable) = 200 MB , ext4 = 500 MB
``` bash
cfdisk sd.img
```
4. This will open a GUI so we will chose dos type

![Divide_partitions](./ss.png)

5. Then we will attach it with loop to be mapped as block device by running next code 
```bash
sudo losetup -f --show --partscan sd.img
```
6. You can show ur sd Card loop by running 
```bash 
losetup -a | grep loop5
```
7. Then we Format the boot and rootfs partition to be Fat16 and ext4 
``` bash
sudo mkfs.vfat -F 16 -n boot /dev/loop5p1
sudo mkfs.ext4 -l rootfs /dev/loop5p2
```
8. Last step in SD card is to mount it 
``` bash 
cd ~
mkdir boot 
mkdir rootfs
$ sudo mount ${DISK}p1 ~/boot
$ sudo mount ${DISK}p2 ~/rootfs
```
# Write the Script
![writing_script](./script.png)
9. put Files into Boot folders and create zImage of the script
![Creating_zImage](./Screenshot%20from%202024-07-22%2011-50-29.png)
# Booting from SD-Card

10. Go to u-boot directory and Run Qemu attaching path of sd card
```bash 
qemu-system-arm -M vexpress-a9 -nographic -kernel ./u-boot  -sd /home/mostafam722/sd.img 
```
- Then You need to check having sd card by running
``` bash 
mmc dev 
```
![Check_mmc](./mmcdev.png)
- Load file from mmc boot file 
``` bash 
fatload mmc 0:1 ${KERNEL_addr_r} zImage
source ${KERNEL_addr_r}
```
![Booting_kernel_addr](./Screenshot%20from%202024-07-22%2012-42-43.png)
