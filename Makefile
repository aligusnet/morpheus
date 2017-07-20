OPENBLAS_PATH ?= /usr/local/opt/openblas

CC = cc
AR = ar
CFLAGS = -I$(OPENBLAS_PATH)/include -Icontrib -DUNITY_INCLUDE_DOUBLE
LDFLAGS = -L$(OPENBLAS_PATH)/lib -Lobj
LIBS = -lmorpheus -lunity -lopenblas


LIB_SRC = $(wildcard src/*.c)
LIB_OBJ = $(patsubst src/%.c, obj/%.o, $(LIB_SRC))


all: obj/testapp

obj/testapp: tests/main.c obj/libmorpheus.a obj/libunity.a
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/libmorpheus.a: $(LIB_OBJ)
	$(AR) rcs $@ $^

obj/libunity.a: obj/unity.o
	$(AR) rcs $@ $^

obj/unity.o: contrib/Unity/unity.c
	$(CC) $(CFLAGS) -Icontrib/Unity -c $< -o $@

clean:
	rm obj/*
