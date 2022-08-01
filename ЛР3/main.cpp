/*
������� ���������, ������� ���������:
�       ������� �� ������������ ����� std::cin ������, �������� �������� �������.
�       ��������� ��������� ������ � ������������ ������ std::vector<Figure*>
�       �������� ��� ����� ������� ����� ������� (1-3 ��. ����).�.�. ������������� ��� ������ ������ � ������� �������������� �����, ���������� ������ � �������.
�       ���������� ����� ��������� ����� ������� ����� � �������.
�       ������� �� ������� ������ �� �������;


34.
�������
�������������
��������
*/
#include<iostream>
#include<vector>
#define PI 3.14159265
using namespace std;

struct Point {
	double x = 0;
	double y = 0;
};

Point operator+ (const Point& a, const Point& b) {
	return { a.x + b.x, a.y + b.y };
}

Point operator- (const Point& a, const Point& b) {
	return { a.x - b.x, a.y - b.y };
}

istream& operator>> (istream& input, Point& a) {
	input >> a.x >> a.y;
	return input;
}

ostream& operator<< (ostream& output, const Point& a) {
	output << "[" << a.x << ", " << a.y << ']';
	return output;
}

double sin_(double deg) {
	double rad = deg * PI / 180.0;
	return round(sin(rad) * 1000) / 1000;
}

double cos_(double deg) {
	double rad = deg * PI / 180.0;
	return round(cos(rad) * 1000) / 1000;
}

Point turn(Point A, Point O, double deg) {
	Point a = { A.x - O.x, A.y - O.y };

	double x = (a.x * cos_(deg)) - (a.y * sin_(deg));
	double y = (a.y * cos_(deg)) + (a.x * sin_(deg));

	return{ x + O.x, y + O.y };
}

class Figure {
protected:
	Point A_, B_, C_, D_, O_;
public:
	Figure() {}
	virtual void set(Point a, Point b) {}
	virtual void set(Point a, Point b, double fi) {}
	virtual void set(Point a, Point b, Point c, double fi) {}
	virtual double S() { return 0; }
	virtual Point A() { return { 0,0 }; }
	virtual Point B() { return { 0,0 }; }
	virtual Point C() { return { 0,0 }; }
	virtual Point D() { return { 0,0 }; }
	virtual Point O() { return { 0,0 }; }

	/*
	virtual Point A() { return A_; }
	virtual Point B() { return B_; }
	virtual Point C() { return C_; }
	virtual Point D() { return D_; }
	*/
};

class Square : public Figure {
public:
/*	Square() {	// �� ��������� - ������� � ������� � ����� 0 � �������� 2
		O_ = { 0,0 };
		A_ = { -1,-1 };
		B_ = { -1,1 };
		C_ = { 1,1 };
		D_ = { 1,-1 };
	}
	Square(Point o, Point a) {
		O_ = o;
		A_ = a;
		C_ = { A_.x + 2 * (O_.x - A_.x), A_.y + 2 * (O_.y - A_.y) };
		B_ = { O_.x - A_.y + O_.y, O_.y + A_.x - O_.x };
		D_ = { B_.x + 2 * (O_.x - B_.x), B_.y + 2 * (O_.y - B_.y) };
	}
	*/
	void set(Point o, Point a) {
		O_ = o;
		A_ = a;
		C_ = { A_.x + 2 * (O_.x - A_.x), A_.y + 2 * (O_.y - A_.y) };
		B_ = { O_.x - A_.y + O_.y, O_.y + A_.x - O_.x };
		D_ = { B_.x + 2 * (O_.x - B_.x), B_.y + 2 * (O_.y - B_.y) };
	}
	
	double S() { return pow(sqrt(pow(A_.x - B_.x, 2) + pow(A_.y - B_.y, 2)), 2); }
	Point A() { return A_; }
	Point B() { return B_; }
	Point C() { return C_; }
	Point D() { return D_; }
	Point O() { return O_; }
};

class Rectangle : public Figure {
public:
/*	Rectangle(Point a, Point o, double fi) { // fi - ���� ����� �����������
		A_ = a;
		O_ = o;
		B_ = turn(A_, O_, fi);
		C_ = turn(B_, O_, 180.0 - fi);
		D_ = turn(C_, O_, fi);
	}
	*/

	void set(Point o, Point a, double fi) {		// fi - ���� ����� �����������
		A_ = a;
		O_ = o;
		B_ = turn(A_, O_, fi);
		C_ = turn(B_, O_, 180.0 - fi);
		D_ = turn(C_, O_, fi);
	}
	
	double S() { return (sqrt(pow(A_.x - B_.x, 2) + pow(A_.y - B_.y, 2)) * sqrt(pow(C_.x - B_.x, 2) + pow(C_.y - B_.y, 2))); } //AB*CB
	Point A() { return A_; }
	Point B() { return B_; }
	Point C() { return C_; }
	Point D() { return D_; }
	Point O() { return O_; }
};

class Trapeze : public Figure {
	double F;	// ���� ����� �����������
public:
	/*Trapeze(Point a, Point c, Point o, double fi) {	// O - ����� ����������� ����������, d - ���������, fi - ���� ����� ����������� (AOB)
		O_ = o;
		A_ = a;
		B_ = turn(A_, O_, fi);	// AB^2 = x^2 + y^2
		C_ = c;
		D_ = turn(C_, O_, fi);
		F = fi;
	}*/

	void set(Point o, Point a, Point c, double fi) {	// O - ����� ����������� ����������, d - ���������, fi - ���� ����� ����������� (AOB)
		O_ = o;
		A_ = a;
		B_ = turn(A_, O_, fi);	// AB^2 = x^2 + y^2
		C_ = c;
		D_ = turn(C_, O_, fi);
		F = fi;
	}
//	AC = sqrt(pow(A_.x + C_.x, 2) + pow(A_.y + B_.y, 2)) - ���������
	double S() { return (pow(A_.x + C_.x, 2) + pow(A_.y + B_.y, 2) / 2) * sin_(F); }
	Point A() { return A_; }
	Point B() { return B_; }
	Point C() { return C_; }
	Point D() { return D_; }
	Point O() { return O_; }
};

void commands() {
	cout << "________________________________________________________________________________________\n"
		<< "|�������:                                                                               |\n"
		<< "|_______________________________________________________________________________________|\n"
		<< "|1. �������� ������ � ������                                                            |\n"
		<< "|2. ������� n-� ������ �� �������                                                       |\n"
		<< "|3. �������� ������                                                                     |\n"
		<< "|4. ������� ���������� ������ � ��������������� ������                                  |\n"
		<< "|5. ������� �������                                                                     |\n"
		<< "|6. ������ ���������� ����� � �������                                                   |\n"
		<< "|7. ��������� ����� ������� ����� � �������                                             |\n"
		<< "|8. ��������� ������ ���������                                                          |\n"
		<< "|_______________________________________________________________________________________|\n"
		<< endl;
}

int inputFigure() {
	unsigned int var;
	cout << "������ �����:\n1. �������\n2. �������������\n3. ��������\n"
		<< "������� ����� ������: ";
	if (cin >> var) { return var; }
	return -1;
}

int main() {
	setlocale(LC_ALL, "rus");
	vector<Figure*> f;
	int i = 0; // ���������� ����� � �������
	unsigned int input = 0;
	commands();

	while (input != 8) {
		cout << "������� �������: ";
		if (!(cin >> input)) {
			cout << "������� ������� �����������.\n";
			commands();
			break;
		}

		double allS = 0;
		int numb;
		Point O, A, C;
		double AOB;
		switch (input) {
		case 1:
			numb = inputFigure();
			switch (numb) {
			case 1:
				f.push_back(new Square());
//				Point O, A;
				cout << "������� ���������� ������ (����� ����������� ����������) O � ����� �� ������ �������� A:\n"
					<< "O: ";
				cin >> O;
				cout << "A: ";
				cin >> A;
				f[i]->set(O, A);
				++i;
				break;
			case 2:
				f.push_back(new Rectangle());
//				Point O, A; double AOB;
				cout << "������� ���������� ������ (����� ����������� ����������) O, ����� �� ������\n�������������� A � ���� ����� ����������� AOB:\n"
					<< "O: "; 
				cin >> O;
				cout << "A: ";
				cin >> A;
				cout << "AOB: ";
				cin >> AOB;
				f[i]->set(O, A, AOB);
				++i;
				break;
			case 3:
				f.push_back(new Trapeze());
//				Point O, A, C; double AOB;
				cout << "������� ���������� ������ (����� ����������� ����������) O, ��� �������, ������� �� �����\n��������� A � C, � ����� ���� ����� ����������� AOB:\n" 
					<< "O: ";
				cin >> O;
				cout << "A: ";
				cin >> A;
				cout << "C: ";
				cin >> C;
				cout << "AOB: ";
				cin >> AOB;
				f[i]->set(O, A, C, AOB);
				++i;
				break;
			default:
				cout << "������: �������� ����� ������\n";
				break;
			}
			break;
		case 2:
			int n;
			if (i == 0) {
				cout << "������ �������. � ������� ��� �� ����� ������\n";
				break;
			}
			cout << "������� ����� ������, ������� �� ������ �������: ";
			cin >> n;
			--n;
			if (n >= i) {
				cout << "���������� ������� ������ �" << n << ". ����� � ������� �����: " << i << '\n';
				break;
			}
			for (n; n < i - 1; ++n) {
				f[n] = f[n + 1];
			}
			f.pop_back();
			--i;
			cout << "�������� ������ �������\n";
			break;
		case 3:
			if (i == 0) {
				cout << "������ �������. � ������� ��� �� ����� ������\n";
				break;
			}
			for (int n = 0; n < i; ++n) {
				f.pop_back();
			}
			cout << "�������� ���� ��������� ������� ������ �������\n";
			i = 0;
			break;
		case 4:
			if (i == 0) {
				cout << "� ������� ��� �� ����� ������\n";
				break;
			}
			for (int var = 0; var < i; ++var) {
				cout << "��� " << "������ �" << var + 1 << ":\n"
					<< "O = " << f[var]->O() << ";\n"
					<< "A = " << f[var]->A() << ";\n"
					<< "B = " << f[var]->B() << ";\n"
					<< "C = " << f[var]->C() << ";\n"
					<< "D = " << f[var]->D() << ";\n";
			}
			break;
		case 5:
			if (i == 0) {
				cout << "� ������� ��� �� ����� ������\n";
				break;
			}
			for (int var = 0; var < i; ++var) {
				cout << "��� ������ �" << var + 1 << ": S = " << f[var]->S() << '\n';
			}
			break;
		case 6:
			cout << "����� � �������: " << i << '\n';
			break;
		case 7:
			for (int n = 0; n < i; ++n) {
				allS += f[n]->S();
			}
			cout << "����� ������� ���� ����� � �������: " << allS << '\n';
		case 8: break;
		default: 
			cout << "������� ������� �����������.\n";
			commands();
			break;
		}
		cout << '\n';
	}
	return 0;
}