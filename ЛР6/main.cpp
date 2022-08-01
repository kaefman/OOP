#include "figures.h"
#include "stack.h"
#include "allocator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T, class Alloc>
void remove_by_index(Stack<T, Alloc>& st, size_t idx) {
	auto it = st.begin();
	it = next(it, idx);
	st.erase(it);
}

template <typename T, class Alloc>
void print(const Stack<T, Alloc>& st) {
	for_each(st.begin(), st.end(), [](const auto& i) {cout << i << "\n"; });
}

int main() {
	setlocale(LC_ALL, "RUS");
	for (int test_count = 0;; ++test_count) {
		ifstream input("test" + to_string(test_count + 1) + ".txt");
		if (!input) {
			cerr << "Количество тестовых файлов: " << test_count << "\n";
			break;
		}

		cerr << "Тест №" << test_count + 1 << ":" << "\n\n";

		size_t count;
		size_t count_of_remove_requests;
		double target_square;
		input >> count >> count_of_remove_requests >> target_square;
		Stack<Square<double>, custom_allocator<Square<double>>> st;
		try {
			while (count-- > 0) {
				Square<double> sq;
				if (!(input >> sq)) {
					throw runtime_error("incorrect input");
				}
				st.push(sq);
			}
		}
		catch (exception & ex) {
			cerr << "Ошибка ввода на тесте " << test_count + 1 << ": " << ex.what() << "\n" << endl;
			continue;
		}

		cout << "Стек:\n";
		print(st);
		cout << count_if(st.begin(), st.end(), [target_square](const auto& figure) {return S(figure) < target_square; });
		cout << " фигур(ы) с площадью, меньше чем " << target_square << "\n";

		try {
			while (count_of_remove_requests-- > 0) {
				size_t idx;
				if (!(input >> idx)) {
					throw runtime_error("incorrect input for remove");
				}
				remove_by_index(st, idx);
			}
		}
		catch (exception & ex) {
			cerr << "Ошибка ввода на тесте " << test_count + 1 << ": " << ex.what() << "\n" << endl;
			continue;
		}
		cout << "Результат после удаления этих фигур: " << target_square << ":\n";
		print(st);
		cout << "\n";

//		cerr << "Конец ввода теста " << test_count + 1 << "\n\n";
	}

	return 0;
}