#include <iostream>
#include <stack>

int main() {
    std::stack<int> stk;

    // Push elements onto the stack
    stk.push(1);
    stk.push(2);
    stk.push(3);

    // Display the top element
    std::cout << "Top element: " << stk.top() << std::endl; // Output: 3

    // Pop an element
    stk.pop();
    std::cout << "Top element after pop: " << stk.top() << std::endl; // Output: 2

    // Check if the stack is empty
    if (stk.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    // Display the size of the stack
    std::cout << "Size of stack: " << stk.size() << std::endl; // Output: 2

    return 0;
}
