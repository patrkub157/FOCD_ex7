
#pragma once
#include "check_gate.h"

int calc(int a_value, int b_value, std::string circuit)
{
    std::ifstream f(circuit + ".txt");
    std::string line;

    while (std::getline(f, line)) //while functions one for each line in .txt file
    {
        std::string gate; // gate read from file
        int a, b, result, end, endresult;
        int tab[100]; // a table for 0,1 numbers

        std::istringstream ss(line);

        ss >> gate >> a >> b >> result; //read values from file

        if (gate == "IN:")
        {
            tab[a] = a_value;
            tab[b] = b_value;
            //std::cout << gate << "\t" << a << "\t" << b << "\n"; // For cout print
        }
        else if (gate == "OUT:")
        {
            end = a;
            //std::cout << gate << "\t" << end << "\n"; // For cout print
        }
        else
        {

            tab[result] = check_gate(gate, tab[a], tab[b]); // function for finding the right gate and get the result
            if (tab[result] == 404)                         //throw an error if gate does not exist
            {
                std::cout << "ERROR! GATE " << gate << " NOT FOUND!";
                return 404;
            }

            //std::cout << gate << "\t \t" << a << ": " << tab[a] << "\t" << b << ": " << tab[b] << "\t" << result << ": " << tab[result] << "\n"; //line for checking if program works fine

            if (end == result) //end program if we know the result
            {
                return tab[result];
            }
        };
    };
    return 404;
};