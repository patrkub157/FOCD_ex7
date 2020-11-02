#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int check_gate(std::string gate, int a, int b) //function for chceking and calculating gates
{
    if (gate == "AND")
    {
        if (a && b == 1)
        {
            return 1;
        }
        return 0;
    }
    else if (gate == "NAND")
    {
        if (a && b == 1)
        {
            return 0;
        }
        return 1;
    }
    else if (gate == "OR")
    {
        if (a | b == 1)
        {
            return 1;
        }
        return 0;
    }
    else if (gate == "NOR")
    {
        if (a && b == 0)
        {
            return 1;
        }
        return 0;
    }
    else if (gate == "XOR")
    {
        if (a && b == 0 | 1)
        {
            return 0;
        }
        return 0;
    }
    else
        return 404;
};

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

int main()
{
    std::string circuit, inputs, output;
    std::cout << "Write the name of the input file with circuit (.txt): ";
    std::cin >> circuit;
    std::cout << "\n";
    std::cout << "Write the name of the input file with inputs (.txt): ";
    std::cin >> inputs;
    std::cout << "\n";
    std::cout << "Write the name of the otput file (.txt): ";
    std::cin >> output;
    std::cout << "\n";

    std::ifstream f(circuit + ".txt");
    std::string line;
    if (!std::getline(f, line))
    {
        std::cout << "Empty or not existing circuit file " + circuit + ".txt";
        return 0;
    }
    std::ifstream sf(inputs + ".txt");
    std::string sline;
    if (!std::getline(sf, sline))
    {
        std::cout << "Empty or not existing inputs file " + inputs + ".txt";
        return 0;
    }

    write(circuit, inputs, output);
    std::cout << "File created :) ";
    return 0;
}