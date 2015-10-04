# Basic Makefile
 
CPPFLAGS=
CC=clang
CFLAGS=-lSDLmain -lSDL -lSDL_image `pkg-config --cflags --libs gtk+-2.0` 
LDFLAGS=
LDLIBS=
 

all:
	$(CC) $(CFLAGS) data.c testData.c -o testData
 
clean:
	rm -f *~ *.o .*.swp
 
# END
