
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "calc.h"

//
// Function for reading from input states and writing values into a output file
//

int write(std::string circuit, std::string inputs, std::string output)
{

    std::ifstream f(inputs + ".txt");
    std::string line;

    std::ofstream myfile;
    myfile.open(output + ".txt");

    while (std::getline(f, line))
    {
        int a, a_value, b, b_value;

        char colon; // to absorb the ':' separator

        std::istringstream ss(line);

        ss >> a >> colon >> a_value >> b >> colon >> b_value; //line for reading values from structures file

        std::cout << a << colon << a_value << "\t" << b << colon << b_value << "\n"; // For cout print

        if (calc(a_value, b_value, circuit) == 404) // write an error if calc() returns 404
        {
            std::cout << "There was an error in the circuit txt file check if you have IN OUT values and correct numbers for gates ";
            return 0;
        }

        myfile << "IN: " << a << colon << a_value << "\t" << b << colon << b_value << "\t"
               << "OUT: " << calc(a_value, b_value, circuit) //return outcome from calc()
               << "\n";
    };
    myfile.close(); //close the output file
    return 0;
}