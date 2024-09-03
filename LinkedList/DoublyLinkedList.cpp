#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }

    Node(int data, Node* next, Node* previous) {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
};

Node* convertArr2DLL(int array[], int size);
void printDLL(Node* head);
void freeLinkedList(Node* head);
Node* reverseDLL(Node* head);
Node* swappingDLL(Node* head);

int main() {
    int array[] = {55, 97, 89, 56, 67};
    Node* head = convertArr2DLL(array, 5);
    printDLL(head);
    freeLinkedList(head);
    return 0;
}

Node* convertArr2DLL(int array[], int size) {
    Node* head = new Node(array[0]);
    Node* prev = head;
    for (int i = 1; i < size; i++) {
        Node* temp = new Node(array[i]);
        prev->next = temp;
        temp->previous = prev;
        prev = prev->next;
    }
    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

Node* reverseDLL(Node* head) {
    Node* temp = head;
    stack<int> tempStack;

    while (temp != nullptr) {
        tempStack.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr) {
        temp->data = tempStack.top();
        tempStack.pop();
        temp = temp->next;
    }

    return head;
}

Node* swappingDLL(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* last = current->previous;
        current->previous = current->next;
        current->next = last;
        current = current->previous;
    }
    return current != nullptr ? current->previous : nullptr;
}
