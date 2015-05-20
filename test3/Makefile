CC=gcc
CFLAGS=-I.
DEPS = commonemittermake.h
OBJ = commonemittermake.o commonemitter1.o
%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
commonemittermake: $(OBJ)
				gcc -o $@ $^ $(CFLAGS)
