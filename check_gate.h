
#pragma once

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