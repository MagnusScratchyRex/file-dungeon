fsmapdir = lib/fsmap/

CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic \
	 -Wwrite-strings -O2 -I$(fsmapdir)
LDFLAGS = -lncurses

objects = main.o $(fsmapdir)fsmap.o
executable = fd

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

main.o: main.c $(fsmapdir)fsmap.h
fsmap.o: $(fsmapdir)fsmap.c $(fsmapdir)fsmap.h
