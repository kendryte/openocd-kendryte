Build on OSX
===

>**Note:** You only need HomeBrew!

### Install dependencies

```bash
brew install autoconf automake libtool pkg-config libusb
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
```

The `configure` step generates the Makefiles required to build
OpenOCD, run `./configure --help` to see the list of all the supported options.</br>
The first `make` step will build OpenOCD and place the final executable in `./src/`.</br>
