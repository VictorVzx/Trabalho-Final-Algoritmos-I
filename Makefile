CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = main

# Correção 1: Adicionado o '=' que faltava
SRCS = main.c $(shell find functions -name "*.c")

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)