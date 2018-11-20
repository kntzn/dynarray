#include "darray.h"
#include <list>
#include <iostream>
#include <time.h>

#define echo(msg) std::cout<<msg<<std::endl

int main ()
    {
    darray <int> arr (200);
    std::list <int> lst;

    clock_t start = clock ();

    for (int i = 0; i < 2000; i++)
        {
        arr.push_back (i);
        arr.pop_back ();
        arr.push_back (i);
        }

    for (int i = 0; i < 1000; i++)
        echo (arr [i]);


    printf ("tm: %d\n", clock () - start);


    system ("pause");
    }