#include <iostream>

// check(string to be checked, length of string);
// Returns true if it's balanced, otherwise false
bool check(std::string arr)
{
    CharStack parStack;
    for (int i = 0; i < arr.length(); i++)
    {
        // [()()]()
        // If current character is an opening bracket
        switch (arr[i])
        {
        case '{':
        case '[':
        case '(':
            parStack.push(arr[i]);
            break;
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
        default:
            continue;
            break;
        }
    }
    return parStack.top == -1;
}