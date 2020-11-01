#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int check_gate(std::string gate, int a, int b)
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
    //and, nand, or, nor, xor,
};

int main()
{

    std::ifstream f("input.txt");
    std::string line;

    while (std::getline(f, line))
    {
        std::string gate;
        int a, b, result, end;
        int tab[100];
        char dash; // to absorb the '-' separator

        std::istringstream ss(line);

        ss >> gate >> a >> b >> result;

        if (gate == "IN:")
        {
            tab[a] = 0;
            tab[b] = 1;
            std::cout << gate << "\t" << a << "\t" << b << "\n";
        }
        else if (gate == "OUT:")
        {
            end = a;
            std::cout << gate << "\t" << end << "\n";
        }
        else
        {
            ////////////////////////////////////
            tab[result] = check_gate(gate, tab[a], tab[b]);
            if (tab[result] == 404)
            {
                std::cout << "ERROR! GATE " << gate << " NOT FOUND!";
                return 0;
            }

            std::cout << gate << "\t \t" << a << ": " << tab[a] << "\t" << b << ": " << tab[b] << "\t" << result << ": " << tab[result] << "\n";
        };
    }
}