EXEC = test
#$(wildcard *.cpp)
SOURCES = main.cpp
CXX := g++-4.8
CXXFLAG := -std=c++11
HEADERS = $(wildcard *.h*)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS) $(HEADERS)
	$(CXX) $(CXXFLAG) -L/usr/local/Cellar/boost/1.54.0/lib -lpthread -lboost_system -lboost_filesystem-mt -lboost_thread-mt $(OBJECTS) -o $(EXEC)
 
%.o: %.cpp $(HEADERS) 
	$(CXX) $(CXXFLAG) -I/usr/local/Cellar/boost/1.54.0/include -c $< -o $@
 
.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJECTS) *.o
