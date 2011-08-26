# Description
**dwm** is a dynamic tiling window manager. Customization of dwm involves editing the __config.h__ header file and changes to the source code, most commonly in __dwm.c__. This is a repository of my entire Arch Linux dwm folder which contains changes to dwm.c and to config.h. 

# How to Use This Repository
I cannot guarantee that this will work on your system. But you can try. 

If you are using Arch Linux, it is very simple to build my dwm if you just want an exact copy of it.

Clone the repository using git: 

```
git clone git@github.com:spo11/dwm.git
```

Navigate to this folder in which you have cloned this repository on your computer. Then run the following command to both compile and install this custom dwm to your system. 

```
makepkg -efi --skipinteg
```

# installing dwm patches
[patches](http://dwm.suckless.org/patches/) for dwm have to be implemented into dwm's source code. 

Generally you must download a patch that corresponds to the version of dwm you are using. For example, if I were using dwm 5.9, I would want dwm-5.9-uselessgap.diff. Save the patch to the src/dwm-5.9 folder. 

Run the following command:
```
patch -p1 < nameofpatch.diff
```
 
Once you have done that, open the _*.diff_ file in a text editor to see if there are any changes you must make manually. Since I have a custom _config.h_, I have to manually add/change lines specified by the patch file there. In Arch Linux, you want to change the _config.h_ located in the same directory as the PKGBUILD. 
