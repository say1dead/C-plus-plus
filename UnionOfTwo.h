//
// Created by kochu on 07.02.2024.
//

#ifndef LAB_PROGA_2_UNIONOFTWO_H
#define LAB_PROGA_2_UNIONOFTWO_H
//
// Created by kochu on 07.02.2024.
//
//
// Created by kochu on 07.02.2024.
//

#include <iostream>
using namespace std;

class UnionOfTwo{
private:
    int* first_array;
    int first_size;

    int* second_array;
    int second_size;

    int* ans_array;
    int ans_arraySize;
public:
    UnionOfTwo(int* first_arr,int first_arrSize,
               int* second_arr,int second_arrSize){
        first_size = first_arrSize;
        first_array = new int[first_size];


        for (int i = 0; i < first_size; ++i) {
            first_array[i] = first_arr[i];
        }

        second_size = second_arrSize;
        second_array = new int[second_size];


        for (int i = 0; i < second_size; ++i) {
            second_array[i] = second_arr[i];
        }

        ans_array = new int[first_size];
        ans_arraySize = 0;
    }

    void Union();

    void printArray();

};

int StartUnionOfTwo();
#endif //LAB_PROGA_2_UNIONOFTWO_H
