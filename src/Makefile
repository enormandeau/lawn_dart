TARGET = lawn_dart
LIBS = -lm
CC = gcc
CFLAGS = -Wall -g -L/usr/local/lib -largtable2


.PHONY: build all clean

build: $(TARGET)
all: build
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

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

test:
	./lawn_dart 100 20 0.6 0 1000

