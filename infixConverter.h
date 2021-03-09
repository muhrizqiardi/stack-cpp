#include <iostream>

// Checks if a character is an operator
bool oprCheck(char x)
{
    switch (x)
    {
    case '*':
    case '/':
    case '+':
    case '-':
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

// Bracket check

int bracketCheck(char x) {
    switch (x)
    {
    case '{':
    case '(':
        return 1;
        break;
    case '}':
    case ')':
        return 2;
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

// Precedence check
int precedenceCheck(char opr)
{
    switch (opr)
    {
    case '{':
    case '(':
    case '}':
    case ')':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

// Takes an argument of two operator character, returns true if the first char has higher precedence
bool hasHigherPrecedence(char a, char b)
{
    return precedenceCheck(a) > precedenceCheck(b);
}

// Converts infix expression to postfix
std::string infixToPostfix(std::string infixExp)
{
    CharStack stack;
    std::string postfixExp = ""; // String var to store the postfix expression after converted
    for (int i = 0; i < infixExp.length(); i++)
    {
        // If the current character is an operand
        if (!oprCheck(infixExp[i]))
        {
            postfixExp.push_back(infixExp[i]);
            postfixExp.push_back(' ');
        }
        // If the current character is an operator
        else if (oprCheck(infixExp[i]))
        {
            while (!stack.isEmpty() && hasHigherPrecedence(stack.peek(false), infixExp[i]) && bracketCheck(infixExp[i]) == 0)
            {
                postfixExp.push_back(stack.pop());
                postfixExp.push_back(' ');
            }
            stack.push(infixExp[i]);
        }
        // If the current character is not an operand or and operator
        else if (infixExp[i] == ' ')
            continue;
    }

    while (!stack.isEmpty())
    {
        postfixExp.push_back(stack.pop());
        postfixExp.push_back(' ');
    }
    return postfixExp;
}