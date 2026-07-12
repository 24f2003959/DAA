#include <ostream>
class Stack {
    public:
        int size;
        int top;
        int *arr;
        Stack(int);
        void operator+(int);
        void operator--(int);
        friend std::ostream& operator<<(std::ostream& os, const Stack& s);
};