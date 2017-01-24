# Lab 00
# Chad Chapnick
# Date:  Januare 23 2017

# Notes:
[use sizeof(array)/sizeof(array[0]) to find the length of an array](http://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array)

[Great article on const](http://duramecho.com/ComputerInformation/WhyHowCppConst.html)

cv-qualifiers (constant/volatile)


# Prompt
You'll see files Vector3D.h and Vector3D.cpp in this folder.

(1) Verify that this compiles correctly to an object file, as follows:
```bash
   g++ -c Vector3D.cpp
```

This should run with no errors and produce a file Vector3D.o.

(2) Note that Vector3D is not "const-correct". Decide which 
methods should be const and which arguments to methods should
be const. Make it so, and recompile as in (1).

(3) Write a main program that creates an instance of type Vector3D.
Loop from i=0 to i=2, prompt the user to enter a number
each time through the loop, and set the coordinates of the 
Vector3D to the values that are input.

(4) Write a second loop in the main program that checks each
coordinate to see if it is negative, and if it is, changes 
that coordinate to be positive (multiply it by -1). 
Compile and convince yourself that your code works.

(5) You might decide that the operation in step (4), ensuring
that each coordinate of the vector is positive, is something
you do frequently enough that you'd like to make it a
method of Vector3D.  Do that, by adding a method

void absoluteValue();

to Vector3D.h, and along with its implementation

void Vector3D::absoluteValue() {

// .... 
}

in Vector3D.cpp.

Then modify the main to simply call the normalize method.

(6) Extra time?  What additional methods might be useful for
a general Vector3D class?  Decide on their names, return types,
argument types, and whether they are const methods or not, and 
add them to the Vector3D.h file.  Implement them in Vector3D.cpp
i
