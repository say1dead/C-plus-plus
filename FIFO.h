//
// Created by kochu on 15.02.2024.
//

#ifndef LAB_PROGA_3_FIFO_H
#define LAB_PROGA_3_FIFO_H
//
// Created by kochu on 15.02.2024.
//
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class FIFO{
private:
    Node* head;
    Node* tail;
public:
    FIFO() : head(nullptr), tail(nullptr) {};

    void enqueue(int value);

    void operator>> (int element);

    int dequeu();

    ostream& operator<<(ostream& os);

    void Show();

};

int StartFIFO();
#endif //LAB_PROGA_3_FIFO_H
