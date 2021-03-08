#include "balanceParentheses.h"
#include<iostream>

main() {
    std::cout << "Balanced parentheses check: \n";
    std::cout << "()[]{()} is balanced is " << (check("()[]{()}") ? "true" : "false") << "\n"; // Will output "true"
    std::cout << "[(1+1]*2+3) is balanced is " << (check("[(1+1]*2+3)") ? "true" : "false") << "\n"; // Will output "false"
    std::cout << "[(x+y)*(3+z)]+(2*x) is balanced is " << (check("[(x+y)*(3+z)]+(2*x)") ? "true" : "false") << "\n"; // Will output "true"
    std::cout << "\nInfix, postfix, and prefix: \n";
}