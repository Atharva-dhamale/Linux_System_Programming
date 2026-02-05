CC = gcc
AR = ar
CFLAGS = -c

OBJ = Addition.o Subtraction.o Multiplication.o Division.o
LIB = libmath.a

all: lib app

lib: $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

Addition.o: Addition.c
	$(CC) $(CFLAGS) Addition.c

Subtraction.o: Subtraction.c
	$(CC) $(CFLAGS) Subtraction.c

Multiplication.o: Multiplication.c
	$(CC) $(CFLAGS) Multiplication.c

Division.o: Division.c
	$(CC) $(CFLAGS) Division.c


app: program8_5.c $(LIB)
	$(CC) program8_5.c -L. -lmath -o app

clean:
	rm -f *.o *.a app
