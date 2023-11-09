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
CXXFLAGS=-g -Wall -std=c++20

all : 01-rotate 02-avlfix 03-loop 04-iter 05-avl-set 06-loop-set 

01-rotate : test-rotate.cc bst.h bintree.h avltree.h testing.h
	$(CXX) $(CXXFLAGS) -o 01-rotate test-rotate.cc

02-avlfix : test-avlfix.cc avltree.h bst.h bintree.h testing.h
	$(CXX) $(CXXFLAGS) -o 02-avlfix test-avlfix.cc

03-loop : test-loop.cc bst.h bintree.h avltree.h testing.h
	$(CXX) $(CXXFLAGS) -o 03-loop test-loop.cc

04-iter : test-iter.cc bst.h bintree.h avltree.h avl_set.h testing.h
	$(CXX) $(CXXFLAGS) -o 04-iter test-iter.cc

05-avl-set : test-avl-set.cc avltree.h avl_set.h bst.h bintree.h testing.h
	$(CXX) $(CXXFLAGS) -o 05-avl-set test-avl-set.cc

06-loop-set : test-loop-set.cc avl_set.h bst.h bintree.h avltree.h testing.h
	$(CXX) $(CXXFLAGS) -o 06-loop-set test-loop-set.cc

clean :
	-rm -f 01-rotate 02-avlfix 03-loop 04-iter 05-avl-set 06-loop-set
