#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int, int, int);

int main()
{
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;

    int disks[] = {5, 10, 15, 20, 25, 30, 35};

    for (int numdisks : disks)
    {
        auto start = chrono::high_resolution_clock::now();

        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);

        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Recursive Hanoi with " << numdisks
             << " disks took " << duration.count()
             << " milliseconds" << endl;
    }

    return 0;
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg)
{
    if (num > 0)
    {
        moveDisks(num - 1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}

void printIt(int disk, int fromPeg, int toPeg)
{
    // Do nothing for timing test
}
