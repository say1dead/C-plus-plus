//
// Created by kochu on 07.02.2024.
//
#include <iostream>
#include <cstring>

using namespace std;

class DeleteElement{
private:
    int* array;
    int size;

public:
    DeleteElement(int* initialArray, int arraySize){
        array = new int[arraySize];
        size = arraySize;

        for (int i = 0; i < arraySize; ++i) {
            array[i] = initialArray[i];
        }
    }

    void deleteElement(int element) {
        int* newArray = new int[size-1];
        int newIndex = 0;

        for (int i = 0; i < size; ++i) {
            if (array[i] != element) {
                newArray[newIndex] = array[i];
                newIndex++;
            }
        }

        delete[] array;
        array = newArray;
        size--;

    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ' ';
        }
        cout << std::endl;
    }

};

int StartDeleteElement(){
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
    DeleteElement arr(array, size);
    cout << "Array before delete:";
    arr.printArray();
    arr.deleteElement(x);
    cout << "Array after delete:";
    arr.printArray();
    cout << '\n';

    return 0;
}