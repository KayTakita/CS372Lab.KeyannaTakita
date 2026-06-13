//
//  Bag.hpp
//  Assignment03
//
//  
//

#pragma once
#include "List.hpp"

template <typename T>
class Bag
{
private:
    List<T> items;

public:
    Bag()
    {
    }

    void add(T item)
    {
        items.push_back(item);
    }

    bool empty() const
    {
        return items.empty();
    }

    T grab()
    {
        T item = items.front();
        items.pop_front();
        return item;
    }

    void traverse(void (*doIt)(T data)) const
    {
        items.traverse(doIt);
    }
};
