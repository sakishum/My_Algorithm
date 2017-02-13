SRC := $(wildcard *.cpp)
EXC := test
CXX := g++-4.7
CXXFLAG := -std=c++11 -Wall -O3

all: $(SRC)
	$(CXX) $(CXXFLAG) -o $(EXC) $?

.PHONY: clean
clean: $(EXC)
	$(RM) $?


