//
// Created by kochu on 27.02.2024.
//
#include <iostream>
#include <vector>

template<typename Iterator, typename Predicate>

bool allOf(Iterator first, Iterator second, Predicate pred){
    bool flag;
    for (Iterator current = first; current != second; ++current){
        if (!pred(*current)){
            return false;
        }
    }
    return true;
}
struct Cpoint{
    int a;
    int b;
};

int StartAllOf(){

    std::vector<Cpoint> num;

    num.push_back({1, 1});
    num.push_back({2, 2});
    num.push_back({2, 1});

    std::vector<int> vec = {2, 4, 6, 8, 10};



    std::cout << "\n\n";
    std::cout << "all_of\n";
    std::cout << "Vector:\n";
    for (int i = 0; i < 5; i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "CPoint:\n";
    for (int i = 0; i < 3; i++){
        std::cout << '{' << num[i].a << ", " << num[i].b << '}' << ' ';
    }
    std::cout << '\n';
    std::cout << std::boolalpha;

    auto isEven = [](int x) { return x % 2 == 0; };
    auto forCPoint = [](const Cpoint &point){ return (point.a == point.b); };

    std::cout << "all_of for vector: " << std::boolalpha << allOf(vec.begin(), vec.end(), isEven) << std::endl;
    std::cout << "all_of for CPoint: " << std::boolalpha << allOf(num.begin(), num.end(), forCPoint) << std::endl;
    return 0;
}