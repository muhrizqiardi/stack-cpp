// #include "stack.h"
#include <iostream>

// Convert char type to int by substracting 48
int charToInt(char x)
{
    return x - 48;
}

// Perform the expression
// perform(operator, operand1, operand 2)
int perform(char opr, int op1, int op2)
{
    switch (opr)
    {
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    }
    return 0;
}

// Evaluate Postfix expression
// Argument is string exp
int evaluatePostfix(std::string exp)
{
    CharStack stack;
    for (int i = 0; i < exp.length(); i++)
    {
        // If current character is space
        if (exp[i] == ' ' || exp[i] == ',')
            continue;

        // If current character is an operand
        if ((exp[i] >= 48 && exp[i] <= 57))
        {
            stack.push(charToInt(exp[i]));
        }

        // If current character is an operator
        else    
        {
            int op2 = stack.pop();               // First operand
            int op1 = stack.pop();               // Second operand
            int res = perform(exp[i], op1, op2); // Result of operation of first and second operand
            stack.push(res);
        }
    }
    return stack.peek(false);
}