#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long int arrln;
#define SZ_DEFAULT 1000
#define msgassert(expression, message) { if (!expression) printf ("%s\n", message); \
                                       (void)((!!(expression)) || \
                                       (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0)); }

template <typename dataType> class darray
    {
    private:
        bool ok;
        bool debug_output;
        arrln currentLen, allocLen;
        dataType* container;

    public:
        // Constructor and destructor
        darray (arrln Size = STK_SZ_DEFAULT);
        ~darray ();

        // Getters
        dataType & back ();
        dataType & front ();

        // Modifiers
        //bool push (dataType value);
        //bool pop ();
        //bool shrink_to_fit ();

        // Size getters
        arrln size ();
        bool empty ();
    };

template<typename dataType>
inline darray<dataType>::darray (arrln Size)
    {
    // Default values
    ok = true;
    debug_output = false;
    currentLen = 0;
    allocLen = Size;
    
    msgassert (allocLen, "Size of array must be greater than zero\n");
    container = (dataType*) calloc (allocLen, sizeof (dataType));

    if (container == nullptr)
        {
        ok = false;
        printf ("Failed to allocate memory\n");
        }
    else
        printf ("Allocated %d bytes at %d\n", allocLen*sizeof (dataType), int (container));

    }

template<typename dataType>
inline darray<dataType>::~darray ()
    {
    free (container);
    }

template<typename dataType>
inline dataType & darray<dataType>::back ()
    {
    msgassert (currentLen, "Unable to back ():\n\tArray is empty\n");
    return container [currentLen - 1];
    }

template<typename dataType>
inline dataType & darray<dataType>::front ()
    {
    msgassert (currentLen, "Unable to back ():\n\tArray is empty\n");
    return container [0];
    }

template<typename dataType>
inline arrln darray<dataType>::size ()
    {
    return currentLen;
    }

template<typename dataType>
inline bool darray<dataType>::empty ()
    {
    return (currentLen == 0);
    }

#undef SZ_DEFAULT