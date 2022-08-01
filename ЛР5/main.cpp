#include "square.hpp"
#include "stack.hpp"
#include <iostream>

int main() {
	unsigned int input;
	std::cout << "1. Push\n2. Pop\n3. Top element\n4. Count elements\n5. Number of shapes with an area less than 100\n6. End\n";
	Stack<Square<int>> stack;
	int task = 0;
	while (std::cin >> input) {
		if (input == 1) {
			Square<int> s;
			std::cin >> s;
			stack.push(s);
			if (S(s) < 100) { ++task; }
			std::cout << "Success" << std::endl;
		}
		else if (input == 2) {
			if (!stack.empty()) {
				if (S(stack.top()) < 100) { --task; }
				stack.pop();
				std::cout << "Success" << std::endl;
			}
			else { std::cout << "Error: stack is empty" << std::endl; }
		}
		else if (input == 3) {
			std::cout << "Top element is " << stack.top() << std::endl;
		}
		else if (input == 4) {
			std::cout << "Number of elements is " << stack.size() << std::endl;
		}
		else if (input == 5) {
			std::cout << "Area less then 100: " << task << std::endl;
		}
		else if (input == 6) {
			std::cout << "Goodbye!" << std::endl;
			return 0;
		}
		else {
			std::cout << "Error of input";
		}
	}
}
