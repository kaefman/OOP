#pragma once
#include <iostream>
#include <cmath>

template <class T>
struct Square {
	using vertex_t = std::pair<T, T>;
	static const size_t vertexes{ 4 };
	vertex_t a, b, c, d;

	Square() {
		a = std::make_pair(0, 0);
		b = std::make_pair(0, 0);
		c = std::make_pair(0, 0);
		d = std::make_pair(0, 0);
	}
	Square(const vertex_t& aa, const vertex_t& bb, const vertex_t& cc, const vertex_t& dd) :
		a(aa), b(bb), c(cc), d(dd) {

	}

	Square(const Square& other) {
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;

	}

	Square& operator=(const Square& other) {
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;
		return *this;
	}
};

template <class T>
std::ostream& operator<<(std::ostream& os, Square<T> sq) {
	os << "[" << sq.a.first << "," << sq.a.second << "]";
	os << "[" << sq.b.first << "," << sq.b.second << "]";
	os << "[" << sq.c.first << "," << sq.c.second << "]";
	os << "[" << sq.d.first << "," << sq.d.second << "]";
	return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Square<T>& sq) {
	is >> sq.a.first >> sq.a.second
		>> sq.b.first >> sq.b.second
		>> sq.c.first >> sq.c.second
		>> sq.d.first >> sq.d.second;
	return is;
}

template <typename T>
T S(Square<T> sq) {
	if (sq.a.first != sq.b.first) return pow(sq.a.first - sq.b.first, 2);
	return pow(sq.a.second - sq.b.second, 2);
}