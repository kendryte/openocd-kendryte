Build on Windows
===

* [Compiling with Msys2](#compiling-with-msys2)
* [Compiling with Cygwin](#compiling-with-cygwin)
* [After Compiling](#after-compiling)

### Compiling with Msys2
>**Note:** To be compatible with both 32-bit and 64-bit operating systems, the best choice is to use MinGW 32-bits console.

#### 1. Install dependencies

***Note:*** The library of `hidapi` and `ftdi` is optional.

```bash
pacman -S autoconf automake pkg-config libtool binutils gcc git make mingw-w64-i686-toolchain mingw-w64-i686-libusb mingw-w64-i686-hidapi mingw-w64-i686-libftdi
```

#### 2. Get the source

```bash
git clone https://github.com/kendryte/openocd-kendryte.git
cd openocd-kendryte
```

#### 3. Run the following command in the project root directory

```bash
./bootstrap
./configure --build=i686-w64-mingw32 --host=i686-w64-mingw32
make
```

If the following error occurs during make:
```
../config.h:83:0: error: "__USE_MINGW_ANSI_STDIO" redefined [-Werror]
 #define __USE_MINGW_ANSI_STDIO 1
```
you can open `openocd-kendryte\src\jtag\drivers\libjaylink\config.h` and convert
```c
/* Define to 1 to use C99 compatible stdio functions on MinGW. */
#define __USE_MINGW_ANSI_STDIO 1
```
to
```c
/* Define to 1 to use C99 compatible stdio functions on MinGW. */
#ifndef __USE_MINGW_ANSI_STDIO
#define __USE_MINGW_ANSI_STDIO 1
#endif
```

### Compiling with Cygwin

#### 1. Install [Cygwin](http://www.cygwin.com/) with the following packages

* autoconf (all packages)
* automake (all packages)
* binutils
* gcc
* git
* libtool
* libusb-1.0
* make
* mingw-w32

#### 2. Get the source

```bash
git clone https://github.com/kendryte/openocd-kendryte.git
cd openocd-kendryte
```

#### 3. Run the following command in the project root directory

```bash
./bootstrap
./configure --build=i686-pc-cygwin --host=i686-w64-mingw32
make
```

### After Compiling

The executable file `openocd.exe` in `openocd-kendryte\src\` can be run from the Windows command line and does not require Msys2 or Cygwin, you can copy this file to a new folder like `C:\kendryte-openocd\bin`.

Download the latest [WindowsTools](https://github.com/kendryte/openocd-kendryte/releases) from [https://github.com/kendryte/openocd-kendryte/releases](https://github.com/kendryte/openocd-kendryte/releases).

Use `Zadig` to convert the vendor drivers to WinUSB drivers for your JTAG device.

There are some dlls in the `mingw32-dll` directory, copy them to the path where openocd runs.
