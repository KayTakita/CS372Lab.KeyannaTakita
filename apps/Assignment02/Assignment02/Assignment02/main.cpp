#include <iostream>
#include "ReceiptBag.hpp"
using namespace std;

int main()
{
    ReceiptBag<string> bag;

    int receipt1 = bag.insert("apple");
    int receipt2 = bag.insert("orange");
    int receipt3 = bag.insert("apple");

    cout << "Size: " << bag.size() << endl;
    cout << "Apple count: " << bag.count("apple") << endl;

    cout << "Removing receipt " << receipt2 << endl;
    string removed = bag.remove(receipt2);

    cout << "Removed item: " << removed << endl;
    cout << "Size after remove: " << bag.size() << endl;

    return 0;
}
