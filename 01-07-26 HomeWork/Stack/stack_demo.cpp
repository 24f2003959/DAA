#include<iostream>
#include "stack.h"
int main() {
    Stack st(10);
    st+10;
    st+20;
    st+30;
    std::cout<<st;
    st--;
    st--;
    std::cout<<st;
    return 0;
}