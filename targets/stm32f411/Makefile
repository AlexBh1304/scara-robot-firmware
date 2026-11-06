CC =  arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -g -O0 -c -Wall -Wextra -nostdlib
LINKFLAGS = -mcpu=cortex-m4 -g -O0 -T linker.ld -Wall -Wextra -nostdlib 

all: final

final: main.o startup.o
	$(CC) main.o startup.o $(LINKFLAGS) -o final

main.o:main.c
	$(CC) $(CFLAGS) main.c

startup.o:startup.c
	$(CC) $(CFLAGS) startup.c

clean:
	rm -rf *.o final

load:
	arm-none-eabi-gdb final -ex 'target remote localhost:3333' -ex 'monitor reset halt' -ex 'load' 
