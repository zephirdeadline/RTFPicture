# Basic Makefile
 
CPPFLAGS=
CC=clang
CFLAGS=-lSDLmain -lSDL -lSDL_mixer -lSDL_ttf
LDFLAGS=
LDLIBS=
 
# empty all rule to prevent clean being the default rule
all:
 
clean:
	rm -f *~ *.o
 
# END