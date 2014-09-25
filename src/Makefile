TARGET = lawn_dart
LIBS = -lm
CC = gcc
CFLAGS = -Wall -g

.PHONY: build all clean

build: $(TARGET)
all: build

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@

install:
	cp $(TARGET) /usr/local/bin

clean:
	rm -f *.o
	rm -f *~
	rm -f $(TARGET)

