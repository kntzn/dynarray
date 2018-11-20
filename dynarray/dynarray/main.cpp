#include "darray.h"
#include <list>
#include <iostream>
#include <time.h>
#include <vector>

#define echo(msg) std::cout<<msg
#define times(n) for (int _ = 0; _ < n; _++)

#define N_TESTS 1000000
#define variable auto

int main ()
    {
    variable n_tst = 10;
    
    darray <int> arr (20);
    std::vector <int> vec;
    
    
    echo ("TST 0: only push_back");
    
    
    while (n_tst < N_TESTS)
        {
        darray <int> arr (20);
        std::vector <int> vec;

        clock_t start = clock ();

        times (n_tst)
            vec.push_back (1337);


        n_tst += 10000;

        echo (clock () - start << ", ");
        }
    

    system ("pause");
    }