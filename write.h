
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "calc.h"

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

        if (calc(a_value, b_value, circuit) == 404)
            return 0;

        myfile << "IN: " << a << colon << a_value << "\t" << b << colon << b_value << "\t"
               << "OUT: " << calc(a_value, b_value, circuit) //return value
               << "\n";
    };
    myfile.close();
    return 0;
}