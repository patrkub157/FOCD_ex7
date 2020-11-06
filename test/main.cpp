#include <iostream>

int main(int argc, char *argv[])
{
    //std::cout << "Value in argc: " << argc << std::endl;

    std::string input_file, output_file;

    for (int i = 0; i < argc; i++)
    {
        // std::cout << argv[i] << std::endl;
        if (std::string(argv[i]) == "-i")
        {
            input_file = argv[i + 1];
        }

        if (std::string(argv[i]) == "-o")
        {
            output_file = argv[i + 1];
        }
    }

    std::cout << "Input file: " << input_file << std::endl;
    std::cout << "Output file: " << output_file << std::endl;

    return 0;
}