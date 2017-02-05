The starting point for this lab is the same code from last week's lab,
Vector3D.h and Vector3D.cpp in the folder ../lab00.

(1) Write a VectorND class that can be of any dimension, using Vector3D
as a model.  You can copy those files here as follows:

    cp ../lab00/Vector3D.h ./VectorND.h
    cp ../lab00/Vector3D.cpp ./VectorND.cpp

and then globally search/replace "Vector3D" with "VectorND".

The methods will need to change slightly.  The old constructor

Vector3D()

should now be:

VectorND(int n)

where the dimension of the vector is passed as an argument.  You'll
need to use the "new" operator in the body of the constructor to 
allocate memory for the array.  You'll also need to add a destructor
to clean up this memory (remember: "a delete for every new"!)

You can either kill the 

Vector3D(float x, float y, float z) 

constructor (since it's hard to generalize this to n dimensions)
or change it so that it takes a float[] along with the dimension.

(2) Last week you wrote a small main program that tested Vector3D.
Imagine that you'd spent 5 years working on that main program, and 
it ended up being over a million lines of code.  That code makes 
many references to Vector3D's all over the place.  

Now, in the meantime you've learned about the "new" and "delete" 
operators and dynamic memory allocation in C++.  You think these
are cool ideas, so you'd like to use them in place of the static array
used in Vector3D.  How would you do this?  Here are some
options to consider:

(a) "Port" the million line main program so that everywhere you create 
a Vector3D, you now create a VectorND (and pass n=3 to the constructor),
and come up with a suitable replacement for anywhere you used
the Vector3D(float,float,float) constructor.

(b) Rewrite the internals of Vector3D to use a dynamic array;
don't bother using VectorND at all.

(c) Rewrite Vector3D so that it stores an instance of VectorND
as private data, initialized to be dimension 3. (For this,
it's useful to Remember that it's possible to call the constructor
of private attributes from a class constructor using the "colon" syntax.)

(d) Use inheritance to rewrite Vector3D as a child of VectorND.

(e) Something else altogether... anything goes!

Discuss the pros and cons of each with your partner.
Then pick the approach you think is best, and implement it.
Make sure the main program from last week still works
as expected. Of course, it wasn't a million lines long, but you
should think through what would be entailed if it had been
(I mean this as an argument against approach (a)!)

(3) If you have extra time, try implementing one of the other 
approaches as well.
