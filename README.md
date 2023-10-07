# Geehy APM32F003 project template

This repository contains my project template (and mandatory LED blinking code example) 
for the dirt-cheap [Geehy APM32F003](https://global.geehy.com/apm32?type=1) microcontroller.

Structure:

* [geehy](geehy) subdirectory contains startup code, linker scripts, CMSIS header files
  and drivers - all extracted from [Geehy](https://www.geehy.com/) `APM32F00x_SDK_V1.4`.
  * only `GPIO` and `RCM` drivers are included in the build, if you need other drivers, 
    you need to edit the [Makefile](Makefile).
* [src](src) contains actual blinker source code.

Note:

* I use [make](https://www.gnu.org/software/make/) as a build tool. I consider reworking it
  to [CMake](https://cmake.org/) or [SCons](https://scons.org/)  some day, to make it
  cross-platform. Maintaining a cross-platform `Makefile` is a nightmare (been there, 
  done that), I don't want to fight slashes vs backslashes ever again in my life :) 
  But it's not my priority, though, PRs welcome.
* I've used `APM32F003F6P6` (32kB Flash / 4kB RAM) variant, if you want to use 
  `APM32F003F4P6` (16kB Flash / 2kB RAM), remember to tweak the `Makefile`  - 
  `LD_SCRIPT` variable should point to
  [geehy/APM32F00x/Source/gcc/gcc_APM32F00xx4.ld](geehy/APM32F00x/Source/gcc/gcc_APM32F00xx4.ld) in such case.

## Flashing / debugging

I've successfully used a `Segger J-Link v8`  clone + [OpenOCD](https://openocd.org/) for 
flashing and debugging. Support for `APM32F00x` is not yet included in the official 
`OpenOCD` release, however (and `Geehy` only released Windows binaries, as far I know).

I have found [this patch](https://review.openocd.org/gitweb?p=openocd.git;a=commitdiff;h=ea291b5ff9bb316cdf2e4aa50e0c58642b048cef), 
fixed it to apply cleanly on top of the current code and actually compile, it seems to work fine. 
You can grab patched `OpenOCD` from [my forked repo](https://github.com/codepainters/openocd), 
from the `apm32` branch (you have to compile it yourself, of course).

For `J-Link` probe you can use [openocd.cfg](openocd.cfg) directly:
```
$ openocd -f openocd.cfg
```
For other probes tweak the first commandi in the `openocd.cfg` file accordingly.

## How to run Blinky

In order to build the sample project:

* set `ARM_TOOLCHAIN_PATH` environment variable to point to the directory 
  containing `arm-none-eabi-gcc` and other binaries, or set your `PATH` accordingly.
* run `make` - if all is OK, you should get `out/blinky.elf` file.
* flash it to your test board, e.g. with `OpenOCD` and `gdb`, issuing `load` command in `gdb`.

### Test hardware

All my test were performed with a bare minimum circuit done on the breadboard. The only necessary connections are:

* +5V to `VDD` (pin 9), ground to `VSS` (pin 7),  some decoupling capacitor
* 1uF capacitor between `VCAP` (pin 8) and ground
* LED (with 1k resistor in series), between `PD4` (pin 1) and ground
* your SWD probe of choice attached to `SWCLK` (pin 19), `SWDIO` (pin 18) and `NRST` (pin 4).

**WARNING:** the capacitor between `VCAP` and ground is very important. I've lost a few hours
debugging random `Hard Fault` crashes early in startup code, just to realize that I connected
the capacitor to the wrong pin by mistake. On the other hand, demo board from `Geehy` uses 10k 
pull-up resistor on `SWDIO` and 10k pull-down on `SWCLK`, but everything works fine for me 
without those resistors.









