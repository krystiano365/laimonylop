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
//	class Word;
	struct word{
		word(){
			coeff = 0;
			index = 0;
		};
		word(double c){
			coeff = c;
			index = 0;
		}
		word(int i, double c){
			index = i;
			coeff = c;
		}
		int index;
		double coeff;
	};
	unsigned int words_no;
	vector<word> polynomial;
public:
	Poly();
	Poly(double coeff);
	~Poly()= default;
	word operator[] (unsigned int i);
	double& operator[] (int index);
	friend ostream& operator<< (ostream& ostr, const Poly& poly);
	void print();
};


//
//class Poly::Word {
//private:
//	int index;
//	double coeff;
//public:
//	Word()=default;
//	~Word()=default;
//};
#endif //POLYNOMIAL_POLY_H
