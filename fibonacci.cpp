#include <iostream>
#include <string>
#include <cctype>

class FibonacciCalculator {
public:
    static long long calculate(int n) {
        if (n < 0) {
            throw std::invalid_argument("n must be non-negative");
        }
        if (n > 50) {
            throw std::invalid_argument("n too large (max 50)");
        }
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long long prev = 0, curr = 1;
        for (int i = 2; i <= n; ++i) {
            long long next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};

int main() {
    std::cout << "=== Fibonacci Calculator ===" << std::endl;
    std::cout << "Enter n (0-50): ";
    
    int n;
    std::cin >> n;
    
    try {
        long long result = FibonacciCalculator::calculate(n);
        std::cout << "F(" << n << ") = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
