#include <iostream>
using namespace std;

// ===================== STACK NODE =====================
struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

// ===================== STACK =====================
class Stack {
private:
    SNode* top; // en üstteki eleman
public:
    Stack() : top(nullptr) {}

    void push(int val) {
        SNode* newNode = new SNode(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack bos!" << endl;
            return 0;
        }
        SNode* temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Stack bos!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void print() const {
        SNode* current = top;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
};

// ===================== QUEUE NODE =====================
struct QNode {
    int data;
    QNode* next;
    QNode(int val) : data(val), next(nullptr) {}
};

// ===================== QUEUE =====================
class Queue {
private:
    QNode* front;
    QNode* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        QNode* newNode = new QNode(val);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue bos!" << endl;
            return 0 ;
        }
        QNode* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr; // tamamen bosaldi
        int data = temp->data;
        delete temp;
        return data;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Queue bos!" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void print() const {
        QNode* current = front;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};
// it checks if queue is palindrome with using stack and queue.
int isPalindrome(Queue* q) {
    Stack* sTemp = new Stack();
    Queue* qTemp = new Queue();

    while (!q->isEmpty()) {
        int data = q->dequeue();
        sTemp->push(data);
        qTemp->enqueue(data);
    }
    while (!sTemp->isEmpty()) {
        if (sTemp->pop() != qTemp->dequeue()) return 0;
    }
    return 1;
}
// ===================== MAIN =====================

int counterOfLastWord(Queue* q) {
    int cnt = 0;
    int last= 0;
    Queue qTemp;
    while (!q->isEmpty()) {
        last = q->dequeue();
        qTemp.enqueue(last);
    }
    while (!qTemp.isEmpty()) {
        int data = qTemp.dequeue();
        q->enqueue(data);
        if (data == last) cnt++;
    }
    return cnt;
}


int main() {
    // STACK TEST
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout << "Pop: " << s.pop() << endl;
    
    s.print();

    // QUEUE TEST
    Queue q;
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(2);
    q.print();


    cout<<"number of times that the last character of the line appeared somewhere in this line:" << counterOfLastWord(&q) << endl;
    q.print();
    return 0;
}
