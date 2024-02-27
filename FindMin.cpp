//
// Created by kochu on 27.02.2024.
//

#include <iostream>
using namespace std;

template<typename T>

T min(T& a, T& b){
    return (a < b ? a : b);
}

int StartFindMin(){
    cout << "Find min:\n";
    cout << "Min of (1) and (2) it`s " << min(1, 2) << '\n';
    cout << "Min of (2.3) and (2.4) it`s " << min(2.3, 2.4) << '\n';
    cout << "Min of (a) and (b) it`s " << min('a', 'b') << '\n';
    return 0;
}