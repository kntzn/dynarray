#include "darray.h"
#include <vector>
#include <iostream>

int main ()
    {
    darray <int> arr (10);
    
    //std::vector <int> vec;
    std::cout << arr.back () << std::endl;

    system ("pause");
    }