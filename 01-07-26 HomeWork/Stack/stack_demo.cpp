#include <iostream>
#include "stack.h"

int main() {
    std::cout << "Integer Stack:\n";
    Stack<int> st(10);
    st + 10;
    st + 20;
    st + 30;
    std::cout << st;
    st--;
    st--;
    std::cout << st;

    std::cout << "\nDouble Stack\n";
    Stack<double> double_st(5);
    double_st + 3.14159;
    double_st + 2.71828;
    double_st + 1.61803;
    std::cout << double_st;
    double_st--;
    double_st--;
    std::cout << double_st;


    return 0;
}