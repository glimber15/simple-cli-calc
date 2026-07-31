CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude

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

.PHONY: all clean run