#include <cstddef>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};


Node* ConvertArr2LL(int array[], int size);
int countElement(Node* Head);
void printLL(Node* Head);
void freeLinkedList(Node* Head);
int find(Node* Head, int target);
Node* RemoveHead(Node* Head);
Node* RemoveTail(Node* Head);
Node* deleteKelement(Node* Head, int k);
Node* InsertAtHead(Node* Head, int k);
Node* InsertAtTail(Node* Head, int k);

int main() {
    int array[] = {5, 10, 15, 23, 10, 27, 90};
    Node* H = ConvertArr2LL(array, 7);

    cout << "[";
    printLL(H);
    cout << "]" << endl;

    int ans = find(H, 15);
    cout << "Element found: " << ans << endl;

    H = deleteKelement(H, 5);
    Node* NewHead = InsertAtHead(H, 89);
    Node* NewTail = InsertAtTail(NewHead, 99);

    cout << "Modified List: [";
    printLL(NewHead);
    cout << "]" << endl;

    freeLinkedList(NewHead);

    return 0;
}

Node* ConvertArr2LL(int array[], int size) {
    if (size == 0) return nullptr;

    Node* Head = new Node(array[0]);
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
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
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

Node* RemoveHead(Node* Head) {
    if (Head == nullptr || Head->next == nullptr) return nullptr;

    Node* temp = Head;
    Head = Head->next;
    delete temp;

    return Head;
}

Node* RemoveTail(Node* Head) {
    if (Head == nullptr || Head->next == nullptr) return nullptr;

    Node* temp = Head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return Head;
}

Node* deleteKelement(Node* Head, int k) {
    if (Head == nullptr) return nullptr;
    if (k == 1) {
        return RemoveHead(Head);
    }

    int count = 1;
    Node* temp = Head;
    Node* prev = nullptr;

    while (temp != nullptr && count < k) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
    }

    return Head;
}

Node* InsertAtHead(Node* Head, int k) {
    Node* NewHead = new Node(k, Head);
    return NewHead;
}

Node* InsertAtTail(Node* Head, int k) {
    if (Head == nullptr) {
        return new Node(k);
    }

    Node* temp = Head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node(k);
    return Head;
}
