#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432
TARGET = c1m4
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
IFILES = $(SOURCES:.c=.i)

ifeq ($(PLATFORM),HOST)
	# Architectures Specific Flags
	LINKER_FILE =
	CPU = 
	ARCH = 
	SPECS = 
else
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
endif

ifeq ($(PLATFORM),HOST)
	# Compiler Flags and Defines
	CC = gcc
	LD = 
	LDFLAGS = 
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES) -D$(PLATFORM)
	CPPFLAGs = 
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T$(LINKER_FILE)
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m \
	-mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(INCLUDES) -D$(PLATFORM)
	CPPFLAGs = 
endif

%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	size $(OBJS)

.PHONY: compile-all
compile-all: $(TARGET).o

 $(TARGET).o: $(OBJS)
	$(CC) -c $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@


.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMS) $(IFILES) $(TARGET).out $(TARGET).map