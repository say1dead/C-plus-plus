//
// Created by kochu on 07.02.2024.
//

#ifndef LAB_PROGA_2_DELETEELEMENT_H
#define LAB_PROGA_2_DELETEELEMENT_H
#include <iostream>
using namespace std;

class DeleteElement{
private:
    int* array;
    int size;

public:
    DeleteElement(int* arr, int arrSize) {
        size = arrSize;
        array = new int[size];

        for (int i = 0; i < arrSize; ++i) {
            array[i] = arr[i];
        }
    }

    void printArray() {};
    void deleteElement(int) {};
};

int StartDeleteElement();
#endif //LAB_PROGA_2_DELETEELEMENT_H
