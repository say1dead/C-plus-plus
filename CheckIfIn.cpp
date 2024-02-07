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

    bool Check(int x){
        for (int i = 0; i < size; i++){
            if (array[i] == x){
                return true;
            }
        }
        return false;
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ' ';
        }
    }

};

int StartCheckIfIn(){
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

    CheckIfIn arr(array, size);
    if (arr.Check(x)){
        cout << "x in array.";
    }
    else{
        cout << "x not in array.";
    }
    cout << '\n';
    return 0;
}