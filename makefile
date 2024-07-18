CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCS = duktape.c js_c.c utils.c main.c
OBJS = $(patsubst %.c,output/%.o,$(SRCS))
TARGET = output/c-js-example

.PHONY: all build clean

all: build run

build: $(OBJS) | output
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

run:
	./$(TARGET)

output:
	mkdir -p output

output/%.o: %.c | output
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf output $(TARGET)
