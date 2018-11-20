#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef size_t arrln;
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

        // Allocates memory and fils it with poison value
        bool allocate (dataType* & newContainer, arrln len)
            {
            newContainer = nullptr;

            msgassert (allocLen, "Size of array must be greater than zero\n");
            newContainer = (dataType*)calloc (len, sizeof (dataType));

            if (newContainer == nullptr)
                {
                printf ("Failed to allocate memory\n");
                return false;
                }
            else
                {
                printf ("Allocated %d bytes\n", len * sizeof (dataType));

                for (int i = 0; i < len; i++)
                    newContainer [i] = NAN;

                return true;
                }
            }

    public:
        // Constructors and destructor
        darray (arrln Size = STK_SZ_DEFAULT);
        ~darray ();

        // Container getters
        dataType & back ();
        dataType & front ();

        // Operators
        dataType & operator [] (arrln index);
        
        // Modifiers
        bool push_back (dataType value);
        bool pop_back ();
        bool push_front (dataType value);

        // Size getters
        arrln size ();
        bool empty ();

        // Size setters
        bool shrink ();
        bool resize (arrln newSize);

    };



// Constructors and destructors
template<typename dataType>
inline darray<dataType>::darray (arrln Size)
    {
    // Default values
    debug_output = false;
    currentLen = 0;
    allocLen = Size;
    
    // Allocates memory
    allocate (container, allocLen);
    }

template<typename dataType>
inline darray<dataType>::~darray ()
    {
    free (container);
    }

// Operators
template<typename dataType>
inline dataType & darray<dataType>::operator[](arrln index)
    {
    return container [index];
    }


// Modifiers
template<typename dataType>
inline bool darray<dataType>::push_back (dataType value)
    {
    if (currentLen == allocLen - 1)
        if (!resize ((allocLen * 3 / 2) + 1))
            return false;

    container [currentLen] = value;
    currentLen++;

    return true;
    }

template<typename dataType>
bool darray<dataType>::push_front (dataType value)
    {
    if (currentLen == allocLen - 1)
        if (!resize ((allocLen * 3 / 2) + 1))
            return false;

    for (int i = currentLen+1; i > 0; i--)
        container [i] = container [i - 1];

    container [0] = value;
    currentLen++;

    return true;
    }


template<typename dataType>
bool darray<dataType>::resize (arrln newSize)
    {
    if (newSize >= currentLen)
        {
        dataType* newContainer = nullptr;

        if (allocate (newContainer, newSize))
            {
            // Copies the memory
            for (int i = 0; i < currentLen; i++)
                newContainer [i] = container [i];

            allocLen = newSize;

            // Releases memory
            free (container);
            container = newContainer;

            return true;
            }
        else
            return false;
        }
    else
        printf ("Failed to 'resize ()'\n\tNew length is less than old one\n");

    return false;
    }


// Container getters
template<typename dataType>
dataType & darray <dataType>::back ()
    {
    msgassert (currentLen, "Unable to back ():\n\tArray is empty\n");
    return container [currentLen - 1];
    }

template<typename dataType>
dataType & darray <dataType>::front ()
    {
    msgassert (currentLen, "Unable to back ():\n\tArray is empty\n");
    return container [0];
    }


// Modifiers
template<typename dataType>
bool darray<dataType>::pop_back ()
    {
    if (!currentLen)
        {
        printf ("Unable to pop ():\n\tArray is empty\n");
        return false;
        }

    container [currentLen - 1] = NAN;
    currentLen--;

    return true;
    }


// Size getters
template<typename dataType>
arrln darray<dataType>::size ()
    {
    return currentLen;
    }

template<typename dataType>
bool darray<dataType>::empty ()
    {
    return (currentLen == 0);
    }


// Size setters
template<typename dataType>
bool darray<dataType>::shrink ()
    {
    return resize (currentLen);
    }

#undef SZ_DEFAULT