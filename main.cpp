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
        int a, b;

        char dash; // to absorb the '-' separator

        std::istringstream ss(line);

        ss >> gate >> a >> b;

        if (gate == "OUT:")
        {
            std::cout << gate << "\t" << a << "\n";
        }
        else

            std::cout << gate << "\t" << a << "\t" << b << "\n";
    }
}