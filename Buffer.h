//
// Created by kochu on 23.03.2024.
//
/*
 * Буфер должен обладать следующими возможностями:
1 Вставка и удаление в конец
2 Вставка и удаление в начало
3 Вставка и удаление в произвольное место по итератору
4 Доступ в конец, начало
5 Доступ по индексу
6 Изменение капасити
 */
#ifndef UNTITLED13_BUFFER_H
#define UNTITLED13_BUFFER_H


#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>

template <class T>
class CircularBuffer {
    T* bufferData;

    size_t minCapacity = 0;
    size_t maxCapacity = 0;

    size_t capacity = 0;
    size_t size = 0;

    size_t beginIndex = 0;
    size_t endIndex = 0;

    int beginOffset = 0;
    int endOffset = 0;

public:
    void updateCapacity(size_t newCapacity) {
        if (newCapacity > 0 && minCapacity <= newCapacity && newCapacity <= maxCapacity) {
            setCapacity(newCapacity);
        }
    }


    void setCapacity(size_t capacity) {
        if (capacity == this->capacity || capacity < 0)
            return;

        T* temp = new T[capacity];
        size_t copied = 0;
        size_t index = beginIndex;
        size_t newSize = this->size < capacity ? this->size : capacity;

        while (copied < newSize) {
            temp[copied++] = bufferData[index];
            index = (index + 1) % this->capacity;
        }

        delete[] bufferData;
        bufferData = temp;

        beginIndex = 0;
        endIndex = newSize == capacity ? 0 : newSize;
        beginOffset = 0;
        endOffset = newSize == capacity ? 1 : 0;

        this->capacity = capacity;
        this->size = newSize;

    }



    CircularBuffer(size_t maxCapacity) {
        this->maxCapacity = maxCapacity;
        this->capacity = minCapacity;
        bufferData = new T[capacity];
    }


    CircularBuffer(const CircularBuffer& other) :
            capacity(other.capacity),
            size(other.size),
            beginIndex(other.beginIndex),
            endIndex(other.endIndex),
            beginOffset(other.beginOffset),
            endOffset(other.endOffset),
            minCapacity(other.minCapacity),
            maxCapacity(other.maxCapacity) {

        bufferData = new T[capacity];
        for (size_t i = 0; i < capacity; i++)
            bufferData[i] = other.bufferData[i];

    }


    void swap(CircularBuffer& other) {
        std::swap(capacity, other.capacity);
        std::swap(size, other.size);
        std::swap(beginIndex, other.beginIndex);
        std::swap(endIndex, other.endIndex);
        std::swap(beginOffset, other.beginOffset);
        std::swap(endOffset, other.endOffset);
        std::swap(bufferData, other.bufferData);
        std::swap(minCapacity, other.minCapacity);
        std::swap(maxCapacity, other.maxCapacity);
    }


    CircularBuffer& operator=(const CircularBuffer& other) {
        CircularBuffer<T> temp(other);
        (*this).swap(temp);
        return *this;
    }


    ~CircularBuffer() {
        delete[] bufferData;
    };


    T& operator[](int index) {
        return bufferData[(beginIndex + index) % capacity];
    }


    const T& front() {
        return bufferData[beginIndex];
    }

    const T& back() {
        return bufferData[(endIndex + capacity - 1) % capacity];
    }



    void setMinCapacity(size_t capacity) {
        if (capacity >= 0) {
            minCapacity = capacity;
            if (this->capacity < minCapacity)
                setCapacity(minCapacity);
        }
    }

    void setMaxCapacity(size_t capacity) {
        if (capacity >= 0) {
            maxCapacity = capacity;
            if (this->capacity > maxCapacity)
                setCapacity(maxCapacity);
        }
    }

    size_t getMinCapacity() {
        return minCapacity;
    }

    size_t getMaxCapacity() {
        return maxCapacity;
    }


    void pushFront(const T& element) {
        setCapacity(capacity + 1);

        if (beginIndex == 0) {
            beginIndex = capacity - 1;
            beginOffset--;
        }
        else {
            beginIndex--;
        }
        bufferData[beginIndex] = element;

        if (size == capacity) {
            if (endIndex == 0) {
                endOffset--;
                endIndex = capacity - 1;
            } else {
                endIndex--;
            }
            size--;
        }
        size++;
    }


    void pushBack(const T& element){
        setCapacity(capacity + 1);

        bufferData[endIndex] = element;
        if (endIndex == capacity - 1){
            endOffset++;
        }
        endIndex = (endIndex + 1) % capacity;

        if (size == capacity) {
            if (beginIndex == capacity - 1){
                beginOffset++;
            }
            beginIndex = (beginIndex + 1) % capacity;
            size--;
        }

        size++;
    }


    void popFront() {
        if (capacity == 0 || capacity > 0 && capacity - 1 < minCapacity)
            return;

        if (size > 0) {
            if (beginIndex == capacity - 1) {
                beginIndex = 0;
                beginOffset++;
            } else {
                beginIndex++;
            }

            size--;
        }

        updateCapacity(capacity - 1);
    }


    void popBack() {
        if (capacity == 0 || capacity > 0 && capacity - 1 < minCapacity)
            return;

        if (size > 0) {
            if (endIndex == 0) {
                endIndex = capacity - 1;
                endOffset--;
            } else {
                endIndex--;
            }

            size--;
        }

        updateCapacity(capacity - 1);
    }


    class iterator {
        CircularBuffer<T>* buffer;
        T* pointer_;
        int offset;


    public:

        typedef int difference_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::random_access_iterator_tag iterator_category;

        iterator(CircularBuffer<T>& bf, T* ptr, int offs) :
                buffer(&bf),
                pointer_(ptr),
                offset(offs) {

        }

        iterator() {

        }

        T& operator*() const {
            return *pointer_;

        }

        T& operator->() const {
            return &(*pointer_);
        }

        iterator& operator++() {
            pointer_++;
            if (pointer_ == (buffer->bufferData + buffer->capacity)) {
                pointer_ = buffer->bufferData;
                offset++;
            }

            return *this;
        };

        iterator operator++(int) {
            iterator temp(*this);
            this->operator++();
            return temp;
        }

        iterator& operator--() {
            if (pointer_ == buffer->bufferData) {
                pointer_ = buffer->bufferData + buffer->capacity - 1;
                offset--;
            } else {
                pointer_--;
            }

            return *this;
        };

        iterator operator--(int) {
            iterator temp(*this);
            this->operator--();
            return temp;
        }

        difference_type operator-(const iterator& iter2) {
            return buffer->capacity * offset + (pointer_ - buffer->bufferData)
                   - iter2.buffer->capacity * iter2.offset - (iter2.pointer_ - iter2.buffer->bufferData);
        }

        iterator operator-(int number) {
            int dif = buffer->capacity * offset + (pointer_ - buffer->bufferData) - number;
            int offs = dif / buffer->capacity;
            T* ptr = buffer->bufferData + (dif % buffer->capacity);
            return iterator(*buffer, ptr, offs);
        }

        difference_type operator+(const iterator& iter2) {
            return buffer->capacity * offset + (pointer_ - buffer->bufferData)
                   + iter2.buffer->capacity * iter2.offset + (iter2.pointer_ - iter2.buffer->bufferData);
        }

        iterator operator+(int number) {
            int dif = buffer->capacity * offset + (pointer_ - buffer->bufferData) + number;
            int offs = dif / buffer->capacity;
            T* ptr = buffer->bufferData + (dif % buffer->capacity);
            return iterator(*buffer, ptr, offs);
        }

        bool operator==(const iterator& iter2) const {
            return pointer_ == iter2.pointer_ && offset == iter2.offset;
        }

        bool operator!=(const iterator& iter2) const {
            return !(*this == iter2);
        }

        bool operator<(const iterator& iter2) const {
            return offset == iter2.offset && pointer_ < iter2.pointer_
                   || offset < iter2.offset;
        }

        bool operator<=(const iterator& iter2) const {
            return offset == iter2.offset && pointer_ <= iter2.pointer_
                   || offset < iter2.offset;
        }

        bool operator>(const iterator& iter2) const {
            return iter2 < *this;
        }

        bool operator>=(const iterator& iter2) const {
            return iter2 <= *this;
        }


        T& operator[](int index) const {
            return *pointer_;
        }

    };


    iterator begin() {
        return iterator(*this, bufferData + beginIndex, 0);
    }


    iterator end() {
        if (size == 0)
            return begin();
        return iterator(*this, bufferData + endIndex, endIndex <= beginIndex);
    }


    size_t getCapacity() const {
        return capacity;
    }


    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void showElementByIndex(size_t index) {
        if (index >= size) {
            std::cout << "\nIndex out of range." << std::endl;
        }
        else {
            std::cout << "\nElement at index " << index << ": " << bufferData[(beginIndex + index) % capacity] << std::endl;
        }
    }
    void insertIterator(iterator it, const T& value) {
        size_t pos = it - begin();

        size_t insertIndex = (beginIndex + pos) % capacity;

        if (size == 0 || insertIndex == endIndex) {
            pushBack(value);
        } else if (insertIndex == beginIndex) {
            pushFront(value);
        } else {
            if (endIndex < beginIndex) {
                if (insertIndex > beginIndex || insertIndex < endIndex) {
                    endIndex = (endIndex + 1) % capacity;
                }
            } else {
                if (insertIndex > beginIndex && insertIndex < endIndex) {
                    endIndex = (endIndex + 1) % capacity;
                }
            }

            for (size_t i = endIndex; i != insertIndex; i = (i - 1 + capacity) % capacity) {
                bufferData[i] = bufferData[(i - 1 + capacity) % capacity];
            }

            bufferData[insertIndex] = value;
            size++;
        }
    }

    void popIterator(iterator it) {
        int index = it - begin();

        size_t pos = (beginIndex + index) % capacity;

        for (size_t i = pos; i != endIndex; i = (i + 1) % capacity) {
            bufferData[i] = bufferData[(i + 1) % capacity];
        }

        endIndex = (endIndex - 1 + capacity) % capacity;
        size--;
    }

    void clear() {
        beginIndex = 0;
        endIndex = 0;
        size = 0;
        beginOffset = 0;
        endOffset = 0;
    }

    void Show(std::ostream& os) const{
        if (empty()){
            os << "Buffer is empty.\n";
        }
        else{
            std::cout << "Buffer: ";
            for (size_t i = beginIndex, count = 0; count < size; ++i, ++count){
                if (i == capacity) i = 0;
                os << bufferData[i] << " ";
            }
        }
    }
};

#endif //UNTITLED13_BUFFER_H
