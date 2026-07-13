#include <iostream>
template <typename T>
class Queue {
public:
    int size;
    int front;
    int rear;
    T *arr;
    Queue(int size) {
        this->size = size;
        arr = new T[size];
        front = -1;
        rear = -1;
    }
    void operator+(T x) {
        if (rear == size - 1) {
            std::cout << "Queue overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = x;
    }
    void operator--(int) {
        if (front == -1 || front > rear) {
            std::cout << "Queue underflow\n";
            return;
        }
        front++;
    }
    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
        os << "Queue elements: ";
        if (q.front != -1 && q.front <= q.rear) {
            for (int i = q.front; i <= q.rear; i++) {
                os << q.arr[i] << " ";
            }
        }
        os << "\n";
        return os;
    }
};