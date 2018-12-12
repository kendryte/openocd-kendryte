Kendryte OpenOCD
=======

The **Kendryte OpenOCD** forks from [riscv-openocd](https://github.com/riscv/riscv-openocd), improved for Kendryte K210.

## Kendryte Support

* Stronger stability and better debugging experience
* Support for multi-core debugging
* Not guaranteed to be compatible with other chips
  
## Prebuild

Prebuild can be downloaded at [github releases](https://github.com/kendryte/openocd-kendryte/releases).

Also you can get them on Kendryte website: https://kendryte.com

## Configuration for K210

There is a template configuration in `tcl/kendryte.cfg`:
```
# debug adapter
interface jlink
jlink serial 000504401724

transport select jtag
adapter_khz 3000

# server port
gdb_port 3333
telnet_port 4444

# add cpu target
set _CHIPNAME riscv

jtag newtap $_CHIPNAME cpu -irlen 5 -expected-id 0x04e4796b

set _TARGETNAME $_CHIPNAME.cpu
target create $_TARGETNAME riscv -chain-position $_TARGETNAME

# command
init
halt
```

## Build from source

### Linux

1. Install dependencies:
* make
* libtool
* pkg-config
* autoconf
* automake
* texinfo
* libusb-1.0
  
2. Download the J-Link driver (DEB installer) from [here](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack), then:
```bash
sudo dpkg -i JLink_Linux_xxx_xxx.deb
```

3. Download or clone the source:
```bash
git clone https://github.com/kendryte/openocd-kendryte.git
cd openocd-kendryte
```

4. Run the following sequence of commands:
```bash
./bootstrap
./configure # [other options]
make
sudo make install # if needed
```

### Windows

1. Install [Cygwin](http://www.cygwin.com/) with the following packages:
* autoconf (all packages)
* automake (all packages)
* binutils
* gcc
* gcc-core
* gcc-g++
* git
* libtool
* libusb-1.0
* make
* mingw-binutils
* mingw-gcc
* mingw-gcc-core
* mingw-gcc-g++
* mingw-pthreads
* mingw-runtime

2. Download or clone the source:
```bash
git clone https://github.com/kendryte/openocd-kendryte.git
cd openocd-kendryte
```

3. Run the following sequence of commands:
```bash
./bootstrap
./configure --build=i686-pc-cygwin --host=i686-w64-mingw32 # [other options]
make
```

4. The executable file `openocd.exe` in `C:\cygwin\home\user\openocd-kendryte\src ` can be run from the Windows command line and does not require Cygwin, you can copy this file to a new folder like `C:\openocd-bin`.

5. Download the latest [libusb releases](https://sourceforge.net/projects/libusb/), and copy `MinGW32\dll\libusb-1.0.dll` to the directory of `openocd.exe`.

6. Download [Zadig](http://zadig.akeo.ie/) and convert the vendor drivers to WinUSB drivers for your JTAG.

