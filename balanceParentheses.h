#include "stack.h"
#include <iostream>

Stack parStack;

// check(string to be checked, length of string);
// Returns true if it's balanced, otherwise false
bool check(std::string arr)
{
    for (int i = 0; i < arr.length(); i++)
    {
        // If current character is an opening bracket
        if ((arr[i] == '{') || (arr[i] == '[') || (arr[i] == '('))
        {
            parStack.push(arr[i]);
        }
        else
        {
            switch (arr[i])
            {
            case '}':
                if (parStack.peek(false) == '{')
                    parStack.pop();
                break;
            case ']':
                if (parStack.peek(false) == '[')
                    parStack.pop();
                break;
            case ')':
                if (parStack.peek(false) == '(')
                    parStack.pop();
                break;
            }
        }
    }
    return parStack.top == -1;
}