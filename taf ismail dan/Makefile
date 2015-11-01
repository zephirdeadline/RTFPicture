CC=clang
CFLAGS= -Wall -Wextra -o2 -lm -lSDL -lSDLmain -lSDL_image `pkg-config --cflags --libs gtk+-2.0`
LDLIBS=`pkg-config --libs sdl`

all:
	$(CC) $(CFLAGS) main.c pretraitement2.c data.c eigenface.c  funcInter.c -o RTFPicture
