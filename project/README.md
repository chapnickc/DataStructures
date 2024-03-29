This week's lab is essentially Project 11.3 from Shaffer:

"While the underlying implementation (whether adjacency matrix or
adjacency list) is hidden behind the graph ADT, these two implementations
can have an impact on the efficiency of the resulting program. For Dijkstra's
shortest paths algorithm, two different implementations were given in
Section 11.4.1 that provide different ways for determining the next
closest vertex at each iteration of the algorithm. The relative costs
of these two variants depend on how sparse or dense the graph is.
They might also depend on whether the graph is implemented using an
adjacency list or adjacency matrix.

Design and implement a study to compare the effects on performance for
three variables: 
 1. the two graph representations (adjacency list and adjacency matrix); 

2. the two implementations for Dijkstra's shortest paths algorithm 
       (searching the table of vertex distances or using a priority queue to 
       track the distances), and 

3. Sparse vs Dense graphs. Be sure to test your implementations 
    on a variety of graphs that are sufficiently large to generate meaningful times."

Some hints/comments:

1.  There are implementations of both variants of Dijkstra's algorithm,
for both adjacency list and adjacency matrix Graphs in Shaffer's code.  
See the files __grdijkl1.cpp, grdijkl2.cpp, grdijkm1.cpp, and grdijkm2.cpp.__
These programs are designed to read the custom ".gph" file format;
you'll instead want to read some real world graphs using the import
methods you wrote for last week's lab.

2. It's worth mentioning that you can also produce your own graphs
programmatically, without reading them from a file.  
For example, it might be interesting to test the run-time on 
a complete graph on n vertices for large values of n.  
It's a bit silly to read such a graph from a file when 
you can produce it with a tiny bit of code using the methods 
in the Graph ADT.  Similarly, you could produce a
"linear" graph with n vertices in which the only edges join
vertex i to vertex i+1, for all i.  Or, a complete binary tree of
depth k, etc. etc.

3. This is the only lab of the semester for which you're required to
turn something in.  What I'm expecting from each individual is a
written report on the experiment you ran, and the results you obtained.
\
This means you should tell me about the different graphs you tested
(with URLs for any that you found online), and report the run-times
for all of the different cases, probably in tabular form.  
\
Graphing the run-times as a function of the size of the graph is probably a good
idea too, if possible. 

You should write a paragraph or two on any
conclusions you're able to draw from your experiments.

You should turn in any code that you wrote or modified along with
your report.  This will presumably include your import/export function
from last week, any code for creating graphs programmatically as 
in (2) above, and whatever main() programs you wrote or modified to 
compute run times.

(4) This is intended to be an individual project.  Some of you
collaborated on the import/export functions from last week's lab
and that's perfectly fine.  But any code specifically for this lab,
and all experiments, must be your own work.

Due Date: 11:59PM CST Wednesday, November 30th.
