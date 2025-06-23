CC=gcc
CFLAGS=-Iinc -Wall -Wextra -std=c99
OBJ=src/main.o src/bme280.o src/ssd1306.o src/fonts.o

all: main

main: $(OBJ)
	$(CC) $(OBJ) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main
