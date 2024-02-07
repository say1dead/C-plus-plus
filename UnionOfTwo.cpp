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

    void Union() {
        for (int i = 0; i < first_size; i++) {
            bool flag = false;
            for (int k = 0; k < ans_arraySize; k++) {
                if (first_array[i] == ans_array[k]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans_array[ans_arraySize++] = first_array[i];
            }
        }

        for (int j = 0; j < second_size; j++) {
            bool flag = false;
            for (int k = 0; k < ans_arraySize; k++) {
                if (second_array[j] == ans_array[k]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans_array[ans_arraySize++] = second_array[j];
            }
        }
        first_array = ans_array;
    }

    void printArray() {
        for (int i = 0; i < ans_arraySize; i++) {
            cout << ans_array[i] << ' ';
        }
    }

};

int StartUnionOfTwo(){
    int size;
    cout << "Enter size of first array:";
    cin >> size;
    cout << "Enter first array:";
    int* array = new int[size];
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }

    int n_2;
    cout << "Enter size of second array:";
    cin >> n_2;
    int second_array[n_2];
    cout << "Enter second array:";
    for (int i = 0; i < n_2; i++){
        cin >> second_array[i];
    }
    UnionOfTwo arr(array, size, second_array, n_2);

    arr.Union();
    cout << "Union: ";
    arr.printArray();
    cout << '\n';

    return 0;
}