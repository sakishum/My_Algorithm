SRC := $(wildcard *.cpp)
EXE := test
GCC := g++-4.8
GCCFLAG := -std=c++11 -Wall

all: $(SRC)
	$(GCC) $(GCCFLAG) -o $(EXE) $?

.PHONY: clean
clean: $(EXE)
	$(RM) $?
