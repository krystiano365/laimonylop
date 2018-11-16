//
// Created by krystian on 12.11.18.
//

#ifndef POLYNOMIAL_POLY_H
#define POLYNOMIAL_POLY_H
#include <vector>
#include <ostream>

using namespace std;

class Poly {
private:
	struct word{
		word(){
			coeff = 0;
			index = 0;
		};
		word(int i){
			coeff = 0;
			index = i;
		};
		int index;
		double coeff;
	};
	double freeTerm;
	unsigned int words_no;
	vector<word> polynomial;
public:
	Poly();
	Poly(double coeff);
	Poly(const Poly& p);
	~Poly() = default;
	Poly& operator= (const Poly& p);
	friend Poly operator+ (const Poly& p1, const Poly& p2);
	double& operator[] (int index);
	friend ostream& operator<< (ostream& ostr, const Poly& poly);
};



#endif //POLYNOMIAL_POLY_H
