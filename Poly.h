//
// Created by krystian on 12.11.18.
//

#ifndef POLYNOMIAL_POLY_H
#define POLYNOMIAL_POLY_H
#include <ostream>
#include <map>

using namespace std;

class Poly {
private:
	map<int, double> polynomial;
public:
	Poly() = default;
	Poly(double coeff);
	Poly(const Poly& p);
	~Poly() = default;
	friend Poly operator+ (const Poly& p1, const Poly& p2);
	friend Poly operator- (const Poly& p1, const Poly& p2);
	friend Poly operator* (const Poly& p1, const Poly& p2);
	friend Poly operator- (const Poly& p);
	double operator() (double val);
	double& operator[] (int index);
	friend ostream& operator<< (ostream& ostr, const Poly& poly);
};



#endif //POLYNOMIAL_POLY_H
