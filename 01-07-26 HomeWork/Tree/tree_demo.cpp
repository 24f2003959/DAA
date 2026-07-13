#include <iostream>
#include "tree.h"

int main() {
    std::cout << "Integer Tree:\n";
    Tree<int> tr;
    tr + 50; tr + 30; tr + 70; tr + 20; tr + 40; tr + 60; tr + 80;
    std::cout << tr;
    tr--;
    tr--;    
    std::cout << tr;

    std::cout << "\nDouble Tree:\n";
    Tree<double> double_tr;
    
    double_tr + 3.14159; double_tr + 50.5; double_tr + 30.3; double_tr + 2.71828; double_tr + 80.8; double_tr + 75.5; double_tr + 1.61803;
    std::cout << double_tr;
    double_tr--;
    double_tr--;
    std::cout << double_tr;
    double_tr--;
    double_tr--;
    std::cout << double_tr;

    return 0;
}