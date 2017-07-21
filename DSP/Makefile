MASTER_MAKE = -f M128.make
SLAVE_MAKE = -f M88.make

## Build
help:
	@echo "use \"make {filename}.a\" to complie .c to .hex in dir ./hex"

uart-test1:
	make $(MASTER_MAKE) ./UART/test1/master_main.hex
	make $(SLAVE_MAKE) ./UART/test1/slave_main.hex
