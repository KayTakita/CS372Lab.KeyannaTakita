//
//  main.cpp
//  Lazy Deletion
//
//  Created by Keyanna Takita
//

#include <iostream>
#include "List.hpp"
using namespace std;

//----- Void Functions -----
void printItem(int data)
{
    cout << data << " ";
}

// ------ Main Function ------
int main()
{
    List<int> numbers;          // List of numbers from M03PB
    numbers. push_back(10);
    numbers. push_back(20);
    numbers. push_back(30);
    numbers. push_back(40);
    numbers. push_back(50);
    
    cout << "List Before Deletion";
    numbers.traverse(printItem);
    cout << endl;
    
    numbers.remove(30);
    
    cout << "List After Deletion";
    numbers.traverse(printItem);
    cout << endl;
    
    cout << "Size: " << numbers.size() << endl;
    
    return 0;
    
}
