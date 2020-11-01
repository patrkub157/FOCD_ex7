#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{

    std::ifstream f("input.txt");
    std::string line;

    while (std::getline(f, line))
    {
        std::string gate;
        int a, b, result, end;

        char dash; // to absorb the '-' separator

        std::istringstream ss(line);

        ss >> gate >> a >> b >> result;

        if (gate == "IN:")
        {
            std::cout << gate << "\t" << a << "\t" << b << "\n";
        }
        else if (gate == "OUT:")
        {
            end = a;
            std::cout << gate << "\t" << end << "\n";
        }
        else
            ////////////////////////////////////
            std::cout << gate << "\t" << a << "\t" << b << "\t" << result << "\n";
    }
}