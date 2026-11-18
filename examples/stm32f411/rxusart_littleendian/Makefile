CC =  arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -g -O0 -c -Wall -Wextra -nostdlib  -I/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/inc  -I/home/Alex/BARE_METAL/scara-robot-firmware/drivers/common -I/home/Alex/BARE_METAL/libs/as5600
LINKFLAGS = -mcpu=cortex-m4 -g -O0 -T linker.ld -Wall -Wextra -nostdlib  -I/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/inc  -I/home/Alex/BARE_METAL/scara-robot-firmware/drivers/common -I/home/Alex/BARE_METAL/libs/as5600


BUILDDIR = /home/Alex/BARE_METAL/scara-robot-firmware/build/stm32f411/motors_movement/

all: final

final: main.o startup.o gpio.o rcc.o usart.o i2c.o as5600.o tim.o
	$(CC) $(BUILDDIR)main.o $(BUILDDIR)startup.o $(BUILDDIR)as5600.o $(BUILDDIR)tim.o $(BUILDDIR)usart.o $(BUILDDIR)i2c.o $(BUILDDIR)gpio.o $(BUILDDIR)rcc.o $(LINKFLAGS) -o $(BUILDDIR)final

main.o:main.c
	$(CC) $(CFLAGS) main.c -o $(BUILDDIR)main.o

startup.o:startup.c
	$(CC) $(CFLAGS) startup.c -o $(BUILDDIR)startup.o

as5600.o:/home/Alex/BARE_METAL/libs/as5600/as5600.c
	$(CC) $(CFLAGS) /home/Alex/BARE_METAL/libs/as5600/as5600.c -o $(BUILDDIR)as5600.o

gpio.o:/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/gpio.c
	$(CC) $(CFLAGS) /home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/gpio.c -o $(BUILDDIR)gpio.o

rcc.o:/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/rcc.c
	$(CC) $(CFLAGS) /home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/rcc.c -o $(BUILDDIR)rcc.o

usart.o:/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/usart.c
	$(CC) $(CFLAGS) /home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/usart.c -o $(BUILDDIR)usart.o

i2c.o:/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/i2c.c
	$(CC) $(CFLAGS) /home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/i2c.c -o $(BUILDDIR)i2c.o

tim.o:/home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/tim.c
	$(CC) $(CFLAGS) /home/Alex/BARE_METAL/scara-robot-firmware/drivers/stm32f411_drivers/src/tim.c -o $(BUILDDIR)tim.o


clean:
	rm -rf $(BUILDDIR)*.o $(BUILDDIR)final

start:
	openocd -f /usr/share/openocd/scripts/interface/stlink.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg

load:
	arm-none-eabi-gdb $(BUILDDIR)final -ex 'target remote localhost:3333' -ex 'monitor reset halt' -ex 'load' 
