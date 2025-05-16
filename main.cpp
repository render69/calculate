#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Entry{
    std::string action;
    double result;
};

double calculate(double a, char op, double b, bool& error){
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0){
                error = true;
                return 0;
            } 
            return a / b;
            
        default: 
            error = true;
            return 0;
    }
}

int main(){
    std::vector<Entry> history;
    std::string input;

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|   Добро пожаловать в калькулятор        |" << std::endl;
    std::cout << "|   Доступные действия: +, -, *, /        |" << std::endl;
    std::cout << "|   Пример ввода: 2 + 2                   |" << std::endl;
    std::cout << "|   Выход из калькулятора: q              |" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;



    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "q") break;
        if (input == "history"){
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "------------------История------------------" << std::endl;
            std::cout << "-------------------------------------------" << std::endl;

            for (const auto& e : history){
                std::cout << e.action << " = " << e.result << std::endl;
            }
            std::cout << "-------------------------------------------" << std::endl;
            continue;
            
        } 

        std::stringstream ss(input);
        double a, b;
        char op;
        ss >> a >> op >> b;

        bool error = false;
        double result = calculate(a, op, b, error);

        if (error)
            std::cout << "Ошибка в выражении!" << std::endl;
        else {
            std::cout << "Результат: " << result << std::endl;
            history.push_back({input, result});
        }

    }
}