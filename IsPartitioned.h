//
// Created by kochu on 27.02.2024.
//

#ifndef LAB_PROGA_6_ISPARTITIONED_H
#define LAB_PROGA_6_ISPARTITIONED_H

#include <iostream>
#include <algorithm>
#include <vector>

template <typename Iterator, typename Predicate>
bool isPartitioned(Iterator first, Iterator last, Predicate p);

int StartIsPartitioned();
#endif //LAB_PROGA_6_ISPARTITIONED_H
