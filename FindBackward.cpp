//
// Created by kochu on 27.02.2024.
//

#include <iostream>
#include <algorithm>
#include <vector>

template<typename Iterator, typename T>
bool findBackward(Iterator first, Iterator last, const T& value){
    for (Iterator current = last - 1; current != first; --current){
        if (*current == value){
            return true;
        }
    }
    return false;
}

int StartFindBackward(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "\n\nfind_backward\n";
    std::cout << "Vector:\n";
    for (int i = 0; i < 5; i++){
        std::cout << vec[i] << ' ';
    }

    std::cout << "\nNumber : 2\n";

    std::cout << "Is the number 2 found in the vector from the end: " << std::boolalpha << findBackward(vec.begin(), vec.end(), 2) << std::endl;

    return 0;
}