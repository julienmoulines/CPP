#include "../includes/RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

int RPN::evaluate(const std::string& expr) {
    std::stack<int> stack;
    std::stringstream ss(expr);  // Convertit la chaîne en flux pour lire les tokens facilement
    std::string token;

    // Boucle principale : on lit chaque mot (séparé par un espace)
    while (ss >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            stack.push(token[0] - '0');  // convertit le caractère en int et push sur la stack
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
// On récupère les deux derniers éléments de la pile
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error: division by zero");
                	result = a / b;
            }
        stack.push(result);
        
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");

    return stack.top();
}
