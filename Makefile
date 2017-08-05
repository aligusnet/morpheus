CC = cc
AR = ar
CCFLAGS = -Iexternal -O3 -std=c99
UNITY_CCFLAGS = -DUNITY_INCLUDE_DOUBLE \
	-DUNITY_DOUBLE_VERBOSE \
	-DUNITY_DOUBLE_PRECISION=1e-5
LDFLAGS = -Lobj
LIBS = -lmorpheus -lunity -lm


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
		LDFLAGS += -L$(OPENBLAS)/lib
	else
		CCFLAGS += -DACCELERATE
		LIBS += -framework accelerate
	endif
endif


OPENBLAS_PATH ?= /usr/local/opt/openblas

LIB_SRC = $(wildcard src/*.c)
LIB_OBJ = $(patsubst src/%.c, obj/%.o, $(LIB_SRC))

TESTS_SRC = $(wildcard tests/*.c)


all: obj/testapp

obj/testapp: $(TESTS_SRC) obj/libmorpheus.a obj/libunity.a
	$(CC) $(TESTS_SRC) $(CCFLAGS) $(UNITY_CCFLAGS) $(LDFLAGS) $(LIBS) -o $@

obj/%.o: src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

obj/libmorpheus.a: $(LIB_OBJ)
	$(AR) rcs $@ $^

obj/libunity.a: obj/unity.o
	$(AR) rcs $@ $^

obj/unity.o: external/Unity/unity.c
	$(CC) $(CCFLAGS) $(UNITY_CCFLAGS) -Iexternal/Unity -c $< -o $@

clean:
	rm obj/*

docs:
	doxygen

.PHONY: clean docs
