#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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


    std::vector<int> v = barValue;
    std::sort(v.begin(), v.end(), std::greater<int>());
    int z=0;

    std::cout <<"^\n";


    for (int j = 0 ; j < y_range; j++)
    {
        // std::vector<int> maxidx;
        // // std::cout<<"|";
        

        for (int i = 0; i < x_range-1; i++)
        {

            if(barValue[i] == v[0])
            {
                
                // maxidx.push_back(i); 
                std::cout << "#";
            }
            
            else
                std::cout << " ";
            
        }
        v.erase(v.begin());
        std::cout << "\n";
        // if(j==3)
        // {
        //     for(int i=0; i<x_range;i++) 
        //     if(i==0) std::cout<<"+";
        //     else std::cout<< "-";
        // }
   
        
    }
    std::cout <<"v\n";

    return 0;
}