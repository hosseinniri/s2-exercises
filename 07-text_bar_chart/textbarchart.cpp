#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<int> barValue;
    for (int i = 1; i < argc; i++)
    {
        std::string argvalue{argv[i]};
        int intvalue{std::stoi(argvalue)};
        barValue.push_back(intvalue);
    }

    int max{*std::max_element(barValue.begin(), barValue.end())};
    int min{*std::min_element(barValue.begin(), barValue.end())};

    int y_range{max - min + 1};
    int x_range{argc};

    std::cout << "^\n";
    for (int j = max - 1; j >= 0; j--)
    {
        std::cout << "|";
        for (int i = 0; i < x_range - 1; i++)
        {

            if ((barValue[i] - (j) > 0))
            {
                std::cout << "#";
            }
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "+";
    for (int i = 0; i < x_range-1; i++)
        std::cout << "#";
    std::cout << "\n";

    for (int j = 0; j > min; j--)
    {
        std::cout << "|";
        for (int i = 0; i < x_range - 1; i++)
        {
            if ((barValue[i] - (j) < 0))
            {
                std::cout << "#";
            }

            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "v";

    return 0;
}