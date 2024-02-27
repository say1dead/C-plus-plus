//
// Created by kochu on 27.02.2024.
//

#ifndef LAB_PROGA_5_QUEUE_H
#define LAB_PROGA_5_QUEUE_H

#include <iostream>
#include <queue>
using namespace std;

template<typename T>

class Queue{
private:
    queue<T> q;
    int maxSize;
public:
    Queue() : maxSize(0) {}

    Queue(int max) : maxSize(max) {}

    bool CheckFull();

    bool CheckEmpty();

    void Push(T );

    T Pull();

    void Show();
};

int StartQueue();
#endif //LAB_PROGA_5_QUEUE_H
