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

        bool shrink ();
        bool resize (arrln newSize);
        
        /*dataType & operator [] (arrln index)
            {
            msgassert (index < currentLen + 1, "Index is out of range\n");
            msgassert (index >= 0, "Index is out of range\n");

            return container [index];
            }*/
        
        
            
        

        // Modifiers
        bool push_back (dataType value);
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
    debug_output = false;
    currentLen = 0;
    allocLen = Size;
    
    msgassert (allocLen, "Size of array must be greater than zero\n");
    container = (dataType*) calloc (allocLen, sizeof (dataType));

    if (container == nullptr)
        printf ("Failed to allocate memory\n");
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
inline bool darray<dataType>::shrink ()
    {
    return resize (currentLen);
    }

template<typename dataType>
inline bool darray<dataType>::resize (arrln newSize)
    {
    msgassert (newSize, "Size of array must be greater than zero\n");
    if (newSize >= currentLen)
        {
        dataType* newContainer = nullptr;
        if (newContainer = (dataType*)calloc (newSize, sizeof (dataType)))
            {
            // Copies the memory
            memcpy (newContainer, container, currentLen);
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


template<typename dataType>
inline bool darray<dataType>::push_back (dataType value)
    {
    if (currentLen == allocLen - 1)
        if (!resize ((allocLen * 3 / 2) + 1))
            return false;
          
    container [currentLen++] = value;
            
    return true;
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