CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic \
	 -Wwrite-strings -O2
LDFLAGS = -lncurses

objects = fsmap.o
executable = fsmap

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

fsmap.o: fsmap.c
