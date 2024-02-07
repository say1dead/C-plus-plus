//
// Created by kochu on 07.02.2024.
//

#ifndef LAB_PROGA_2_INTERSECTIONOFTWO_H
#define LAB_PROGA_2_INTERSECTIONOFTWO_H
//
// Created by kochu on 07.02.2024.
//

#include <iostream>
using namespace std;

class IntersectionOfTwo{
private:
    int* first_array;
    int first_size;

    int* second_array;
    int second_size;

    int* ans_array;
public:
    IntersectionOfTwo(int* first_arr,int first_arrSize,
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

    }

    void Intersection();

    void printArray();

};

int StartIntersectionOfTwo();
#endif //LAB_PROGA_2_INTERSECTIONOFTWO_H
