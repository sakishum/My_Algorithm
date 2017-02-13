EXEC = test
#$(wildcard *.cpp)
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h*)
OBJECTS = $(SOURCES:.cpp=.o)
CXXFLAG = -std=c++11 -Wall 

all: $(EXEC)

$(EXEC): $(OBJECTS) $(HEADERS)
	$(CXX) $(CXXFLAG) $(OBJECTS) -o $(EXEC)
 
%.o: %.cpp $(HEADERS) 
	$(CXX) $(CXXFLAG) -c $< -o $@
 
.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJECTS) *.o
