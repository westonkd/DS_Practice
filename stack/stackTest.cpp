#include <iostream>
#include <string>
#include "stack.h"
#include "../testing/expect.h"

int main() {
    // TODO: write some real tests
    Custom::Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack << "\n";

    Custom::Stack<int> stackTwo(stack);
    stackTwo.push(4);

    std::cout << stackTwo;

    return 0;
}