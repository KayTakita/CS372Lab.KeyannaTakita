//
//  ReceiptBag.hpp
//  Assignment02
//
//  Created by Keyanna Takita on 6/3/26.
//

#pragma once

#include <vector>
using namespace std;

template <typename T>
class ReceiptBag
{
private:
    vector<T> items;
    vector<int> receipts;
    int nextReceipt;

public:
    ReceiptBag()
    {
        nextReceipt = 1;
    }

    int insert(T item)
    {
        items.push_back(item);
        receipts.push_back(nextReceipt);

        nextReceipt++;

        return nextReceipt - 1;
    }

    T remove(int receipt)
    {
        for (int i = 0; i < receipts.size(); i++)
        {
            if (receipts[i] == receipt)
            {
                T removedItem = items[i];

                items.erase(items.begin() + i);
                receipts.erase(receipts.begin() + i);

                return removedItem;
            }
        }

        return T();
    }

    int size()
    {
        return items.size();
    }

    int count(T item)
    {
        int total = 0;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i] == item)
            {
                total++;
            }
        }

        return total;
    }
};
