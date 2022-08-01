// Айрапетова Евгения М8о-206Б-19

/*
Создать класс vector3D, задаваемый тройкой координат. Обязательно должны быть реализованы: операции сложения и вычитания векторов,
векторное произведение векторов, скалярное произведение векторов, умножения на скаляр, сравнение векторов на совпадение, вычисление
длины вектора, сравнение длины векторов, вычисление угла между векторами.
Операции сложения, вычитания, сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов.
Необходимо реализовать пользовательский литерал для работы с константами типа vector3D.
*/

#include <iostream>
#define PI 3.1415926535

using namespace std;

class Vector3D {
	double x_, y_, z_;
public:
	Vector3D() { x_ = 0; y_ = 0; z_ = 0; };
	Vector3D(double x, double y, double z) {
		x_ = x;
		y_ = y;
		z_ = z;
	}

	double& x() { return x_; }
	double& y() { return y_; }
	double& z() { return z_; }
	double x() const { return x_; }
	double y() const { return y_; }
	double z() const { return z_; }
};


Vector3D operator+ (const Vector3D& a, const Vector3D& b) {
	return { a.x() + b.x(), a.y() + b.y(), a.z() + b.z() };
}

Vector3D operator- (const Vector3D& a, const Vector3D& b) {
	return { a.x() - b.x(), a.y() - b.y(), a.z() - b.z() };
}

Vector3D operator* (const Vector3D& a, const Vector3D& b) { // Векторное произведение векторов
	return { (a.y() * b.z()) - (b.y() * a.z()), (b.x() * a.z()) - (a.x() * b.z()), (a.x() * b.y()) - (b.x() - a.y()) };
}

Vector3D operator* (const Vector3D& x, const double& a) { // Умножение вектора на скаляр
	return { x.x() * a, x.y() * a, x.z() * a };
}

double ScalarProduct (const Vector3D& a, const Vector3D& b) { // Скалярное произведение векторов
	return { a.x() * b.x() + a.y() * b.y() + a.z() * b.z() };
}

double length(Vector3D a) {		// Длина вектора
	return (sqrt((a.x() * a.x()) + (a.y() * a.y()) + (a.z() * a.z())));
}

bool operator== (const Vector3D& a, const Vector3D& b) {
	return { (a.x() == b.x()) && (a.y() == b.y()) && (a.z() == b.z()) };
}

bool operator!= (const Vector3D& a, const Vector3D& b) {
	return { !(a == b) };
}

bool operator< (const Vector3D& a, const Vector3D& b) {
	return { length(a) < length(b) };
}

bool operator<= (const Vector3D& a, const Vector3D& b) {
	return { length(a) <= length(b) };
}

bool operator> (const Vector3D& a, const Vector3D& b) {
	return { length(a) > length(b) };
}

bool operator>= (const Vector3D& a, const Vector3D& b) {
	return { length(a) >= length(b) };
}

double corner(const Vector3D& a, const Vector3D& b) {	// Угол между двумя векторами
	double c = ScalarProduct(a, b) / (length(a) * length(b));
	return (acos(c) * PI) / 180;
}

istream& operator>> (istream& input, Vector3D& v) {	
	input >> v.x() >> v.y() >> v.z();
	return input;
}

ostream& operator<< (ostream& output, const Vector3D& v) {
	output << "x = " << v.x() << '\n';
	output << "y = " << v.y() << '\n';
	output << "z = " << v.z() << '\n';
	return output;
}

double operator"" _m(const long double val) {		// Пользовательский литерал для метров
	return val;
}

double operator"" _ft(const long double val) {		// Пользовательский литерал для футов
	return (val / 3.28);
}

int main() {
	setlocale(LC_ALL, "rus");
	Vector3D a{ 3.28_ft, 6.56_ft, 6.56_ft }, b{ 2.0_m, 2.0_m, 1.0_m };
	double n = 3.5;
	try {
		cout << "Вектор a:\n" << a << "\nВектор b:\n" << b;
		cout << "\nСумма a + b:\n" << a + b;
		cout << "\nРазность a - b:\n" << a - b;
		cout << "\nВекторное произведение a * b:\n" << a * b;
		cout << "\nСкалярное произведение a & b:" << ScalarProduct(a, b);
		cout << "\nУмножение вектора a на скаляр n:\n" << a * n;
		cout << "\nДлина вектора a: " << length(a);
		cout << "\nДлина вектора b: " << length(b) << '\n';

		if (a > b) { cout << "a > b"; }
		else if (a < b) { cout << "a < b"; }
		else { cout << "a = b"; }
	}
	catch (const exception & ex) {
		cout << ex.what() << endl;
	}
}