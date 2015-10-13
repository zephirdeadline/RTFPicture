# Basic Makefile
 
CPPFLAGS=
CC=clang
CFLAGS= -Wall -Wextra -o2 -lSDLmain -lSDL -lSDL_image `pkg-config --cflags --libs gtk+-2.0` 
LDFLAGS=
LDLIBS=
 

all:

data:
	$(CC) $(CFLAGS) data.c testData.c -o testData

main:
	$(CC) $(CFLAGS) main.c funcInter.c -o main

clean:
	rm -f *~ *.o .*.swp
 
# END
