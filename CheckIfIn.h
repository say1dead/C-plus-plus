//
// Created by kochu on 07.02.2024.
//

#ifndef LAB_PROGA_2_CHECKIFIN_H
#define LAB_PROGA_2_CHECKIFIN_H
//
// Created by kochu on 07.02.2024.
//

#include <iostream>
using namespace std;

class CheckIfIn{
private:
    int* array;
    int size;

public:
    CheckIfIn(int* initialArray, int arraySize){
        size = arraySize;
        array = new int[size];


        for (int i = 0; i < size; ++i) {
            array[i] = initialArray[i];
        }
    }

    bool Check(int x);

    void printArray();

};

int StartCheckIfIn();
#endif //LAB_PROGA_2_CHECKIFIN_H
