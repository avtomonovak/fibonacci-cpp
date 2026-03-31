#include <iostream>
#include <string>
#include <cctype>
#include <chrono>

class FibonacciCalculator {
public:
    static long long calculate(int n) {
        if (n < 0) {
            throw std::invalid_argument("Число не может быть отрицательным");
        }
        if (n > 50) {
            throw std::invalid_argument("Число слишком велико (максимум 50)");
        }
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long long prev = 0;
        long long curr = 1;
        long long next;
        
        for (int i = 2; i <= n; ++i) {
            next = prev + curr;
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
    
    static bool isValidNumber(const std::string& str, int& result) {
        if (str.empty()) return false;
        
        for (char c : str) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        
        try {
            result = std::stoi(str);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }
};

int main() {
    std::cout << "=== Программа вычисления чисел Фибоначчи ===" << std::endl;
    
    std::string input;
    int n;
    
    while (true) {
        std::cout << "Введите n (0-50): ";
        std::getline(std::cin, input);
        
        if (FibonacciCalculator::isValidNumber(input, n) && n >= 0 && n <= 50) {
            break;
        }
        std::cout << "Ошибка! Введите число от 0 до 50." << std::endl;
    }
    
    try {
        auto start = std::chrono::high_resolution_clock::now();
        long long result = FibonacciCalculator::calculate(n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
        std::cout << "Время: " << duration.count() << " мкс" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}