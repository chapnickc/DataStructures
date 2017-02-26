

# Stacks 

They are used when you are still working on something

((3+3)*(5+7))
we push and 'E' on to the stack to indicate we are ging to parse an arithmetic expression

pushing a strategy for an enemy in a video game

```bash
4   #push
5   #push
+   #  pop
p   # what's on top
9
```

```bash
6
7
+
3
*
p   # gives 39
```

# Stack.h
- Abstract base class for stack
- For stacks it doesnt matter if 
    we use an alist or llist


what should we store as private data.

1.) inherit from alist
2.) inherit from llist 
3.) multiple inheritance w/ llist (java does not allow this)
4.) A wrapper class:
        store llist or alist in private data
```c++
    private: 
        LList<E> data;
    //...
        int length(){data.length()}

        void push(){data.append()}
```



you never want to handle an error in library code

real library code should be able to run in multiple contexts
- mobile
- gui
- command line











