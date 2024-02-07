//
// Created by kochu on 07.02.2024.
//

#ifndef LAB_PROGA_2_ADDTOSET_H
#define LAB_PROGA_2_ADDTOSET_H
#include <iostream>
#include <cstring>
using namespace std;

class AddToSet{
private:
    int* array;
    int size;

public:
    AddToSet(int* initialArray, int arraySize){
        array = new int[arraySize + 1];
        size = arraySize + 1;


        for (int i = 0; i < size; ++i) {
            array[i] = initialArray[i];
        }
    }

    void Add(int x);
    void printArray();

};

int StartAddToSet();
#endif //LAB_PROGA_2_ADDTOSET_H
