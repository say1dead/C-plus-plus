//
// Created by kochu on 14.02.2024.
//

#ifndef LAB_PROGA_2_SETOFNUMBERS_H
#define LAB_PROGA_2_SETOFNUMBERS_H

class SetOfTwo{
private:
    int* array;
    int size;
    int maxSize;
public:
    SetOfTwo() : array(nullptr), size(0), maxSize(0) {}

    SetOfTwo(int MaxSize);

    SetOfTwo(SetOfTwo& other) : size(other.size), maxSize(other.maxSize) {};

    void Add(int );

    void Delete(int );

    bool Check(int );

    SetOfTwo Union(SetOfTwo& other);

    SetOfTwo Intersection(SetOfTwo& other);

    void Print();
};

int Start();

#endif //LAB_PROGA_2_SETOFNUMBERS_H
