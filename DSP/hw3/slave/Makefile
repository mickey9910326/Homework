## General Flags
MCU = atmega88
CC = avr-gcc
CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99  -DF_CPU=8000000UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
# CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS += -Wl,-u,vfprintf  -Wl,-u,vfscanf -Wl,-Map=$*.map

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature
HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings

## Libraries
# LIBS = -lm -lprintf_flt -lscanf_flt

## Objects that must be built in order to link
OBJECTS += ASA_slave_SPI.o
OBJECTS += ASA_XXX.o
OBJECTS += ASA_STDIO.o

## Objects explicitly added by the user
# LINKONLYOBJECTS = ".\LIB\ASA_Lib.o"
LINKONLYOBJECTS =

## Build
help:
	@echo "use \"make {filename}.a\" to complie .c to .hex in dir ./hex"

## LIB OBJECTS Compile
ASA_DIO.o: ./LIB/ASA_DIO.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ASA_SPI.o: ./LIB/ASA_SPI.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ASA_slave_SPI.o: ./LIB/ASA_slave_SPI.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ASA_STDIO.o: ./LIB/ASA_STDIO.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ASA_XXX.o: ./LIB/ASA_XXX.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

%.o: ./LIB/%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
%.elf: %.o $(OBJECTS)
	 $(CC) $(LDFLAGS) $< $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $@

%.hex: %.elf
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.a: %.elf %.hex
	@echo
	@avr-size -C --mcu=${MCU} $<
	@-mkdir -p hex
	@-mv $*.hex hex/
	@-rm -rf $(OBJECTS) $*.map $*.o $<

%.eep: %.elf
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: %.elf
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) *.elf *.hex ./hex/*
