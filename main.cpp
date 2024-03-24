#include "Buffer.h"
int main(){
    CircularBuffer<int> buffer(5);

    //вставка и удаление в конец
    std::cout << "---add and delete from back---\n";
    std::cout  << "TASK -> Back 1, 2, 3 and delete.\n";
    buffer.pushBack(1);
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.pushBack(2);
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.pushBack(3);
    std::cout << '\n';
    buffer.Show(std::cout);

    std::cout << "\n\ndelete\n";
    buffer.popBack();
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.popBack();
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.popBack();
    std::cout << '\n';
    buffer.Show(std::cout);

    std::cout << "\n\n---add and delete from front---";
    //вставка и удаление в начало
    std::cout << "\nTASK -> pushFront 1, 2, 3 and delete";
    buffer.pushFront(1);
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.pushFront(2);
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.pushFront(3);
    std::cout << '\n';
    buffer.Show(std::cout);
    std::cout << "\n\ndelete\n";
    buffer.popFront();
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.popFront();
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.popFront();
    std::cout << '\n';
    buffer.Show(std::cout);

    std::cout << "\n---add and delete by iterator---\n";
    std::cout << "TASK -> push front 1 by iterator, push back 2 by iterator, erase by iterator\n";
    buffer.clear();
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.insertIterator(buffer.begin(), 1);
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.insertIterator(buffer.begin(), 2);
    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.insertIterator(buffer.end(), 3);
    std::cout << '\n';
    buffer.Show(std::cout);


    std::cout << "\n\n---front and back---\n";
    std::cout << "TASK -> cout front and back\n";
    buffer.clear();
    buffer.pushBack(3);
    buffer.pushBack(2);
    buffer.pushBack(1);
    std::cout << '\n';
    buffer.Show(std::cout);
    std::cout << "\nFront: " << buffer.front() << '\n';
    std::cout << "Back: " << buffer.back() << '\n';
    buffer.clear();

    std::cout << "\n---by index---\n";
    std::cout << "TASK -> add 1, 2, 3 by index\n";


    std::cout << '\n';
    buffer.Show(std::cout);
    buffer.showElementByIndex(1);
    buffer.clear();

    std::cout << "\n---set capacity---\n";
    std::cout << "TASK -> change capacity\n";

    buffer.pushBack(1);
    buffer.pushBack(2);
    buffer.pushBack(3);
    std::cout << "Buffer with max_capacity= " << buffer.getCapacity() << " and size= " << buffer.getSize() << "\n";
    buffer.Show(std::cout);

    buffer.setCapacity(10);
    std::cout << "\nBuffer with max_capacity= " << buffer.getCapacity() << " and size= " << buffer.getSize() << "\n";
    buffer.clear();

    std::cout << "\n\n\nTest algo\n";
    buffer.pushBack(3);
    buffer.pushBack(2);
    buffer.pushBack(1);
    buffer.pushBack(6);
    buffer.pushBack(5);
    buffer.pushBack(7);
    buffer.Show(std::cout);

    std::cout << std::boolalpha;
    std::cout << "\nall_of (x < 12) : " << std::all_of(buffer.begin(), buffer.end(), [](int x){return x < 12;});
    std::cout << "\nfind (1) : " << (std::find(buffer.begin(), buffer.end(), 1) != buffer.end());

    std::sort(buffer.begin(), buffer.end());
    std::cout << '\n';
    buffer.Show(std::cout);
    return 0;
}