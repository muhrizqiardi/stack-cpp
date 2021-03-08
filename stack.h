#include <iostream>

// Maximum stack index
#define MAX_STACK 100

// CharStack class
// A stack with char type as elements
class CharStack
{

public:
    // Class Constructor
    // Initializing stack by setting the top = -1
    int top;
    CharStack()
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
    // If the argument is false, then the function won't output the element through console
    char peek(bool print);

    // Inserts an element to the stack, returns false if the stack is full, returns true otherwise
    bool push(char item);

    // Removes an element to the stack, returns the popped item if the stack isn't empty, returns false otherwise
    char pop();
};

bool CharStack::isEmpty()
{
    if (top <= -1)
    {
        return true;
    }
    else
        return false;
}

bool CharStack::isFull()
{
    if (top >= MAX_STACK - 1)
    {
        return true;
    }
    else
        return false;
}

bool CharStack::push(char item)
{
    if (!CharStack::isFull())
    {
        stackArr[++top] = item;
        return true;
    }
    else
        return false;
}

char CharStack::pop()
{
    if (!CharStack::isEmpty())
    {
        int x = stackArr[top--];
        return x;
    }
    else
        return false;
}

char CharStack::peek(bool print) {
    if (print) std::cout << "\n" << stackArr[top] << "\n";
    return stackArr[top];
}

// IntStack Class
// A stack with integer type as elements
class IntStack
{

public:
    // Class Constructor
    // Initializing stack by setting the top = -1
    int top;
    IntStack()
    {
        top = -1;
    }

    // An array for stack, with maximum index of MAX_STACK
    int stackArr[MAX_STACK];

    // Returns true if the stack is empty or if top == -1
    bool isEmpty();

    // Returns true if the stack is full or top == MAX_STACK - 1
    bool isFull();

    // Prints the top element of the stack
    // If the argument is false, then the function won't output the element through console
    int peek(bool print);

    // Inserts an element to the stack, returns false if the stack is full, returns true otherwise
    bool push(int item);

    // Removes an element to the stack, returns the popped item if the stack isn't empty, returns false otherwise
    int pop();
};

bool IntStack::isEmpty()
{
    if (top <= -1)
    {
        return true;
    }
    else
        return false;
}

bool IntStack::isFull()
{
    if (top >= MAX_STACK - 1)
    {
        return true;
    }
    else
        return false;
}

bool IntStack::push(int item)
{
    if (!IntStack::isFull())
    {
        stackArr[++top] = item;
        return true;
    }
    else
        return false;
}

int IntStack::pop()
{
    if (!IntStack::isEmpty())
    {
        int x = stackArr[top--];
        return x;
    }
    else
        return false;
}

int IntStack::peek(bool print)
{
    if (print)
        std::cout << "\n"
                  << stackArr[top];
    return stackArr[top];
}
