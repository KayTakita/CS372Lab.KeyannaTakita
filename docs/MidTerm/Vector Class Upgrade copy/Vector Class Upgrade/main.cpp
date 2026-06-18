//
//  main.cpp
//  Vector Class Upgrade
//
//  Created by Keyanna Takita 
//

#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    Vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    for (auto it = numbers.begin();
         it != numbers.end();
         ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
