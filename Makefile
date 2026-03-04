CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = src/str.c main.c
OUT = app

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)