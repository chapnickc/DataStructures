
For *next* week's lab (lab11), you'll be analyzing the
efficiency of some graph algorithms. To do this effectively
it will be useful to be able to create some (big) graphs in
memory for testing purposes.  Instead of hard-coding these graphs
edge-by-edge into your main program, it will be better if you
can read the graphs from a file.

Fortunately, there are a number of well-established file formats
that developers use to store graph data, and you'll be able to find
example of (big) graphs online in several of these formats. 
There's a good survey of formats on this page:

https://gephi.org/users/supported-graph-formats/

(this is the list of formats supported by "Gephi", a nice
graph visualization package).

Your job in this lab is to write new methods for the Graph class
that will import *and* export graph data in *at least two*
of these file formats.  So that's at least four methods you'll
need to write.  I'll let you choose the formats you'd like
to support; you should want to base your decision on the complexity
of the format, and whether you're able to find examples of
interesting graphs saved in these formats online, since you'll
need them for next week.

##
I'd suggest a design that passes a reference to an ostream
to the export functions, and a reference to an istream to the
import methods.  

Then, in your main, you can create an
ofstream or ifstream attached to a file and pass that to 
the import/export.  

The point is that there are other kinds
of ostreams/istreams that you might conceivably want to write
to (cout/cin for example!) and this design allows that.

Note that export is slightly easier to write since you can simply
make it a method of Graph.  
Import is trickier since the number of
vertices in the graph gets established once and for all when
the constructor is called.  This means that the _import function
should not be a method_; make it a standalone function, and
create the graph within that function once you know how many
vertices there are. You can check out graphutil.cpp in Shaffer's
code which has a function that imports from a non-standard file
format of his devising (see the *.gph files in ../shaffer for example).

You'll find the Shaffer's abstract base class Graph in
../shaffer/graph.h.  There are child implementations
in grlist.h and grmat.h in case you're curious, but
we shouldn't need those details for this lab, other than
for testing purposes in a main program. Remember that
these are fundamentally *directed graphs*, so you should
have that case in mind when writing your import/export
methods.

It's important to note that Shaffer's Graph class is 
quite stripped-down (reasonably so, for pedagogical reasons). 
It allows us to store an integer weight on each edge, but that's
about it; we don't even have the ability to store a label for
each vertex.  This means that you shouldn't expect to support all
of the "bells and whistles" of the different graph formats
(they typically allow you to store all kinds of
labels, colors, weights, and so on).  When importing from
these files, you can simply ignore the stuff that isn't relevant
(i.e. anything other than the vertex and edge information).
Similarly, when exporting, you'll only be able to output
a very simple file containing the vertex and edge information.

Finally, test, test, test! You'll want to find a collection "real" 
examples of the file formats you choose, and maybe create a few
simple ones as well, representing some simple graphs with, say, 
fewer than 10 vertices.  Make sure you can read these all successfully,
and that you can, for example, do a traversal of the graph and get the
expected result (see section 11.3). Then export the graph to another
file using your export method, re-import that file and see if the
results are the same (this is called "round-tripping").



