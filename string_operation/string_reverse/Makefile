SRC:=$(wildcard *.cpp)
EXC:=test
HEAD=$(wildcard *.h*)
OBJ:=$(SRC:.cpp=.o)
CXX:=g++-4.7
FLAG:=-g -Wall -std=c++11

all: $(EXC)

$(EXC):$(OBJ) $(HEAD)
	$(CXX) $(FLAG) $? -o $@

%o:%.cpp $(HEAD)
	$(CXX) $(FLAG) -c $< -o $@

.PHONY:clean
clean: $(EXC) $(OBJ)
	$(RM) $?
