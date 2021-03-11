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

// Parentheses check
// If the argument is an opening parentheses char return 1, if it's a closing parentheses return 2, otherwise return 0
int parCheck(char x)
{
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

        // Loop count logger
        std::cout << "\nloop " << i << "\n";

        // If the current character is an operand (not an operator or a parentheses)
        if (!oprCheck(infixExp[i]) && parCheck(infixExp[i]) == 0)
        {
            postfixExp.push_back(infixExp[i]);
        }

        // If the current character is an operator
        else if (oprCheck(infixExp[i]))
        {

            // Pop the stack until the top element of the stack is a parentheses
            while (!stack.isEmpty() && parCheck(stack.peek(false)) == 0 && hasHigherPrecedence(stack.peek(false), infixExp[i]))
            {
                postfixExp.push_back(stack.pop());
            }

            // Push the operator to the stack
            stack.push(infixExp[i]);
        }

        // If the current character is an opening parentheses
        else if (parCheck(infixExp[i]) == 1)
        {
            stack.push(infixExp[i]);
        }

        // If the current character is an closing parentheses
        else if (parCheck(infixExp[i]) == 2)
        {

            // Pop the stack and push it to string until the top element of the stack is a parentheses
            while (!stack.isEmpty() && parCheck(stack.peek(false)) == 0)
            {
                postfixExp.push_back(stack.pop());
            }

            // Remove the parentheses on the top of the stack
            if (parCheck(stack.peek(false)) > 0) {
                stack.pop();
            }

        }

        // If the current character is not an operand or and operator
        else if (infixExp[i] == ' ')
            continue;
    }

    // Emptying the stack as the final step of the algorithm
    while (!stack.isEmpty())
    {
        if (parCheck(stack.peek(false)) > 0)
        {
            stack.pop();
        }
        else 
        {
            postfixExp.push_back(stack.pop());
        }
            
    }
    return postfixExp;
}

// Convert infix to prefix expressions
std::string infixToPrefix();