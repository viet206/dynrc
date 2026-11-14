CC = gcc
LD = ld
CFLAGS = -ffreestanding -nostdlib -nostdinc -nostartfiles -Wall -Wextra -I../src -O3 -pedantic -std=c99 -s

SRC = ../src/memory.c ../src/string.c
OBJ = $(notdir $(SRC:.c=.o))

.PHONY: all clean

all: ubox.o

%.o:
	$(CC) $(CFLAGS) -c ../src/$*.c -o $@

ubox.o: $(OBJ)
	$(LD) -r -o $@ $^
	cp ../src/ubox.h .
	rm -f $(OBJ)

clean:
	rm -f ubox.o
	rm -f ubox.h
