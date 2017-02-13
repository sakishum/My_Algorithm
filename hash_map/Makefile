CFLAGS = -std=c++11 -O2 -Wall
OBJECT = main.o

all: obj test

obj: main.cpp
	$(CXX) -c -o $(OBJECT) $? 

test: $(OBJECT)
	$(CXX) $(CFLAGS) -o $@ $?
	$(RM) $?

.PHONY : clean
clean:
	$(RM) test
