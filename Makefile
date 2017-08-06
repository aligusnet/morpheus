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
LIB_OBJ = $(patsubst src/%.c, obj/src_%.o, $(LIB_SRC))

TESTS_SRC = $(wildcard tests/*.c)
TESTS_OBJ = $(patsubst tests/%.c, obj/tests_%.o, $(TESTS_SRC))

BENCHMARKS_SRC = $(wildcard benchmarks/*.c)
BENCHMARKS_OBJ = $(patsubst benchmarks/%.c, obj/benchmarks_%.o, $(BENCHMARKS_SRC))


all: obj/testapp obj/benchmarkapp

# library
obj/src_%.o: src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

obj/libmorpheus.a: $(LIB_OBJ)
	$(AR) rcs $@ $^

# unity
obj/unity.o: external/Unity/unity.c
	$(CC) $(CCFLAGS) $(UNITY_CCFLAGS) -Iexternal/Unity -c $< -o $@

obj/libunity.a: obj/unity.o
	$(AR) rcs $@ $^

#tests
obj/tests_%.o: tests/%.c
	$(CC) $(CCFLAGS) $(UNITY_CCFLAGS) -c $< -o $@

obj/testapp: $(TESTS_OBJ) obj/libmorpheus.a obj/libunity.a
	$(CC) $(TESTS_OBJ) $(CCFLAGS) $(UNITY_CCFLAGS) $(LDFLAGS) $(LIBS) -o $@

#benchmarks
obj/benchmarks_%.o: benchmarks/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

obj/benchmarkapp: $(BENCHMARKS_OBJ)
	$(CC) $(BENCHMARKS_OBJ) $(CCFLAGS) $(LDFLAGS) $(LIBS) -o $@

clean:
	rm -f obj/*

docs:
	doxygen

.PHONY: clean docs
