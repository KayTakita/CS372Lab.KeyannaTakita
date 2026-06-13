//
//  CircularList.hpp
//  Assignment03
//
//
//

#pragma once
#include "List.hpp"

template <typename T>
class CircularList : public List<T>
{
public:
    CircularList() : List<T>()
    {
    }

    void traverseFromFront(void (*doIt)(T data), int times) const
    {
        for (int i = 0; i < times; i++)
        {
            this->traverse(doIt);
        }
    }
};
