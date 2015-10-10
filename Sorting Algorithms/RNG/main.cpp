/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.31
*	Purpose: Implementation of main function of RNG
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <random>
#include <ctime>
#include <string>

int main (int argc, char** argv)
{
    std::string s;
    int count;
    int min;
    int max;
    try
    {
        if (argc != 5)
        {
            throw (std::runtime_error("Input Invalid"));
        }
        else
        {
            s = argv[1];
            count = std::stoi (argv[2]);
            min = std::stoi (argv[3]);
            max = std::stoi (argv[4]);
        }
    }
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    std::ofstream output(s);
    output << count << '\n';
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min, max-1);
    int rand = 0;
    for (int i = 0; i < count; i++)
    {
        rand = distribution(generator);
        output << rand << '\n';
    }
    output.close();
    return 0;
}
