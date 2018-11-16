//
// Created by krystian on 12.11.18.
//

#include <iostream>
#include <math.h>
#include "Poly.h"

//Poly& Poly::operator= (double coeff) {
//	word w(coeff);
//	polynomial.emplace_back(w);
//	words_no++;
//	return *this;

Poly::Poly() {
	words_no = 0;
	freeTerm = 0;
}

Poly::Poly(double coeff) {
	words_no = 0;
	if (freeTerm != 0) {
		freeTerm = coeff;
	}
}




double& Poly::operator[] (const int index) {
	unsigned int i = words_no;
	word w;
	w.index = index;
	polynomial.emplace_back(w);
	words_no++;
	return polynomial.at(i).coeff;
}


//}

//void Poly::print(){
//	cout << to_string(polynomial.at(words_no - 1).index) + ", " + to_string(polynomial.at(words_no - 1).coeff) << endl;
//}

ostream &operator<<(ostream &os, const Poly &poly) {
	bool notFirst = false;
	bool sign = false;
	bool nonZeroFreeTerm = false;
//	os << "words no:" << poly.words_no << endl;
	for (auto iterator : poly.polynomial) {
		double coeff = iterator.coeff;
		int index = iterator.index;

		if(coeff < 0) {
			os << " - ";
			sign = true;
		}

		if(notFirst && !sign) {
				os << " + ";
		}

		if(coeff != 0) {
			os << fabs(coeff);
		}

		if(index >= 1) {
			os << "x";
		}

		if(index > 1) {
			os << "^" << index;
		}
		notFirst = true;
		sign = false;
	}

	if(poly.freeTerm > 0) {
		os << " + " ;
		nonZeroFreeTerm = true;
	} else if(poly.freeTerm < 0) {
		os << " - ";
		nonZeroFreeTerm = true;
	}
	if(nonZeroFreeTerm) os << poly.freeTerm;

	return os;
}

