#include <iostream>
using namespace std;
#include <stack>

class Node {
        public:
        int data;
        Node* next;
        Node* Previous;


                        Node(int data){
                    this->data = data;
                    this->next = nullptr;
                    this->Previous = nullptr;
                }

Node(int data,Node* next,Node* Previous){
        this->data = data;
        this->next = next;
        this->Previous = Previous;
    }


};

Node* convertAll2Arr(int array[],int size);
void printDLL(Node* Head);
void freeLinkedList(Node* Head);
int main(){
int array[] = {55,97,89,56,67};
Node* H = convertAll2Arr(array,5);
printDLL(H);
freeLinkedList(H);
return 0;


}


Node* convertAll2Arr(int array[],int size){
    Node* Head = new Node(array[0]);
    Node* prev = Head;
    for(int i=1;i<size;i++){
        Node* temp = new Node(array[i]);
        prev->next = temp;
        temp->Previous = prev;
        prev = prev->next;
    }

    return Head;
}

void printDLL(Node* Head){
    Node* temp = Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void freeLinkedList(Node* Head) {
    Node* temp;

    while (Head != nullptr) {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
}

Node* reverseDLL(Node* Head){
    Node* temp = Head;
    stack<int> tempStack;

    while (temp!=NULL) {
        tempStack.push(temp->data);
        temp= temp->next;

    }

    temp = Head;
while(temp!=NULL){
    temp->data = tempStack.top();
    tempStack.pop();
    temp = temp->next;
}

return Head;
}

Node* swappingDDL(Node* Head){
    Node* Current = Head;
    while(Current!=NULL){
        Node* Last = Current->Previous;
        Current->Previous = Current->next;
        Current->next = Last;
        Current = Current->Previous;
    }

    return Current->Previous;
}
