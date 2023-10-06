# Project template for Geehy APM32F003 MCU

This repository contains my project template (and mandatory LED blinking code) for the el cheapo `Geehy APM32F003` microcontroller.

Note:

* `Make` is used for building. I consider reworking it to `CMake` or `SCons`, I'd like it to be cross-platform, but maintaining a cross-platform `Makefile` is a nightmare (been there, done that), I don't want to fight slashes vs backslashes ever again in my life :) It's not my priority, though, PRs welcome.
* I successfully flashed and debugged the MCU using `Segger J-Link v8`  clone + `OpenOCD`, but support for `APM32F00x` is not yet included in the official `OpenOCD` releases. I have found [this patch](https://review.openocd.org/gitweb?p=openocd.git;a=commitdiff;h=ea291b5ff9bb316cdf2e4aa50e0c58642b048cef), but had to fix it to actually apply and build. It seems to work fine. You can grab patched `OpenOCD` from [my repo](https://github.com/codepainters/openocd), from the `apm32` branch (you'll have to compile it yourself, of course).



Structure:

* `geehy` subdirectory contains startup code, linker scripts, CMSIS header files and drivers - all extracted from Geehy `APM32F00x_SDK_V1.4`

  * only `GPIO` driver is included in the compilation, if you need other drivers, you'll need to edit `Makefile`. 

* `src` contains actual application.

  

  

  

  

  