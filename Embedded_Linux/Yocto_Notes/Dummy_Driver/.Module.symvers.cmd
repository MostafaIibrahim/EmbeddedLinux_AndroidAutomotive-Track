cmd_/home/mostafa/Desktop/ITI_Docs/AdminLinux_Lab/Embedded-LinuxI/Embedded_Linux/Yocto_Notes/Dummy_Driver/Module.symvers := sed 's/\.ko$$/\.o/' /home/mostafa/Desktop/ITI_Docs/AdminLinux_Lab/Embedded-LinuxI/Embedded_Linux/Yocto_Notes/Dummy_Driver/modules.order | scripts/mod/modpost -m -a  -o /home/mostafa/Desktop/ITI_Docs/AdminLinux_Lab/Embedded-LinuxI/Embedded_Linux/Yocto_Notes/Dummy_Driver/Module.symvers -e -i Module.symvers   -T -