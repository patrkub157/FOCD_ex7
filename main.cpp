
#include "main.h"

int main(int argc, char *argv[])
{

   
    std::string circuit_file = "", input_file = "", output_file = "";

    for (int i = 0; i < argc; i++)
    {
        //std::cout << "1. " << argv[i] << std::endl;
        if (std::string(argv[i]) == "-i")
        {
            input_file = argv[i + 1];
        }

        if (std::string(argv[i]) == "-o")
        {
            output_file = argv[i + 1];
        }
        if (std::string(argv[i]) == "-u")
        {
            circuit_file = argv[i + 1];
        }
    }

    if (input_file == "" || circuit_file == "" || output_file == "")
    {
        std::cout << "##################################################################" << std::endl;
        std::cout << "You need to declare input, circuit and output files in flags. " << std::endl;
        std::cout << "-u file_name -input file with an circuit" << std::endl;
        std::cout << "-i file_name -input file with inputs" << std::endl;
        std::cout << "-o file_name -output file with outputs" << std::endl;
        std::cout << "##################################################################" << std::endl;
        return 0;
    }

    // std::cout << "Input file: " << input_file << std::endl;
    // std::cout << "Output file: " << output_file << std::endl;

    write(circuit_file, input_file, output_file);
    std::cout << "File created :) ";
    return 0;
}