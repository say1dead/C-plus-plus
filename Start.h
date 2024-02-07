//
// Created by Сергей on 07.02.2024.
//

#ifndef LAB_PLUS_1_START_H
#define LAB_PLUS_1_START_H

#include "SwapToNumbers.h"
#include "RoundFloat.h"
#include "CompNumber.h"
#include "MatrixTranspone.h"

int Start(){
    (new SwapToNumbers) -> StartSwapToNumbers();
    (new RoundFloat) -> StartRoundFloat();
    (new CompNumber) -> StartCompNumber();
    (new MatrixTranspone) -> StartMatrixTranspone();
}
#endif //LAB_PLUS_1_START_H
