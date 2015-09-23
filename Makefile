CC=clang

all: $(CC) `pkg-config --libs --cflags gtk+-2.0` main.c -o RTFPicture

