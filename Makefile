CC = cc
AR = ar
CCFLAGS = -Iexternal -O3 -std=c99
UNITY_CCFLAGS = -DUNITY_INCLUDE_DOUBLE \
	-DUNITY_DOUBLE_VERBOSE \
	-DUNITY_DOUBLE_PRECISION=1e-5
LDFLAGS = -Lbin/lib
LIBS = -lmorpheus -lm


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ifdef OPENBLAS
		LIBS += -lopenblas
	else
		LIBS += -lblas -llapack
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


$(shell mkdir -p bin/obj/src bin/obj/tests bin/obj/benchmarks bin/lib)

LIB_SRC = $(wildcard src/*.c)
LIB_OBJ = $(patsubst src/%.c, bin/obj/src/%.o, $(LIB_SRC))

TESTS_SRC = $(wildcard tests/*.c)
TESTS_OBJ = $(patsubst tests/%.c, bin/obj/tests/%.o, $(TESTS_SRC))

BENCHMARKS_SRC = $(wildcard benchmarks/*.c)
BENCHMARKS_OBJ = $(patsubst benchmarks/%.c, bin/obj/benchmarks/%.o, $(BENCHMARKS_SRC))


all: bin/testapp bin/benchapp


test: bin/testapp
	./bin/testapp


bench: bin/benchapp
	./bin/benchapp

# library
bin/obj/src/%.o: src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

bin/lib/libmorpheus.a: $(LIB_OBJ)
	$(AR) rcs $@ $^

# unity
bin/obj/unity.o: external/Unity/unity.c
	$(CC) $(CCFLAGS) $(UNITY_CCFLAGS) -Iexternal/Unity -c $< -o $@

bin/lib/libunity.a: bin/obj/unity.o
	$(AR) rcs $@ $^

#tests
bin/obj/tests/%.o: tests/%.c
	$(CC) $(CCFLAGS) $(UNITY_CCFLAGS) -c $< -o $@

bin/testapp: $(TESTS_OBJ) bin/lib/libmorpheus.a bin/lib/libunity.a
	$(CC) $(TESTS_OBJ) $(CCFLAGS) $(UNITY_CCFLAGS) $(LDFLAGS) $(LIBS) -lunity -o $@

#benchmarks
bin/obj/benchmarks/%.o: benchmarks/%.c bin/lib/libmorpheus.a
	$(CC) $(CCFLAGS) -c $< -o $@

bin/benchapp: $(BENCHMARKS_OBJ)
	$(CC) $(BENCHMARKS_OBJ) $(CCFLAGS) $(LDFLAGS) $(LIBS) -o $@

clean:
	rm -rf bin

docs:
	doxygen

docker:
	docker build -t morpheus .
	docker run -ti -v ${PWD}:/build -w /build morpheus

.PHONY: clean docs docker
