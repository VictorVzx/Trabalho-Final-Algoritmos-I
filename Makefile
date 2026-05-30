CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = main

SRCS := $(shell find . -name '*.c' -not -path './.git/*')

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)