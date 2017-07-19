OPENBLAS_PATH=/usr/local/opt/openblas
CC = cc
AR = ar
CFLAGS = -I$(OPENBLAS_PATH)/include
LDFLAGS = -L$(OPENBLAS_PATH)/lib -Lobj
LIBS = -lopenblas -lmorpheus


LIB_SRC = $(wildcard src/*.c)
LIB_OBJ = $(patsubst src/%.c, obj/%.o, $(LIB_SRC))

all: obj/lsapp

obj/lsapp: tests/least_squares_test.c obj/libmorpheus.a
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


obj/libmorpheus.a: $(LIB_OBJ)
	$(AR) rcs $@ $^

clean:
	rm obj/*
