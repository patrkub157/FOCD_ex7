#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "write.h"

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