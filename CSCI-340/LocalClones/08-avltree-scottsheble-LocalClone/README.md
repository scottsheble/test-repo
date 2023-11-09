# NIU CSCI 340 Assignment 8
## AVL Binary Search Trees (BST)

### Introduction

The purpose of this assignment is for you to add AVL support to the binary search tree from the previous assignment, and create an STL-style container, `avl_set`, that uses your AVL tree to act like `std::set`.

### Your Task

- You will need to add to your `bst.h`):
   - `predecessor(node)`

- In `avltree.h`, you will implement:
   - `is_avl(root)`
   - `rotate_left(pivot)`
   - `rotate_right(pivot)`
   - `fix_avl_tree(root, node)`

- In `avl_set.h`, you will need to implement all of the methods in `avl_iterator` and `avl_set` classes for which implementations were not already provided.

### Reused Functionality

You were to implement all of the below functions in the previous assignment. If you finished, great. You should use your solution from the previous assignment. If you did not finish them, you're responsible for finishing them now. 

 - For general binary tree functionality (in `bintree.h`).
   - `preorder(root, fn)`
   - `inorder(root, fn)`
   - `postorder(root, fn)`
   - `levelorder(root, fn)`
   - `delete_tree(root)`
   - `height(node)`
   - `count(root)`

 - For dealing with binary search trees (in `bst.h`):
   - `bst_find(root, value)`
   - `bst_insert(root, value)`
   - `bst_remove_value(root, value)`
   - `is_bst(root)`
   - `bst_minimum(root)`
   - `bst_maximum(root)`
   - `successor(node)`

### AVL Binary Search Trees

AVL Trees are a type of dynamically self-balancing binary search tree. They have to follow all of the rules that normal binary search trees, *and* they have an additional rule that the height of the left subtree and the height of the right subtree may differ by at most one in every node of the tree. Forcing this rule to be followed will keep the tree balanced, which has performance benefits.

Insertions and deletions are performed in the same way they would be done in a BST, but whenever you add or remove a node, there's a potential of breaking the height constraint. Your `fix_avl_tree` function is responsible for fixing those problems and ensuring that the tree remains AVL.

### Functions you Implement

Remember, you will be including the files you had from your previous assignment. If you still need to implement one of those functions, check out *that* assignment's `README`.

#### `predecessor(node)`
 - `node` - a pointer to the node in the binary search tree whose successor we would like to find.

**NOTE:** This will work like the `successor` function that you wrote in the previous assignment, but in the opposite direction. 

This function must return a pointer to the node in the binary search tree that would be the *inorder predecessor* to the supplied node, `node`. If the node has no predecessor, then return `nullptr`. Remember that the inorder predecessor is the node that would have been visited *previous* to the current node in an inorder traversal. In a binary search tree, this will be found in the node with the greatest value that is less than the current node's value. If called on binary tree that is *not* a BST, do not expect the values to come out sorted, but iterating over the predecessors is like doing an inorder traversal in reverse.

#### `is_avl(root)`
 - `root` - A pointer to the root of the tree that's being checked.

This function will return true if and only if the AVL tree's balance condition is true for every node in the tree whose root is pointed to by `root`.

This is independent from the check for whether it's a BST or not. Only do the AVL check based on heights, and don't worry about the values of the nodes themselves in this function.
   
#### `rotate_left(pivot)`
- `pivot` - a *reference* to the pointer to the pivot node that the rotation goes through.

This function is responsible for performing the left rotation as discussed during the lecture. No new nodes are created, and the values stay the same, but you will be changing the pointers of the nodes involved to reshape the tree. Make sure you remember to change the `parent` pointers as well.

**NOTE:** `pivot` is a **reference** to a pointer, and you need to make sure that it is actually referencing either the pointer holding the root of the tree, or the `left` or `right` pointer of the pivot node's parent, and not just a copy of the address. If you ignore this, you will have a lot of issues with your tree ending up wrong.

Returns nothing.

#### `rotate_right(pivot)`
- `pivot` - a *reference* to the pointer to the pivot node that the rotation goes through.

This function is responsible for performing the right rotation as discussed during the lecture. No new nodes are created, and the values stay the same, but you will be changing the pointers of the nodes involved to reshape the tree. Make sure you remember to change the `parent` pointers as well.

**NOTE:** `pivot` is a **reference** to a pointer, and you need to make sure that it is actually referencing either the pointer holding the root of the tree, or the `left` or `right` pointer of the pivot node's parent, and not just a copy of the address. If you ignore this, you will have a lot of issues with your tree ending up wrong.

Returns nothing.

#### `fix_avl_tree(root, node)`
- `root` - **REFERENCE** to pointer to the root of the BST
- `node` - pointer to the node where fixing should begin.

Start out at `node` and make sure that the AVL balance condition is not being broken. If it is, perform the rotations necessary to reshape the tree to fix the problem as discussed in this lecture. Whether you fix anything at the current node or not, proceed to each of its parents and do the same thing, all the way to the root.

This algorithm is not difficult, but you will need to remember that `root` is a reference, and needs to be a reference to the actual pointer for the root of the tree, in case a rotation moves another node up to replace the root.

Returns the number of nodes in which a violation of the AVL balance criterion was detected and fixed.

### `class avl_set`

This class will be used to implement a version of the STL `set` container that works based on your AVL trees.

- The template parameter `T` will be the type of data contained by the nodes.
- `root` is a pointer to the root of the AVL tree you're using to contain your data.
- `node_count` is used to track the number of elements currently in your AVL tree set. Thus, you can implement `size()` as an $O(1)$ operation instead of needing to count another way.

Important methods and their meanings:

- `avl_set(InputIterator start, InputIterator end)` - constructs an AVL tree by inserting the values found in the iterator range provided and rebalancing as needed.
- `~avl_set()` - destructor needs to free up the memory allocated for nodes when the `avl_set` is destroyed.
- `begin()`, `end()` - return an `avl_iterator` that points to the corresponding position
- `rbegin()`, `rend()` - use the `std::reverse_iterator` adapter on the `avl_iterator` for the appropriate position these can be used to iterate in reverse.
- `insert(key)` - inserts a new key into your `avl_set`. Duplicate keys are not allowed.
- `erase(key)` - removes any node in your AVL tree that has the given key.
- `count(key)` - counts the number of nodes in your tree that have the given key.
- `size` - returns the number of nodes in the tree. Try to do this in $O(1)$ time.
- `height` - returns the height of the tree.
- `empty` - returns true if and only if there are no nodes in the tree.
- The `is_bst` method checks whether the values of the keys in the tree match the BST condition.
- The `is_avl` method checks whether the tree is balanced according to the AVL balance condition.
- Traversal methods will just be wrappers to call the traversals you already wrote. These will be useful for checking that your tree is the right shape.

When in doubt, the aim is for your methods to behave like the corresponding methods from `std::set`, implemented using the functions you've made to work with AVL trees. You can find that specification here:
[https://en.cppreference.com/w/cpp/container/set](https://en.cppreference.com/w/cpp/container/set)

#### `insert(key)`
- `key` - the key to search for in the AVL tree

Tries to insert `key` into the AVL tree in the appropriate location. Duplicate keys are not allowed, so the insertion of a key that was already present in the tree should fail.

Returns a `std::pair`. The first item of the pair will be an `avl_iterator` referencing the node where the key was placed. The second item of the pair will be a `bool` representing whether the insertion succeeded.

If the insertion fails, the first element must still be an iterator, but it should be an iterator for which `==` comparison with the `end()` iterator would be true.

#### `erase(key)`
- `key` - the key to search for and whose node we wish to remove from the tree

This method should locate the key on your AVL tree and remove it, making sure to fix any imbalances caused by that removal.

Returns the number of elements removed. If duplicate keys were allowed, this would have had the potential of removing multiple, but we are requiring our keys to be unique, so this will end up being `1` on successful erasure of the node, and `0` if it fails.

#### `count(key)`
- `key` - the key to search for

This function searches your AVL tree for the key given, and returns the number of times it is found. We are not allowing duplicate keys to be inserted, so this will be `1` if it's found or `0` if it's not found on your tree.

### `class avl_iterator`

- `pos` - pointer to the node being pointed to by this iterator
- `prev` - if `pos` is becoming `nullptr` because we went off the end of the tree, make sure to set this to the position of the last thing so we can get back onto the tree again. Otherwise keep it `nullptr`.
- `next` - if `pos` is becoming `nullptr` because we went backward past the beginning, make sure to set this to the position of the first thing so we can get back onto the tree again by incrementing from here. Otherwise keep it `nullptr`.

This class is where you implement the bidirectional iterator that will be used by the `avl_set` class. They will be implemented in such a way that iterating over the BST will visit the nodes in the same order as an inorder traversal. The implementation of `rbegin()` in the `avl_set` will require that `--` works on `end()` to get you back on the tree. In other bidirection iterators, using `--` to go past `begin()` and then `++` to get back is undefined behavior, but your implementation should allow it to get back onto the tree on the correct side.

- There are various constructors, but you only need to implement the copy constructor.
- `++` - You need to implement both prefix `++x` and postfix `x++`, which move the iterator to point to the next element.
- `--` - You need to implement both prefix `--x` and postfix `--x`, which move the iterator backward by one.
- `*x` - Dereferencing the iterator should provide a reference to the value at the current position.
- `==` - Comparing two iterators compares their position, not their value.

### Notes

Remember to continue with our routine of creating a `development` branch and making all changes to that branch, leaving `main` entirely alone. This will be necessary to submit the pull request at the end, signaling completion of your program to the graders.

Your work should be done in `bintree.h` and `bst.h`. Do not alter the other files that were provided with the assignment. If you use work from a previous assignment, make sure that you do push the necessary files to the GitHub repo so that they will be there when the grader tries to compile.

You should feel free to create whatever files you want to test things locally, including writing your own simple programs to test small parts on their own, but none of them should end up becoming a part of your remote repo. I actually *encourage* you to write unit test programs for yourself, but they should not be a part of your submission.

**DO NOT ADD OR COMMIT THE EXECUTABLE FILES CREATED WHILE COMPILING.** They are big and we will be compiling anyway.

### Testing

There are a number of testing programs included. These will be used to evaluate the functionality of your implementations of the required functions. Typing `make` will attempt to compile them all, and will succeed to the degree it can with whatever you have implemented at that point.

The table below has a list of the tests available, and they are shown in order from least complex to most complex.

|Order|Test |Purpose  |
|:-:  |:----|:--------------------|
1|`01-rotate` |Builds some known trees with `bst_insert` and tests your rotation functions.
2|`02-avlfix` |Test your `fix_avl_tree` function with some known trees.
3|`03-loop` |Interactive program like `test4` from previous assignment, but using `fix_avl_tree` and `is_avl`.
4|`04-iter` |Shows how bidirectional iterators from other containers work, then tests the ones from your `avl_set`.
5|`05-avl-set` |Inserts, searches for, and removes various values from `set`, `unordered_set` and `avl_set` for comparison.
6|`06-loop-set` |Interactive program like the other, but using the `avl_set` methods to insert/remove/search.

The expected output is contained in the `*.refout` files in the `output/` directory.

### How To Submit
 
Like the other assignments for this semester, we will be doing submissions through GitHub. Make sure you
do all of your development in the `development` branch. You can commit as many times as you need to, but keep in mind that this will grow the size of your repo and you may run up against the quota on turing/hopper if it gets too big.

When you are finished implementing everything required and the test program is working properly, make sure you add, commit, and push the working version to the repo. Once that is done, **SUBMIT** a pull request but **DO NOT ACCEPT IT**. 

### Grading Considerations

  - Does it compile? Does it run? All of the tests should compile and run on turing/hopper with the `Makefile` provided, and points will be deducted for each test that will not compile.
  - Does the output match for all of the tests? I have provided reference output for each of the test programs where such a thing is valid, so you can compare your program's output to what is expected. This output can be found in the files ending in `.refout`.
  - Did you change files you're not allowed to? There are warning messages at the top of several of the files telling you not to make changes. If you make changes to these, you will receive a grade penalty. You can write your own test programs if you'd like, but do not commit them or push them to the server, and make sure the only modifications that make it to GitHub are the required ones.
  - Did you commit/push all of the source code needed to compile your program?
  - Did you indent your code? 
    - Indentation aids in the readability of source code, and if you're not indenting your code blocks, the grader will legitimately dislike you for it. I'm authorizing them to mark you off if you subject them to reading that.
  - Did you document your code?
    - You need a docbox at the top of every one of the files you're required to change including:
      - Your name
      - Your zid
      - Your GitHub ID
      - Your course section
      - A description of what the program does
    - You should add a docbox for every function that you implement, explaining what it does and what each parameter is for.
    - Add other comments inside your code blocks describing what you're doing and why.
    - The use of `doxygen` style comments is encouraged, but not required.
