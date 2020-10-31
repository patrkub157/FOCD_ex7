# FOCD_ex7

Fundamentals of Computer Programming

(7) Bipartite

1. A data structure has to accepted by a laboratory instructor before implementation.
2. Source code has to be split into header (_.h) and source (_.cpp) files.
3. All functions have to be commented in the doxygen style.
4. Any permutation of command line switches has to be handled.
5. The program has to accept slightly imperfect input data.
   Write a program that checks if an undirected graph is bipartite. Format of an input file with a graph:
   • Each edge is written in one line as numbers of two vertices connected by the edge.
   • Empty lines are allowed.
   • Redundant white chars are allowed in lines.
   Example of an input file:
   3 2
   12 3
   2 5
   5 3
   3 12
   The program write into an output file: the graph in question and a message whether the graph is
   bipartite. If yes, the program lists vertices in both groups.
   This is a command line program with switches:
   -i input file with edges of a graph
   -o output file
   Running the program with no parameters prints a short help how to use the program.
