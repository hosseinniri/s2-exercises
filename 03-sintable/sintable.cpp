#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    // if(!isdigit(argv[1][0]) || !isdigit(argv[2][0]))
    // {
    //     cout << "\n invalid input argumant [arg[1] and arg[2] must be number.";
    //     return 0;
    // }
    if(argc < 3)
    {
        cout << "Invalid input :number of argumants are not enough [at least 2 inputs requierd]";
        return 0;
    }
        int sample_number ;
         int resulution_bit_number ;
    try
    {
         sample_number = stod(argv[1]);
         resulution_bit_number = stoi(argv[2]);
    }
    catch(const std::exception& e)
    {
        cout << "error was in :";
        std::cerr << e.what() << '\n';
        cout << "Invalid input :[arg[1] and arg[2] must be number]."<< '\n';
        return 0;
    }
    
   

    int table_size;
    int sin_max = (pow(2, resulution_bit_number) - 1) / 2;
    table_size = sample_number;

    int sine_table[table_size];
    int cosine_table[table_size];

    bool include_cosine = false;

    


    // cout << "Abs max of sin :" << sin_max;
    double index;

    
    if (argc > 3)
    {
        string arg3 = argv[3];
        if (arg3 == "c")
        {
            cout << "table including cosine" << "\n" ;
            include_cosine = true;
        }
        else
        {
            cout << "Invalid input [Enter 'c' for cosine table generating ]" << "\n" ;
            return 0;
        }
    }


    for (int i = 0; i < sample_number; i++)
    {
        index = i;
        // std :: cout << "\n angle :" << (i/sample_number);

        sine_table[i] = sin_max * sin((index / sample_number) * (2 * M_PI));
        cout << ">>" << left << setw(40) << sine_table[i] << setbase(10) ;
        if (include_cosine)
        {
            cosine_table[i] = sin_max * cos((index / sample_number) * (2 * M_PI));
            cout << " | " << cosine_table[i] << "\n";
        }
        else
        {
            cout << "\n";
        }
    }

    return 0;
}