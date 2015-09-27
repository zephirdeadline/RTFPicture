# Basic Makefile
 
CPPFLAGS=
CC=clang
CFLAGS=-lSDLmain -lSDL `pkg-config --cflags --libs gtk+-2.0` 
LDFLAGS=
LDLIBS=
 

all:
 
clean:
	rm -f *~ *.o
 
# END
