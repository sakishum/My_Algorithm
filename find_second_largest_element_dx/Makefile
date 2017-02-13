SRC := $(wildcard *.cpp)
EXC := test
OBJ := $(SRC:.cpp=.o)
HEAD := $(wildcard *.h*)
CXX := g++-4.7
FLAG := -g -Wall -std=c++11

all: $(EXC)

$(EXC): $(OBJ) $(HEAD)
	$(CXX) $(FLAG) $? -o $@

%.o: %.cpp $(HEAD)
	$(CXX) $(FLAG) -c $< -o $@

.PHONY: clean
clean: $(EXC) $(OBJ)
	$(RM) $?
