#include <iostream>

template <typename T>
class Stack {
public:
    int size;
    int top;
    T *arr;

    Stack(int size) {
        this->size = size;
        arr = new T[size];
        top = -1;
    }
    void operator+(T x) {
        if (top == size - 1) {
            std::cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void operator--(int) {
        if (top == -1) {
            std::cout << "Stack underflow\n";
            return;
        }
        top--;
    }
    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
        os << "Stack elements: ";
        for (int i = 0; i <= s.top; i++) {
            os << s.arr[i] << " ";
        }
        os << "\n";
        return os;
    }
};