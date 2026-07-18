#include <iostream>

template <typename T>
class Graph {
private:
    int size;
    int count;
    T *arr;

public:
    Graph(int size) {
        this->size = size;
        count = 0;
        arr = new T[size];
    }

    void operator+(T x) {
        if (count == size) {
            std::cout << "Graph overflow\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            if (arr[i] == x) {
                std::cout << "Element already exists\n";
                return;
            }
        }
        arr[count++] = x;
    }

    void operator-(T x) {
        int pos = -1;
        for (int i = 0; i < count; i++) {
            if (arr[i] == x) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            std::cout << "Element not found\n";
            return;
        }
        for (int i = pos; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph<T>& g) {
        os << "DFS: ";
        for (int i = 0; i < g.count; i++) {
            os << g.arr[i] << " ";
        }
        os << "\nBFS: ";
        for (int i = 0; i < g.count; i++) {
            os << g.arr[i] << " ";
        }
        os << "\n";
        return os;
    }
};
