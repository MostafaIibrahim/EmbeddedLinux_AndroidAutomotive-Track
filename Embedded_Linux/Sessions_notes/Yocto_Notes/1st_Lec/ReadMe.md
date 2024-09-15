# Introduction to Yocto
### What is Yocto?
- Yocto is an autobuild tool that helps developer to custom Embedded Linux System for building their own distrobution

- Yocto project is a reference teach us how to build our own distribution using openembedded buildengine (bitbake) and some layers from them

- Yocto provides a reference build system for embedded Linux, called Poky, which
has the BitBake and OpenEmbedded-Core (OE-Core) projects at its base.
### How to create a recipe
- Don't Configure any existing layer to add a featur or anything but create yours, It's not about Licance but it's a design issue-Hirarchey of Yocto-.
 
1. Create a Layer in Yocto
- Create it outside of poky and anything related to --> Open embedded or Third Party.
### So How to Create a layer outside Poky
``` bash
bitbake-layers create-layer [Path/meta.] #This creates a templete of the layer
```
- Create-Layer --> sub command that give me Hirarchey of the layer
- Note that the Path should be outside poky.
