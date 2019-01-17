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

We have provided a template configuration for J-Link in `tcl/kendryte.cfg`, if you are using other JTAG emulators, please modify it yourself.

## Compiling and build

For Linux please see: [Build on Linux](doc/build_on_linux.md)

For Windows please see: [Build on Windows](doc/build_on_windows.md)

For OSX please see: [Build on OSX](doc/build_on_osx.md)
