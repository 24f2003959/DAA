#include "stack.h"
#include <iostream>
    Stack::Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void Stack::operator+(int x) {
        if (top == size - 1) {
            std::cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void Stack::operator--(int) {
        if (top == -1) {
            std::cout << "Stack underflow\n";
            return;
        }
        top--;
    }
    std::ostream& operator<<(std::ostream& os, const Stack& s) {
        os << "Stack elements: ";
        for (int i = 0; i <= s.top; i++) {
            os << s.arr[i] << " ";
        }
        return os;
    }
