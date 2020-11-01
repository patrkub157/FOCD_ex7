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

int calc()
{
    std::ifstream f("input.txt");
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

            tab[result] = check_gate(gate, tab[a], tab[b]); // function for finding the right gate and get the result
            if (tab[result] == 404)                         //throw an error if gate does not exist
            {
                std::cout << "ERROR! GATE " << gate << " NOT FOUND!";
                return 404;
            }

            std::cout << gate << "\t \t" << a << ": " << tab[a] << "\t" << b << ": " << tab[b] << "\t" << result << ": " << tab[result] << "\n"; //line for checking if program works fine

            if (end == result) //end program if we know the result
            {
                return tab[result];
            }
        };
    };
    return 404;
};

int main()
{
    return calc();
}