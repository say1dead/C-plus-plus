//
// Created by Сергей on 07.02.2024.
//

#ifndef LAB_PLUS_1_COMPNUMBER_H
#define LAB_PLUS_1_COMPNUMBER_H
#include "main.h"

class CompNumber{
public:
    int StartCompNumber(){

        StructCompNumber a;
        float b;
        cout << "\nEnter Real number:";
        cin >> a.Real;
        cout << "Enter Imagine number:";
        cin >> a.Imagine;
        cout << "Enter b:";
        cin >> b;

        CompNumber_ref(a, b);

        if (a.Imagine > 0){
            cout << "Comp Number:" << a.Real  << '+' << a.Imagine << 'i';
        }
        else if (a.Imagine == 0){
            cout << "Comp Number:" << a.Real;
        }
        else if (a.Imagine < 0){
            cout << "Comp Number:" << a.Real << a.Imagine << 'i';
        }
        return 0;
    }
};
#endif //LAB_PLUS_1_COMPNUMBER_H
