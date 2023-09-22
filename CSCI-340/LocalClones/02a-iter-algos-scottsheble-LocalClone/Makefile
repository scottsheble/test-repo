CXX=g++
CXXFLAGS=-Wall -g -std=c++20

all: do_ints do_strings


do_ints:  do_ints.cc assign2-algos.h
	$(CXX) $(CXXFLAGS) do_ints.cc -o do_ints

do_strings:  do_strings.cc assign2-algos.h
	$(CXX) $(CXXFLAGS) do_strings.cc -o do_strings

test_ints: do_ints
	./do_ints

test_strings: do_strings
	./do_strings

clean :
	-rm -f do_ints do_strings
