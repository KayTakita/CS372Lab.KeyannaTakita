//
//
//
//
//
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

            std::copy(arr, arr + length, temp);

            delete[] arr;

            arr = temp;
            vCapacity = newCapacity;
        }
    }

public:

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

    int size()
    {
        return length;
    }

    int capacity()
    {
        return vCapacity;
    }
};
