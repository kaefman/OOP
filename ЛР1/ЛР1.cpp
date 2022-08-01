// Айрапетова Евгения М8о-206Б-19
#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3,14159265

using namespace std;

class Complex {	// z = r*(cos j + i sin j)
	double r_;
	double j_;
public:
	Complex() { r_ = 0; j_ = 0; };
	Complex(const double r, const double j) {
		r_ = r;
		j_ = j;
	}

	double& r() {
		return r_;
	}

	double& j() {
		return j_;
	}

	double r() const {
		return r_;
	}

	double j() const {
		return j_;
	}
};

double cos_(double x) { 
	double y;
	y = x * PI / 180.0;
	return cos(y); 
}

Complex operator+ (const Complex& first, const Complex& second) {
	double r, r1, r2, j1, j2;	// Результат r и промежуточные переменные (для удобства)
	if (second.j() >= first.j()) { j1 = first.j(), j2 = second.j(), r1 = first.r(), r2 = second.r(); }	// Присваивание промежуточным переменным значений
	else { j2 = first.j(), j1 = second.j(), r2 = first.r(), r1 = second.r(); }

	double j = j2 - ((j2 - j1) / 2);	// Угол суммарного вектора
	while (abs(j) > 180) { j = 360 - abs(j); };
	r = sqrt(pow(r1, 2) + pow(r2, 2) - 2 * r1 * r2 * cos_(j));
	return { r, j };
} // z1+z2 = r1*(cos j1 + i sin j1) + r2*(cos j2 + i sin j2) = r*(cos j + i sin j)

Complex operator- (const Complex& first, const Complex& second) {
	Complex a{ second.r(), (-90 - second.j()) };
	return { first + a };
}

Complex operator* (const Complex& first, const Complex& second) {
	double j = first.j() + second.j();
	while (abs(j) > 180) { j = 360 - abs(j); };
	return { first.r() * second.r(), j };
} // z1*z2 = r1*r2(cos(j1+j2) + i*sin(j1+j2))

Complex conj(Complex& a) {
	return { a.r(), -a.j() };
}

Complex operator/ (const Complex& first, const Complex& second) {
	double j = first.j() - second.j();
	while (abs(j) > 180) { j = 360 - abs(j); };
	return { first.r() / second.r(), j };
} // z1/z2 = (r1/r2)*(cos(j1-j2) + i*sin(j1-j2))

istream& operator>> (istream& input, Complex& z) {	// Ввод значения
	input >> z.r() >> z.j();
	return input;
}

ostream& operator<< (ostream& output, const Complex& z) {
	output << setprecision(4) << z.r() << " * (cos(" << z.j() << ") + i * sin(" << z.j() << "))";
	return output;
}

bool operator< (const Complex& first, const Complex& second) {
	return (first.r() < second.r());
}

bool operator<= (const Complex& first, const Complex& second) {
	return  (first.r() <= second.r());
}

bool operator> (const Complex& first, const Complex& second) {
	return  (first.r() > second.r());
}

bool operator>= (const Complex& first, const Complex& second) {
	return (first.r() >= second.r());
}

bool operator== (const Complex& first, const Complex& second) {
	return ((first.r() == second.r()) && (first.j() == second.j()));
}

bool operator!= (const Complex& first, const Complex& second) {
	return (!(first == second));
}

int main() {
	setlocale(LC_ALL, "rus");
	Complex a, b;
	cout << "Введите комплексные числа в формате <<Модуль, угол>>:\n";
	try
	{
		if (cin >> a >> b) {
			cout << "Считывание прошло успешно\n";

			Complex	add = a + b,
				sub = a - b,
				mul = a * b,
				div = a / b;

			cout << "a = " << a << '\n'
				<< "b = " << b << '\n'
				<< "a + b = " << add << '\n'
				<< "a - b = " << sub << '\n'
				<< "a * b = " << mul << '\n'
				<< "a / b = " << div << '\n';

			if (a == b) { cout << "a = b\n"; }
			else if (a > b) { cout << "a > b"; }
			else { cout << "a < b"; }
		}
		else {
			cout << "Ошибка ввода" << endl;
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}