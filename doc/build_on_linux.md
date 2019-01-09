Build on Linux
===

>**Note:** Take Debian/Ubuntu as an example

### First, you need the following dependencies

* make
* libtool
* pkg-config >= 0.23 (or compatible)
* autoconf
* automake
* texinfo
* libusb-dev
* libftdi-dev (optional)
* libhidapi-dev (optional)

### And you need to install drivers for your JTAG adapters

For example, if you are using J-Link, you can download the J-Link driver (DEB installer) from [here](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack), then:
```bash
sudo dpkg -i JLink_Linux_xxx_xxx.deb
```

### Get the source

```bash
git clone https://github.com/kendryte/openocd-kendryte.git
cd openocd-kendryte
```

### Run the following command in the project root directory

```bash
./bootstrap
./configure
make
sudo make install # optional
```

The `configure` step generates the Makefiles required to build
OpenOCD, run `./configure --help` to see the list of all the supported options.</br>
The first `make` step will build OpenOCD and place the final executable in `./src/`.</br>
The final (optional) step, `make install`, places all of the files in the required location.
