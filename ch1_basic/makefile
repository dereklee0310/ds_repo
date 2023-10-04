CC=gcc 
CFLAGS=-Wall
# option = -g -O0
SRC = $(wildcard *.c)
EXE = $(patsubst %.c,%.exe,$(SRC))

all: $(EXE)

%.exe : %.c
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	del *.exe