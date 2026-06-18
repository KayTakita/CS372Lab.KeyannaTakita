//
//  Vector 2.hpp
//  Vector Class Upgrade
//
//  Created by Keyanna Takita on 6/17/26.
//


#pragma once

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Vector
{
private:
    T* arr;
    int vCapacity;
    int length;

    void expand(int newCapacity)
    {
        if (newCapacity > vCapacity)
        {
            T* temp = new T[newCapacity];

            copy(arr, arr + length, temp);

            delete[] arr;

            arr = temp;
            vCapacity = newCapacity;
        }
    }

public:

    class Iterator
    {
    private:
        Vector<T>* vec;
        int index;

    public:
        Iterator(Vector<T>* v, int i)
        {
            vec = v;
            index = i;
        }

        T& operator*()
        {
            return vec->arr[index];
        }

        Iterator& operator++()
        {
            index++;
            return *this;
        }

        bool operator==(const Iterator& other) const
        {
            return index == other.index;
        }

        bool operator!=(const Iterator& other) const
        {
            return index != other.index;
        }
    };

    Vector()
    {
        arr = new T[1];
        vCapacity = 1;
        length = 0;
    }

    ~Vector()
    {
        delete[] arr;
    }

    void push_back(T data)
    {
        if (length == vCapacity)
        {
            expand(vCapacity * 4);
        }

        arr[length] = data;
        length++;
    }

    T& at(int index)
    {
        return arr[index];
    }

    int size()
    {
        return length;
    }

    int capacity()
    {
        return vCapacity;
    }

    Iterator begin()        // first element
    {
        return Iterator(this, 0);
    }

    Iterator end()          // Last element
    {
        return Iterator(this, length);
    }
};
