################################################################################
#  This is the Makefile provided for the assignment. You can compile the test  #
# program by typing "make" at the command line. Running make without any       #
# parameters will try to compile all the tests. If you'd like to compile less  #
# than that, you can type the name of the target you'd like to make, i.e.      #
#   % make test1                                                               #
#                                                                              #
#  You can feel free to add NEW rules to this file in your local copy of the   #
# repo. For instance, if you want to write your own simpler test program that  #
# tests only a portion of the container. However, you should not commit any of #
# those changes; keep them local, and...                                       #
#                                                                              #
# DO NOT MAKE CHANGES TO ANY OF THE RULES PROVIDED!                            #
################################################################################
CXX=g++
CXXFLAGS=-g -Wall -std=c++2a -fconcepts

all : simple loadgraph

simple : simple.cc graph.h config.h
	$(CXX) $(CXXFLAGS) -o simple simple.cc

loadgraph : loadgraph.cc graph.h config.h
	$(CXX) $(CXXFLAGS) -o loadgraph loadgraph.cc

clean :
	-rm -f simple loadgraph
