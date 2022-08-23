#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


int main(int argc, char* argv[])
{
    double sample_number = stod(argv[1]);
    int table_size;
    int resulution_bit_number = stoi(argv[2]);
    int sin_max = (pow(2,resulution_bit_number)-1)/2;

    table_size = sample_number;

    int sine_table[table_size];
    int cosine_table[table_size];

    bool include_cosine = false;

    cout << "Abs max of sin :" << sin_max;
    double index;
    
        if(argc > 3 )
        {
            if(argv[3][0] == 'c')
        {
            cout << "\n table including cosine";
            include_cosine = true;
        }
        else
        {
            cout << "\n invalid input";
            return 0;
        }

        }
        


    for (int i = 0; i < sample_number; i++)
    {
        index =i;
        //std :: cout << "\n angle :" << (i/sample_number);
        
        
        sine_table[i]=sin_max * sin ((index/sample_number)*(2*M_PI));
        cout << "\n >>" << left << setw(40)<< sine_table[i] << setbase(10);
        if(include_cosine)
        {
            cosine_table[i]=sin_max * cos ((index/sample_number)*(2*M_PI));
            cout << " | " << cosine_table[i] ;
            
        }
        

    }
    

   
   
    
   return 0;    
}