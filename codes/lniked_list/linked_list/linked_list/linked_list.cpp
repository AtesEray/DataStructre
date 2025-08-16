#include <iostream>
using namespace std;

// Node sýnýfý
class Node {
public:
    int data;     // Düðümde tutulacak veri
    Node* next;   // Sonraki düðümü iþaret eden pointer

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList sýnýfý
class LinkedList {
private:
    Node* head; // Listenin baþýný tutar

    int cntList(Node* temp) const{
        if (temp == nullptr) return 0;
        int a = cntList(temp->next);
        return a+1;
    }

    int cntSameValueList(Node* temp , int value) const {
        if (temp == nullptr) return 0;

        int cnt = cntSameValueList(temp->next, value);

        if (temp->data == value) return (cnt + 1);

        else return cnt;
    }

    Node* deleteNode(Node* temp,int value){
        if (temp == nullptr) return temp;

        if (temp->data == value) {
            Node* newNode = temp->next;
            delete temp;
            return newNode;
        }
        
        temp->next = deleteNode(temp->next, value);
        return temp;
    }

    
public:
    // Constructor (boþ liste ile baþlar)
    LinkedList() {
        head = nullptr;
    }

    int cntList() const {
        return cntList(head);
    }

    int cntSameValueList(int value) const {
        return cntSameValueList(head, value);
    }

    void deleteNode(int value){
        head = deleteNode(head, value);
    }

    // Yeni eleman ekleme (listenin sonuna)
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Listeyi yazdýrma
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor (dinamik bellek temizliði)
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.append(60);
    list.append(70);
    list.append(70);
    list.append(10);
    list.append(10);
    list.printList(); // Çýktý: 10 -> 20 -> 30 -> NULL

    cout<<list.cntList()<<endl;
    cout << list.cntSameValueList(70) << endl;

    list.deleteNode(70);
    list.printList();
    return 0;
}
