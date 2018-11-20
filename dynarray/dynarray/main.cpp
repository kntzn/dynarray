#include "darray.h"
#include <vector>
#include <iostream>

#define echo(msg) std::cout<<msg<<std::endl

int main ()
    {
    darray <int> arr (5);

    for (int i = 0; i < 10; i++)
        {
        bool res = arr.push_back (i);
        }
    
    echo ("\n\n");
    for (int i = 0; i < 10; i++)
        {

        std::cout << arr [i] << std::endl;
        }
    //std::cout << arr [2] << std::endl;

    system ("pause");
    }