CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic \
	 -Wwrite-strings -O2
LDFLAGS =

objects = fsmap_test.o fsmap.o
executable = fsmap_test

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

fsmap_test.o: fsmap_test.c fsmap.h
fsmap.o: fsmap.c fsmap.h
