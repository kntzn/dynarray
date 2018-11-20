#include "darray.h"
#include <vector>
#include <iostream>

#define echo(msg) std::cout<<msg<<std::endl

int main ()
    {
    darray <double> arr (5);

    for (int i = 0; i < 8; i++)
        arr.push_back (i);
        
    
    echo ("\n\n");
    for (int i = 0; i < 10; i++)
        {
        printf ("%f\n", double (arr [i]));
        }
    //std::cout << arr [2] << std::endl;

    system ("pause");
    }