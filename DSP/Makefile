MASTER_MAKE = -f M128.make
SLAVE_MAKE = -f M128.make

## Build
help:
	@echo "use \"make {filename}.a\" to complie .c to .hex in dir ./hex"

uart-test1:
	make $(MASTER_MAKE) ./UART/test1/master_main.hex
	make $(SLAVE_MAKE) ./UART/test1/slave_main.hex

uart-test2:
	make $(MASTER_MAKE) ./UART/test2/master_main.hex
	make $(SLAVE_MAKE) ./UART/test2/slave_main.hex

uart-test3:
	make $(MASTER_MAKE) ./UART/test3/master_main.hex
	make $(SLAVE_MAKE) ./UART/test3/slave_main.hex
uart-test4:
	make $(MASTER_MAKE) ./UART/test4/master_main.hex
	make $(SLAVE_MAKE) ./UART/test4/slave_main.hex
clean:
	-rm -rf $(LIBOBJS) *.elf */*.hex ./hex/*
