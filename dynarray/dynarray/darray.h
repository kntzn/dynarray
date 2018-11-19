#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long int arrln;
#define STK_SZ_DEFAULT 1000
#define NAN std::numeric_limits <double>::quiet_NaN()


template <typename dataType> class darray
    {
    private:
        bool extendable, debug_output;
        arrln len, currentLen;
        dataType* container;

        bool extend ();

    public:
        // Constructor and destructor
        darray (arrln Size = STK_SZ_DEFAULT, bool resizeable = false, bool debug = true);
        ~darray ();

        // Getters
        dataType & top ();

        // Modifiers
        bool push (dataType value);
        bool pop ();
        bool shrink_to_fit ();

        // Size getters
        arrln size ();
        bool empty ();
    };



template<typename dataType>
inline bool darray<dataType>::extend ()
    {
    // Memory allocation
    dataType* newContainer = (dataType*)calloc (2 * len, sizeof (dataType));
    if (newContainer != nullptr)
        {
        for (int i = 0; i < len; i++)
            newContainer [i] = container [i];

        free (container);

        container = newContainer;

        len *= 2;

        return true;
        }
    else
        printf ("Failed to extend darray:\n\tFailed to allocate memory\n");

    return false;
    }

template<typename dataType>
inline darray<dataType>::darray (arrln Size, bool resizeable, bool debug)
    {
    extendable = resizeable;
    len = Size;
    currentLen = 0;
    debug_output = debug;

    if (debug_output)
        printf ("Stk debug enabled\n");

    if (len == 0)
        {
        printf ("Failed to init darray:\n\tStack size must be greater than zero\n");
        return;
        }

    // Memory allocation
    container = (dataType*)calloc (len, sizeof (dataType));
    if (container == nullptr)
        if (debug_output)
            printf ("Failed to init darray:\n\tFailed to allocate memory\n");
        else if (debug_output)
            printf ("Successfully allocated %d bytes\n", unsigned long long int (len * sizeof (dataType)));

    // Memory poisoning
    for (int i = 0; i < len; i++)
        container [i] = NAN;
    }

template<typename dataType>
inline darray<dataType>::~darray ()
    {
    free (container);
    }

template<typename dataType>
inline dataType & darray<dataType>::top ()
    {
    if (currentLen == 0)
        {
        if (debug_output)
            printf ("Failed to top ():\n\tStack is empty\n");

        // Weired
        int exeption_trigger = 1 / (currentLen);
        }
    else
        return container [currentLen - 1];
    }

template<typename dataType>
inline bool darray<dataType>::push (dataType value)
    {
    if (currentLen >= len)
        {
        if (!extendable)
            {
            if (debug_output)
                printf ("Failed to push ():\n\tStack is full\n");
            return false;
            }
        else
            extend ();
        }

    container [currentLen] = value;
    currentLen++;

    return true;
    }

template<typename dataType>
inline bool darray<dataType>::pop ()
    {
    if (currentLen == 0)
        {
        if (debug_output)
            printf ("Failed to pop ():\n\tStack is empty\n");
        return false;
        }

    container [currentLen - 1] = NAN;
    currentLen--;

    return true;
    }

template<typename dataType>
inline bool darray<dataType>::shrink_to_fit ()
    {
    // Memory allocation
    dataType* newContainer = (dataType*)calloc (currentLen, sizeof (dataType));
    if (newContainer != nullptr)
        {
        for (int i = 0; i < currentLen; i++)
            newContainer [i] = container [i];

        free (container);

        container = newContainer;

        len = currentLen;

        return true;
        }
    else if (debug_output)
        printf ("Failed to shrink darray:\n\tFailed to allocate memory\n");

    return false;
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
