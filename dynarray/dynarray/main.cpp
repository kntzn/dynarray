#include "darray.h"
#include <list>
#include <iostream>
#include <time.h>
#include <vector>

// compile with -Werror

#define echo(msg) std::cout<<msg<<"\n"

#define and_str <<

#define iterate(begin, end) for (int iterator = begin; iterator < end; iterator++)
#define times(n) for (int _ = 0; _ < n; _++)

#define N_TESTS 1000000
#define variable auto

int main ()
    {
    
    darray <int> arr (20);
    std::vector <int> vec;
    
    variable n_tst = 10;

    iterate (0, n_tst)
        arr.push_back (iterator);
    
    iterate (0, arr.size ())
        echo (iterator and_str " = " and_str arr [iterator]);

    arr.erase (0);
    echo ("erased");


    iterate (0, arr.size ())
        echo (iterator and_str " = " and_str arr [iterator]);

    system ("pause");
    }