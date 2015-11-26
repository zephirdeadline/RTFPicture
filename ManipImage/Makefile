CC=clang
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O3 -lm -lSDL -lSDLmain -lSDL_image `pkg-config --cflags --libs gtk+-2.0`
LDLIBS=`pkg-config --libs sdl`

all:
	$(CC) $(CFLAGS) manip.c -o manip

histo:
	$(CC) $(CFLAGS) pretraitement2.c testHisto.c -o histo

traitement:
	$(CC) $(CFLAGS) pretraitement2.c mainTransImg.c -o Traitement


clean: 
	rm -f *.o *~
	rm -f RTFPicture
