#include "darray.h"
#include <vector>
#include <iostream>

int main ()
    {
    darray <int> arr (10);

    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.size () << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    std::cout << arr.push_back (10) << std::endl;
    arr.shrink ();
    std::cout << arr.size () << std::endl;

    //std::cout << arr [2] << std::endl;

    system ("pause");
    }