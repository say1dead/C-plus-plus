//
// Created by Сергей on 07.02.2024.
//

#ifndef LAB_PLUS_1_ROUNDFLOAT_H
#define LAB_PLUS_1_ROUNDFLOAT_H
#include "main.h"

class RoundFloat{
public:
    int StartRoundFloat(){
        float a;
        cout << "\nEnter a:";
        cin >> a;
        RoundFloat_ref(a);
        cout << "a after round:" << a;
        return 0;
    }
};

#endif //LAB_PLUS_1_ROUNDFLOAT_H
