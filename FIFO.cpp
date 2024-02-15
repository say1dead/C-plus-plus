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

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void operator>> (int element){
        enqueue(element);
    }

    int dequeu(){
        if (head != nullptr) {
            Node* temp = head;
            int ans = temp->data;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return ans;
        }
        else{
            cout << "Queue is empty";
        }
    }

    ostream& operator<<(ostream& os) {
        return os << dequeu() << '\n';
    }

    void Show() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Queue is empty";
        }
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }


};

int StartFIFO() {
    cout << "\n\nFIFO\n";
    FIFO queue;

    cout << "\nEnter your action:\n";
    cout << "1. Push (+).\n2. Pull (-).\n3. Show (=).\n4. Stop (?).\n";
    string s;
    int element;
    int push, pull;
    while(cin >> s){
        if (s == "+"){
            cout << "Enter element -";
            cin >> element;
            queue >> element;
            push++;
        }
        if (s == "-"){
            cout << "Delete element - ";
            queue<< cout;
            pull++;
        }
        if (s == "=") {
            cout << "FIFO: ";
            queue.Show();
            cout << "\n";
        }
        if (s == "?"){
            printf("Push function was called %d times", push);
            printf("\nPull function was called %d times", pull);
            break;
        }
    }
    return 0;
}