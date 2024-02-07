//
// Created by Сергей on 07.02.2024.
//

#ifndef LAB_PLUS_1_MATRIXTRANSPONE_H
#define LAB_PLUS_1_MATRIXTRANSPONE_H
#include "main.h"

class MatrixTranspone{
public:
    int StartMatrixTranspone(){
        int a[3][3];
        cout << "\nEnter matrix:" << '\n';
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cin >> a[i][j];
            }
        }

        int b[3][3];
        MatrixTranspone_ref(a, b);

        cout << "Matrix:\n";

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }

        return 0;
    }

};
#endif //LAB_PLUS_1_MATRIXTRANSPONE_H
