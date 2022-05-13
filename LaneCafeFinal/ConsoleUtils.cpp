#include "ConsoleUtils.h"
#include <iostream>
#include <string>

#pragma once

namespace ConsoleUtils
{
    void Print(std::string s)
    {
        std::cout << s << std::endl;
    }
    void Print()
    {
        Print("");
    }
    void WaitForKeyPress()
    {
        Print("[Press enter to continue...]");
        std::cin.get();
        //Print();
    }
    std::string ReadString()
    {
        std::string s = "";
        std::cin >> s;
        return s;
    }
    int ReadInt()
    {
        int i = 0;
        std::cin >> i;
        return i;
    }
    bool ReadBool()
    {
        std::string s = ReadString();

        if (s == "y" || s == "Y" || s == "1") return true;
        return false;
    }

    int GetInputInt(int min, int max)
    {
        Print("[ " + std::to_string(min) + " - " + std::to_string(max) + " ]: ");
        int ind = ReadInt();

        if (ind <= max && ind >= min)
        {
            return ind;
        }
        else
        {
            Print("[Error, input integer between the min and max value.]");
            return(GetInputInt(min, max));
        }
    }

    bool GetInputBool()
    {
        Print("[ Y / N ]: ");
        return ReadBool();
    }
}