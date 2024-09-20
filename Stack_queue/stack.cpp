#include <iostream>

#define SIZE 10

class Stack {
    int top = -1;

public:
    int a[SIZE];

    void Push(int data) {
        if (top == SIZE - 1) {
            std::cout << "Stack is full" << std::endl;
        } else {
            top++;
            a[top] = data;
            std::cout << data << " pushed onto stack" << std::endl;
        }
    }

    void Pop() {
        if (top == -1) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            std::cout << a[top] << " popped from stack" << std::endl;
            top--;
        }
    }

    void Display() {
        if (top == -1) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            std::cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Stack stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Display();

    stack.Pop();
    stack.Display();

    return 0;
}
