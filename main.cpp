#include "heap.h"
#include <iostream>
using namespace std;
#include <conio.h>

int main()
{
    Heap myHeap;
    int x;
    cout << "Enter number of elements : ";
    cin >> x;
    myHeap.setNumberOfElements(x);
    myHeap.allocateInitialMemory();
    myHeap.inputElements();

    char c='n';
    do {
        cout << "Do you want to add another element ? ";
        cin >> c;
        if (!(c == 'y' || c == 'Y'))
        {
            break;
        }
        int temp;
        cout << endl << "Enter the element : ";
        cin >> temp;
        myHeap.addElement(temp);
    } while (c == 'y' || c == 'Y');

    cout << endl << endl;
    
    myHeap.printArray();

    if (myHeap.checkMaxHeap())
    {
        cout << endl << "Given heap is max heap!";
    }
    else
    {
        cout << endl << "Given heap is not a max heap!";
    }

    myHeap.buildMaxHeap();
    cout << endl << "Max Heap : " << endl;
    myHeap.printArray();
    cout << endl << "Sorted Array : " << endl;
    myHeap.extractToSort();

    _getch();
    return 0;
}