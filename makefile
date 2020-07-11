CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic \
	 -Wwrite-strings -O2
LDFLAGS = -lncurses

objects = fd.o
executable = fd

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

fd.o: main.c
