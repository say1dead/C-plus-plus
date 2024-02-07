//
// Created by kochu on 07.02.2024.
//
#include <iostream>
#include <cstring>
using namespace std;

class AddToSet{
private:
    int* array;
    int size;

public:
    AddToSet(int* initialArray, int arraySize){
        array = new int[arraySize];
        size = arraySize;


        for (int i = 0; i < size; ++i) {
            array[i] = initialArray[i];
        }
    }

    void Add(int x) {
        int* newArray = new int[size+1];

        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }

        newArray[size] = x;

        delete[] array;
        array = newArray;
        size++;
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ' ';
        }
    }

};

int StartAddToSet(){

    int size;
    cout << "Enter size:";
    cin >> size;
    cout << "Enter array:";
    int* array = new int[size];
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    int x;
    cout << "Enter x:";
    cin >> x;

    AddToSet arr(array, size);
    cout << "Array before add:";
    arr.printArray();
    arr.Add(x);
    cout << "\nArray after add:";
    arr.printArray();
    cout << '\n';
    return 0;
}