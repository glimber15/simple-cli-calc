CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude
PREFIX = $(HOME)/.local
BINDIR = $(PREFIX)/bin

SRC = main.c src/*.c
OBJ = $(SRC:.c=.o)

TARGET = calc

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

install: calc
	mkdir -p $(BINDIR)
	cp calc $(BINDIR)

uninstall:
	rm -f $(BINDIR)/calc

.PHONY: all clean run