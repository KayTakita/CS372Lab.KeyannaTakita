//
//  Array.hpp
//  Assignment02
//
//  Created by Keyanna Takita on 6/3/26.
//
#pragma once

template <typename T>
class Array
{
private:
    T* arr;
    int arrSize;

public:

    Array(int size)
    {
        arrSize = size;
        arr = new T[arrSize];
    }

    ~Array()
    {
        delete[] arr;
    }

    T& operator[](int index)
    {
        return arr[index];
    }

    int size()
    {
        return arrSize;
    }
};
