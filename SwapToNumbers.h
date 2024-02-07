//
// Created by Сергей on 07.02.2024.
//

#ifndef LAB_PLUS_1_SWAPTONUMBERS_H
#define LAB_PLUS_1_SWAPTONUMBERS_H

#include "main.h"
class SwapToNumbers{
public:
    int StartSwapToNumbers(){
        int a, b;
        cout << "Enter a:";
        cin >> a;
        cout << "Enter b:";
        cin >> b;

        SwapToNumbers_ref(a, b);
        cout << "a/b after swap:" << a << ", " << b;
        return 0;
    }
};
#endif //LAB_PLUS_1_SWAPTONUMBERS_H
