#include <iostream>
#include <queue>
using namespace std;

template<class T>
class Queue{
private:
    queue<T> q;
    int maxSize;

public:
    Queue(int size) : maxSize(size) {}

    bool CheckFull(){
        return q.size() == maxSize;
    }

    bool CheckEmpty(){
        return q.empty();
    }

    void Push(T element){
        if (CheckFull()){
            throw overflow_error("Queue is full");
        }

        q.push(element);
    }

    T Pull(){
        if (CheckEmpty()){
            throw underflow_error("Queue is empty");
        }

        T element = q.front();
        q.pop();
        return element;
    }

    void Show() {
        if (q.empty()) {
            throw underflow_error("Queue is empty");
        }
        queue<T> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << ' ';
            temp.pop();
        }
        cout << '\n';
    }
};

int StartQueue(){
    int MaxSize;
    cout << "\nEnter MaxSize:";
    cin >> MaxSize;

    Queue<int> q(MaxSize);

    char choice;
    int element;
    cout << "\n+ to push, - to pull, ? to show, = to stop\nchoice:";
    cin >> choice;
    do {
        cout << "\n+ to push, - to pull, ? to show, = to stop\nchoice:";
        if (choice == '+'){
            try{
                cout << "Enter element:";
                cin >> element;
                q.Push(element);
            } catch (overflow_error& e){
                cerr << "\nError: " << e.what() << '\n';
            }
        }
        else if (choice == '-'){
            try{
                cout << q.Pull() << " deleted" << '\n';
            } catch (underflow_error& e){
                cerr << "\nError: " << e.what() << '\n';
            }
        }
        else if (choice == '?'){
            try {
                q.Show();
            } catch (underflow_error& e){
                cerr << "\nError: " << e.what() << '\n';
            }
        }
        else if(choice == '='){
            return 0;
        }

    } while (cin >> choice);

    return 0;
}