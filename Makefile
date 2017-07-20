CC = cc
AR = ar
CCFLAGS = -Iexternal -DUNITY_INCLUDE_DOUBLE
LDFLAGS = -Lobj
LIBS = -lmorpheus -lunity


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ifdef OPENBLAS
		LIBS += -lopenblas
	else
		LIBS += -lblas
	endif
endif
ifeq ($(UNAME_S),Darwin)
	ifdef OPENBLAS
		CCFLAGS += -I$(OPENBLAS)/include
		LIBS += -lopenblas
		LDFLAGS += -L$(OPENBLAS_PATH)/lib
	else
		CCFLAGS += -DACCELERATE
		LIBS += -framework accelerate
	endif
endif


OPENBLAS_PATH ?= /usr/local/opt/openblas

LIB_SRC = $(wildcard src/*.c)
LIB_OBJ = $(patsubst src/%.c, obj/%.o, $(LIB_SRC))


all: obj/testapp

obj/testapp: tests/main.c obj/libmorpheus.a obj/libunity.a
	$(CC) $(CCFLAGS) $(LDFLAGS) $< -o $@ $(LIBS)

obj/%.o: src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

obj/libmorpheus.a: $(LIB_OBJ)
	$(AR) rcs $@ $^

obj/libunity.a: obj/unity.o
	$(AR) rcs $@ $^

obj/unity.o: external/Unity/unity.c
	$(CC) $(CCFLAGS) -Iexternal/Unity -c $< -o $@

clean:
	rm obj/*
