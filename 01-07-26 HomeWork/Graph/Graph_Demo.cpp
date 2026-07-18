#include <iostream>
#include "Graph.h"

int main() {
    Graph<int> g(5);

    std::cout << "Insert elements:\n";
    g + 10;
    g + 20;
    g + 30;
    g + 40;
    std::cout << g;

    std::cout << "\nDelete element 30:\n";
    g - 30;
    std::cout << g;

    std::cout << "\nInsert element 50:\n";
    g + 50;
    std::cout << g;

    return 0;
}
