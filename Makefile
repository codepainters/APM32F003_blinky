# vim: noexpandtab
#
# GNU GCC toolkit settings
#

ARM_TOOLCHAIN_PATH ?=
CROSS_COMPILE = $(ARM_TOOLCHAIN_PATH)arm-none-eabi-
AS = $(CROSS_COMPILE)gcc
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)gcc
SIZE = $(CROSS_COMPILE)size
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

#
# Project files
#

OUTFILE = blinky

INCLUDE_PATHS = -Isrc 
OBJS = $(addprefix objs/,main.o)

vpath %.c	src
vpath %.h	src

#
# Geehy driver library, device files, CMSIS.
#

DRIVERS_PATH=geehy/APM32F00x_StdPeriphDriver
DEV_PATH=geehy/APM32F00x
CMSIS=geehy/CMSIS

INCLUDE_PATHS += -I$(DRIVERS_PATH)/inc -I$(DEV_PATH)/Include -I$(CMSIS)/Include
OBJS += $(addprefix objs/, \
						$(DEV_PATH)/Source/gcc/startup_apm32f00x.o \
						$(DEV_PATH)/Source/system_apm32f00x.o \
						$(DRIVERS_PATH)/src/apm32f00x_gpio.o \
						$(DRIVERS_PATH)/src/apm32f00x_rcm.o )

vpath %.s	$(DEV_PATH)/src
vpath %.c	$(DEV_PATH)/src
vpath %.h	$(DEV_PATH)/inc
vpath %.c	$(DRIVERS_PATH)/src
vpath %.h	$(DRIVERS_PATH)/inc

#
# Compiler settings, parameters and flags
#

CPU_TYPE = cortex-m0plus
LD_SCRIPT = geehy/APM32F00x/Source/gcc/gcc_APM32F00xx6.ld

COMMON_FLAGS = -c -g -O0 $(INCLUDE_PATHS) -std=c99 -Wall -mthumb \
	-ffunction-sections -fdata-sections -fmessage-length=0 \
	-mcpu=$(CPU_TYPE) 

CFLAGS  = $(COMMON_FLAGS) -DTARGET=$(TARGET) -fno-builtin
ASFLAGS = $(COMMON_FLAGS) -D__ASSEMBLY__ -x assembler-with-cpp
LDFLAGS = -Wl,--nostdlib -mthumb -mcpu=$(CPU_TYPE) -Wl,--gc-sections -Wl,-Map=out/$(OUTFILE).map -g
LDLIBS  = -lm
OCFLAGS = --strip-unneeded

all: out/$(OUTFILE).bin

$(OBJS): | dirs

dirs:
	mkdir -p out
	mkdir -p objs
	mkdir -p objs/$(DRIVERS_PATH)/src
	mkdir -p objs/$(DEV_PATH)/Source/gcc/

objs/%.o : %.c 
	$(CC) $(CFLAGS) -o $@ $<

objs/%.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<

out/$(OUTFILE).elf: $(OBJS) $(SYS_OBJS)
	$(LD) $(LDFLAGS) -T $(LD_SCRIPT) -o out/$(OUTFILE).elf $(OBJS) $(LDLIBS)
	-@echo ""
	$(SIZE) out/$(OUTFILE).elf
	-@echo ""
	$(OBJCOPY) $(OCFLAGS) -O ihex out/$(OUTFILE).elf out/$(OUTFILE).hex
	
out/$(OUTFILE).bin: out/$(OUTFILE).elf
	$(OBJCOPY) $(OCFLAGS) -O binary out/$(OUTFILE).elf out/$(OUTFILE).bin

clean:
	rm -Rf objs
	rm -f out/$(OUTFILE).*

