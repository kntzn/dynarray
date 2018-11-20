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
    for (int i = 0; i < 10; i++)
        arr.push_back (i);
    arr.insert (557, 5);
    for (int i = 0; i < 10; i++)
        printf ("[%d] = %d\n", i, arr [i]);


    printf ("tm: %d\n", clock () - start);


    system ("pause");
    }