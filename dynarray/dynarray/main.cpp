#include "darray.h"
#include <list>
#include <iostream>
#include <time.h>

#define echo(msg) std::cout<<msg<<std::endl

#define TST_VAL 50000

int main ()
    {
    darray <int> arr (5);
    std::list <int> lst;

    clock_t start = clock ();

    for (int i = TST_VAL; i < 2* TST_VAL; i++)
        arr.push_back (i);
    
    
    //for (int i = TST_VAL - 1; i >= 0; i--)
      //  arr.push_front (i);

    printf ("arr: %d\n", clock () - start);

    start = clock ();

    for (int i = TST_VAL; i < 2 * TST_VAL; i++)
        lst.push_back (i);


    //for (int i = TST_VAL - 1; i >= 0; i--)
      //  lst.push_front (i);

    printf ("lst: %d\n", clock () - start);


    //std::cout << arr [2] << std::endl;

    system ("pause");
    }