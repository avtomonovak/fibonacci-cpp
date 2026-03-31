#include <iostream>
#include <cassert>
#include <stdexcept>

class FibonacciCalculator {
public:
    static long long calculate(int n) {
        if (n < 0) throw std::invalid_argument("n < 0");
        if (n > 50) throw std::invalid_argument("n > 50");
        
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

void test_basic() {
    std::cout << "Тест 1: Базовые значения... ";
    assert(FibonacciCalculator::calculate(0) == 0);
    assert(FibonacciCalculator::calculate(1) == 1);
    assert(FibonacciCalculator::calculate(2) == 1);
    assert(FibonacciCalculator::calculate(3) == 2);
    std::cout << "OK" << std::endl;
}

void test_known() {
    std::cout << "Тест 2: Известные значения... ";
    assert(FibonacciCalculator::calculate(5) == 5);
    assert(FibonacciCalculator::calculate(10) == 55);
    assert(FibonacciCalculator::calculate(20) == 6765);
    std::cout << "OK" << std::endl;
}

void test_edge() {
    std::cout << "Тест 3: Граничные значения... ";
    assert(FibonacciCalculator::calculate(50) == 12586269025LL);
    std::cout << "OK" << std::endl;
}

void test_negative() {
    std::cout << "Тест 4: Отрицательные значения... ";
    try {
        FibonacciCalculator::calculate(-1);
        assert(false);
    } catch (const std::invalid_argument&) {
        std::cout << "OK" << std::endl;
    }
}

void test_too_large() {
    std::cout << "Тест 5: Слишком большие значения... ";
    try {
        FibonacciCalculator::calculate(51);
        assert(false);
    } catch (const std::invalid_argument&) {
        std::cout << "OK" << std::endl;
    }
}

int main() {
    std::cout << "=== Запуск тестов ===" << std::endl;
    test_basic();
    test_known();
    test_edge();
    test_negative();
    test_too_large();
    std::cout << "=== Все тесты пройдены! ===" << std::endl;
    return 0;
}