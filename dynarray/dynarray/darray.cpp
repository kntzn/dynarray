#include "darray.h"

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