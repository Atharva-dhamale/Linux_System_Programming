CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
SRC = program8_4.c Addition.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)

help:
	@echo "Usage:"
	@echo "  make        -> build the program"
	@echo "  make run    -> run the program"
	@echo "  make clean  -> remove compiled binary"
