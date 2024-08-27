#include <cstddef>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


Node* ConvertArr2LL(int array[], int size);
int countElement(Node* Head);
void printLL(Node* Head);
void freeLinkedList(Node* Head);
int find(Node* Head, int target);
Node*  RemoveHead(Node* Head);

int main() {
    int array[] = {5, 10, 15, 23};
    Node* H = ConvertArr2LL(array, 4);

    cout << "[";
    printLL(H);
    cout << "]" << endl;

    int ans = find(H, 15);
    cout << ans << endl;

    freeLinkedList(H);

    return 0;
}

Node* ConvertArr2LL(int array[], int size) {
    if (size == 0) return nullptr;
    Node* Head = new Node(array[0], nullptr);
    Node* Mover = Head;

    for (int i = 1; i < size; i++) {
        Node* temp = new Node(array[i]);
        Mover->next = temp;
        Mover = temp;
    }

    return Head;
}

int countElement(Node* Head) {
    int count = 0;
    Node* temp = Head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

void printLL(Node* Head) {
    Node* temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void freeLinkedList(Node* Head) {
    Node* temp;
    while (Head != nullptr) {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
}

int find(Node* Head, int target) {
    Node* temp = Head;
    while (temp) {
        if (temp->data == target) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

Node*  RemoveHead(Node* Head){
    if(Head==NULL || Head->next==NULL)return NULL;

    Node* temp = Head;
    Head = Head->next;
    delete temp;

    return Head;
}

Node* RemoveTail(Node* Head){
    if(Head==NULL || Head->next==NULL)return NULL;
    Node* temp = Head;
    while(temp->next->next!=nullptr){
        temp = temp->next;

    }
    delete temp->next;
    temp->next = nullptr;
    return Head;
}
