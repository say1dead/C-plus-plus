//
// Created by kochu on 07.02.2024.
//

#ifndef LAB_PROGA_2_MAIN_H
#define LAB_PROGA_2_MAIN_H
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
        memcpy(array, arr, size * sizeof(int));
    }

    void printArray() {};
    void deleteElement(int) {};
};

#endif //LAB_PROGA_2_MAIN_H
