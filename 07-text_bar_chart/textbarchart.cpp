#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::vector<int> barValue;
    int max{0};
    int min{0};
    int max_index{0};
    int min_index{0};
    for (int i = 1; i < argc; i++)
    {
        std::string argvalue{argv[i]};
        int intvalue{std::stoi(argvalue)};
        barValue.push_back(intvalue);
        std ::cout << intvalue << "\n";
        if (intvalue < min)
        {
            min = intvalue;
            min_index = i;
        }
        if (intvalue > max)
        {
            max = intvalue;
            max_index = i;
        }
    }

    std::cout << "min" << min << "\n";
    std::cout << "max" << max << "\n";

    int y_range{max - min + 1};
    int x_range{argc};

    for (int j = max; j >= min; j--)
    {
        // for (int i = 1; i < argc; i++)
        // {
        if(j==0)
        {
            for(int z=0;z<argc;z++) std::cout<<"-";
            std::cout<<"\n";
        }

        
        //  for (int i = 0; i < x_range; i++)
        // {
            
        //     if (barValue[i] < min)
        //     {
        //         min = barValue[i];
        //         min_index = i;
        //     }
        //     if (barValue[i] > max)
        //     {
        //         max = barValue[i];
        //         max_index = i;
        //     }
        // }
        for (int i = 0; i < x_range; i++)
        {

            if (barValue[i] == max)
            {
                std::cout << "#";
                // barValue.assign(i, max);
                break;
            }
            else
                std::cout << " ";
        }
         std::cout << "\n";
    }

    return 0;
}