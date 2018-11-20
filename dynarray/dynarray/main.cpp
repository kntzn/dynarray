#include "darray.h"
#include <list>
#include <iostream>
#include <time.h>

#define echo(msg) std::cout<<msg<<std::endl
#define times(n) for (int _ = 0; _ < n; _++)

int main ()
    {
    darray <int> arr (200);
    std::list <int> lst;

    clock_t start = clock ();

    for (int i = 0; i < 20; i++)
        {
        times (rand () % 10)
            arr.push_back (i);
        times (rand () % 2)
            if (arr.size ())
                arr.pop_back ();
        }

    printf ("tm: %d\n", clock () - start);


    system ("pause");
    }