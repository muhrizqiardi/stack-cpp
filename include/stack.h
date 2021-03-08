#include <iostream>

// Maximum stack index
#define MAX_STACK 100

// Stack class
class Stack
{

public:
    // Class Constructor
    // Initializing stack by setting the top = -1
    int top;
    Stack()
    {
        top = -1;
    }

    // An array for stack, with maximum index of MAX_STACK
    char stackArr[MAX_STACK];

    // Returns true if the stack is empty or if top == -1
    bool isEmpty();

    // Returns true if the stack is full or top == MAX_STACK - 1
    bool isFull();

    // Prints the top element of the stack
    char peek();

    // Inserts an element to the stack, returns false if the stack is full, returns true otherwise
    bool push(char item);

    // Removes an element to the stack, returns the popped item if the stack isn't empty, returns false otherwise
    char pop();
};

bool Stack::isEmpty()
{
    if (top <= -1)
    {
        return true;
    }
    else
        return false;
}

bool Stack::isFull()
{
    if (top >= MAX_STACK - 1)
    {
        return true;
    }
    else
        return false;
}

bool Stack::push(char item)
{
    if (!Stack::isFull())
    {
        stackArr[++top] = item;
        return true;
    }
    else
        return false;
}

char Stack::pop()
{
    if (!Stack::isEmpty())
    {
        int x = stackArr[top--];
        return x;
    }
    else
        return false;
}

char Stack::peek() {
    std::cout << "\n" << stackArr[top];
    return stackArr[top];
}
