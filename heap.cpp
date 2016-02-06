#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap(void)
{
    heapArrayPtr = nullptr;
    numberOfElements = 0;
}

void Heap::setNumberOfElements(int x)
{
    numberOfElements = x;
}

int Heap::getNumberOfElements(void)
{
    return numberOfElements;
}

void Heap::allocateInitialMemory(void)
{
    if (numberOfElements == 0)
    {
        cout << "Error! Number of elements has been set as zero" << endl;
        return;
    }
    heapArrayPtr = new int[numberOfElements];
}

void Heap::inputElements(void)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> heapArrayPtr[i];
        cout << endl;
    }
}

void Heap::addElement(int x)
{
    int * tempPtr = new int[numberOfElements + 1];
    for (int i = 0; i < numberOfElements; i++)
    {
        tempPtr[i] = heapArrayPtr[i];
    }
    tempPtr[numberOfElements] = x;
    numberOfElements++;
    delete[] heapArrayPtr;
    heapArrayPtr = tempPtr;
}

void Heap::printArray(void)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << heapArrayPtr[i] << endl;
    }
}

bool Heap::checkMaxHeap(void)
{
    for (int i = 0; i < numberOfElements / 2; i++)
    {
        if (!(heapArrayPtr[i] > heapArrayPtr[2 * i + 1] && heapArrayPtr[i]>heapArrayPtr[2 * i + 2]))
        {
            return false;
        }
    }
    return true;
}

void Heap::maxHeapify(int index)
{
    if (index > (numberOfElements / 2 - 1))
    {
        return;
    }
    int max = heapArrayPtr[2 * index + 1];
    int whichOne = 1;
    if (2 * index + 2 < numberOfElements)
    {
        if (heapArrayPtr[2 * index + 2] > max)
        {
            max = heapArrayPtr[2 * index + 2];
            whichOne = 2;
        }
    }
    if (heapArrayPtr[index] > max)
    {
        return;
    }
    int temp = heapArrayPtr[index];
    heapArrayPtr[index] = max;
    heapArrayPtr[2 * index + whichOne] = temp;
    maxHeapify(2 * index + whichOne);    
}

void Heap::buildMaxHeap(void)
{
    for (int i = (numberOfElements / 2) - 1; i >= 0; --i)
    {
        maxHeapify(i);
    }
}

void Heap::extractToSort(void)
{
    while (numberOfElements > 0)
    {
        cout << heapArrayPtr[0] << endl;
        int temp = heapArrayPtr[0];
        heapArrayPtr[0] = heapArrayPtr[numberOfElements - 1];
        heapArrayPtr[numberOfElements - 1] = temp;
        numberOfElements--;
        buildMaxHeap();
    }
}

Heap::~Heap(void)
{
    delete[] heapArrayPtr;
}