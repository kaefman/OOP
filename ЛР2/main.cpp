// ���������� ������� �8�-206�-19

/*
������� ����� vector3D, ���������� ������� ���������. ����������� ������ ���� �����������: �������� �������� � ��������� ��������,
��������� ������������ ��������, ��������� ������������ ��������, ��������� �� ������, ��������� �������� �� ����������, ����������
����� �������, ��������� ����� ��������, ���������� ���� ����� ���������.
�������� ��������, ���������, ��������� (�� ���������, ������ � ������) ������ ���� ��������� � ���� ���������� ����������.
���������� ����������� ���������������� ������� ��� ������ � ����������� ���� vector3D.
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

Vector3D operator* (const Vector3D& a, const Vector3D& b) { // ��������� ������������ ��������
	return { (a.y() * b.z()) - (b.y() * a.z()), (b.x() * a.z()) - (a.x() * b.z()), (a.x() * b.y()) - (b.x() - a.y()) };
}

Vector3D operator* (const Vector3D& x, const double& a) { // ��������� ������� �� ������
	return { x.x() * a, x.y() * a, x.z() * a };
}

double ScalarProduct (const Vector3D& a, const Vector3D& b) { // ��������� ������������ ��������
	return { a.x() * b.x() + a.y() * b.y() + a.z() * b.z() };
}

double length(Vector3D a) {		// ����� �������
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

double corner(const Vector3D& a, const Vector3D& b) {	// ���� ����� ����� ���������
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

double operator"" _m(const long double val) {		// ���������������� ������� ��� ������
	return val;
}

double operator"" _ft(const long double val) {		// ���������������� ������� ��� �����
	return (val / 3.28);
}

int main() {
	setlocale(LC_ALL, "rus");
	Vector3D a{ 3.28_ft, 6.56_ft, 6.56_ft }, b{ 2.0_m, 2.0_m, 1.0_m };
	double n = 3.5;
	try {
		cout << "������ a:\n" << a << "\n������ b:\n" << b;
		cout << "\n����� a + b:\n" << a + b;
		cout << "\n�������� a - b:\n" << a - b;
		cout << "\n��������� ������������ a * b:\n" << a * b;
		cout << "\n��������� ������������ a & b:" << ScalarProduct(a, b);
		cout << "\n��������� ������� a �� ������ n:\n" << a * n;
		cout << "\n����� ������� a: " << length(a);
		cout << "\n����� ������� b: " << length(b) << '\n';

		if (a > b) { cout << "a > b"; }
		else if (a < b) { cout << "a < b"; }
		else { cout << "a = b"; }
	}
	catch (const exception & ex) {
		cout << ex.what() << endl;
	}
}