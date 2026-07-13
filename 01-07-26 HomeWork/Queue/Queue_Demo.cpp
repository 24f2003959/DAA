#include <iostream>
#include "queue.h"

int main() {
    std::cout << "Integer Queue:\n";
    Queue<int> q(5);
    q + 10;
    q + 20;
    q + 30;
    q + 40;
    std::cout << q;
    q--;
    q--;
    std::cout << q;
    q + 50;
    q--;
    q + 60;
    q--;
    std::cout << q;
    q--;

    std::cout << "\nChar Queue:\n";
    Queue<char> char_q(5);
    char_q + 'A';
    char_q + 'B';
    char_q + 'C';
    char_q + 'D';
    char_q + 'E';
    std::cout << char_q;
    char_q--;
    char_q--;
    std::cout << char_q;

    return 0;
}