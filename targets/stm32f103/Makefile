CFLAGS = -Wall -Wpedantic -Wextra 

all: final

final: main.o hello.o
	gcc $(CFLAGS) main.o hello.o -o final

main.o: main.c
	echo "Compiling the main file"
	gcc $(CFLAGS) -c main.c

hello.o: hello.c
	echo "Compiling the hello file"
	gcc $(CFLAGS) -c hello.c

clean:
	rm -rf *.o
