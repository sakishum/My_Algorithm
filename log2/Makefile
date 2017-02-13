all: log2

log2: CFLAGS = -g -Wall -Werror
log2: main.cpp
	$(CXX) $(CFLAGS) -o $@ $?

.PHONY: clean
clean:
	-$(RM) -rf log2 *.dSYM

