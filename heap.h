#pragma once

class Heap
{
private:
    int* heapArrayPtr;
    int numberOfElements;

public:
    Heap(void);

    void setNumberOfElements(int);
    int getNumberOfElements(void);
    void allocateInitialMemory(void);
    void inputElements(void);
    void addElement(int);
    void printArray(void);

    bool checkMaxHeap(void);
    void maxHeapify(int);
    void buildMaxHeap(void);
    void extractToSort(void);

    ~Heap(void);
};