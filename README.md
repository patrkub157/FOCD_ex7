(8) DCT

1. A data structure has to accepted by a laboratory instructor before implementation.
2. Source code has to be split into header (_.h) and source (_.cpp) files.
3. All functions have to be commented in the doxygen style.
4. Any permutation of command line switches has to be handled.
5. The program has to accept slightly imperfect input data.
   Write a program that simulates a digital circuit composed of logical gates: and, nand, or, nor, xor,
   xnor, neg. Each gates has two inputs and one output. The only exception is a negation gate that has one
   input.
   1 \----------- \
   ----\ --------- | NAND 2 \
   ------\ -------/----------\
   -------| NAND 5 -----------| NAND.--- 3
   ------/ -------\----------/
   ----/ ----------| NAND 4 /
   6 /------------/
   Input file format: The IN keyword introduces input nodes of a circuit. The OUT keyword introduces input
   nodes of a circuit. Following lines hold logical gates (each gate in a separate line) as:
   hinput nodei hinput nodei houtput nodei
   The circuit presented in the figure above is encoded as a text file:
   IN: 1 6
   OUT: 3
   NAND 1 6 5
   NAND 1 5 2
   NAND 5 6 4
   NAND 2 4 3

   The second input file holds input states. Each line holds a separate set of inputs for which output of the
   circuit is to be elaborated.
   1:0 6:0
   1:0 6:1
   1:1 6:0
   1:1 6:1

   The output file holds elaborated outputs for provided inputs.
   IN: 1:0 6:0 OUT: 3:0
   IN: 1:0 6:1 OUT: 3:1
   IN: 1:1 6:0 OUT: 3:1
   IN: 1:1 6:1 OUT: 3:0

   This is a command line program with switches:
   -u input file with an circuit
   -i input file with inputs
   -o output file with outputs
   Running the program with no parameters prints a short help how to use the program.
