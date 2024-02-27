//
// Created by kochu on 27.02.2024.
//

#include <iostream>
#include <algorithm>
#include <vector>

template <typename Iterator, typename Predicate>
bool isPartitioned(Iterator first, Iterator last, Predicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) {
            break;
        }
    }
    for (; first != last; ++first) {
        if (p(*first)) {
            return false;
        }
    }
    return true;
}

int StartIsPartitioned(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto isEven = [](int x) { return x % 2 == 0; };
    auto isOdd = [](int x) { return x % 2 != 0; };
    std::cout << "is_partitioned\n";
    std::cout << "Vector:\n";
    for (int i = 0; i < 5; i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
    std::cout << std::boolalpha;
    std::cout << "Vector is partitioned by even : " << isPartitioned(vec.begin(), vec.end(), isEven) << '\n';
    std::cout << "Vector is partitioned by not_even : " << isPartitioned(vec.begin(), vec.end(), isOdd) << '\n';

    std::partition(vec.begin(), vec.end(), isEven);
    std::cout << "Vector is partitioned by even after partitioned by even : " << isPartitioned(vec.begin(), vec.end(), isEven) << '\n';
    return 0;
}