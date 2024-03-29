
I introduced the idea of a Stack and Queue in lecture yesterday.

There are abstract base classes for these in the shaffer/ directory,
in the files stack.h and queue.h.

While in the 2100 directory:
```bash
files=($(ls ./shaffer/| grep -E '(queue|stack)'))
for f in "${files[@]}"; 
do 
    echo "Copying $PWD/$(basename $f) to ./lab03/$f"
    cp "$PWD/shaffer/$(basename $f)" "./lab03/$f"
done
```

You'll find array-based and link-based implementations for these 
base classes in the files astack.h, aqueue.h, lstack.h, and lqueue.h.

(1) Shaffer Exercise 4.19, p. 148.

A common problem for compilers and text editors is to determine if the
parentheses (or other brackets) in a string are balanced and properly nested.
For example, the string “((())())()” contains properly nested pairs of
parentheses, but the string “)()(” does not, and the string “())” does not
contain properly matching parentheses.

(a) Implement an algorithm that returns true if a string contains properly
nested and balanced parentheses, and false otherwise. Use a stack to keep
track of the number of left parentheses seen so far. You can use
an instance of either AStack or LStack in your code.
Hint: At no time while scanning a legal string from left to right
will you have encountered more right parentheses than left parentheses.

(b) Implement an algorithm that returns the position in the string of the
first offending parenthesis if the string is not properly nested and balanced.
That is, if an excess right parenthesis is found, return its position; if
there are too many left parentheses, return the position of the first
excess left parenthesis. Return -1 if the string is properly balanced and
nested. Use a stack to keep track of the number and positions of left
parentheses seen so far.

(2) Shaffer Project 4.1, p. 149.  A "deque" (pronounced "deck") is
like a queue, except that items may be added and removed from both
the front and the rear.  Write either an array-based or link-based
implementation of a deque.



