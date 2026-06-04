//
//
//
//
//
//

#include <iostream>
#include <chrono>
#include "Vector.hpp"

using namespace std;

int main()
{
    for (int n = 2; n <= 4194304; n *= 2)
    {
        Vector<int> numbers;

        auto start =
            chrono::steady_clock::now();

        for (int i = 0; i < n; i++)
        {
            numbers.push_back(i);
        }

        auto end =
            chrono::steady_clock::now();

        auto elapsed =
            chrono::duration_cast
            <chrono::milliseconds>
            (end - start);

        cout << "Size: "
             << n
             << " Time: "
             << elapsed.count()
             << " ms"
             << endl;
    }

    return 0;
}

