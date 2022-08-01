#pragma once

template <typename T>
class Stack
{
private:
	struct Node {
		Node* prevElement; // указатель на предыдущий элемент стека
		T value;
		Node() {
		}
		Node(T val) {
			value = val;
			prevElement = NULL;
		}
	};

	Node* topElement = new Node();
	int count;
public:
	/*class StackIterator {
	private:
		Stack& stack;
		size_t  index;
		friend class Stack;
	public:
		StackIterator(Stack& l, int i) : stack(l), index(i) {}

		StackIterator& operator++() {
			++index;
			return *this;
		}

		T operator*() {
			return stack[index];
		}

		T* operator->() {
			return &stack[index];
		}

		bool operator!=(const StackIterator& other) {
			if (index != other.index) return true;
			if (&stack != &(other.stack)) return true;
			return false;
		}

		bool operator==(const StackIterator& other) {
			if (index != other.index) return false;
			if (&stack != &(other.stack)) return false;
			return true;
		}

	};*/

	Stack() {
		count = 0;
	}
	~Stack() {}

	bool empty() {
		return (count == 0);
	}

	int size() {
		return count;
	}

	void push(T value) {
		Node* newElement = new Node(value);
		if (count == 0) {
			topElement = newElement;
		}
		else {
			newElement->prevElement = topElement;
			topElement = newElement;
		}
		++count;
	}

	//возвращаем верхний элемент стека
	T top() {
		return topElement->value;
	}

	/*StackIterator begin() {
		return(StackIterator(*this, 0));
	}

	StackIterator end() {
		return (StackIterator(*this, count));
	}*/

	void pop() {
		if (!empty()) {
			Node* temp = topElement;
			topElement = topElement->prevElement;
			delete temp;
			--count;
		}
		else {
			std::cout << "The stack is empty!" << std::endl;
		}
	}
};

