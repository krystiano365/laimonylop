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

Poly::Poly(const Poly& p) {
	this->words_no = p.words_no;
	for(word w : p.polynomial) {
		this->polynomial.emplace_back(w);
	}
	this->freeTerm = p.freeTerm;
}



double& Poly::operator[] (const int index) {
	if (index == 0) {
		return freeTerm;
	} else {
		unsigned int i = words_no;
		word w(index);
		polynomial.emplace_back(w);
		words_no++;
		return polynomial.at(i).coeff;
	}
}


//}

//void Poly::print(){
//	cout << to_string(polynomial.at(words_no - 1).index) + ", " + to_string(polynomial.at(words_no - 1).coeff) << endl;
//}

ostream& operator<<(ostream &os, const Poly &poly) {
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

Poly operator+(const Poly &p1, const Poly &p2) {
	Poly temp(p1);
	int index1, index2;
	int greaterPolyWords_no = p1.words_no > p2.words_no ? p1.words_no : p2.words_no;
//	for (unsigned int i = 0; i < greaterPolyWords_no; i++) {
//		index1 = 0;
//		index2 = 0;
//
//		if(i < p1.words_no) {
//			index1 = p1.polynomial.at(i).index;
//		}
//
//		if(i < p2.words_no) {
//			index2 = p2.polynomial.at(i).index;
//		}
//
//		if(index1 > index2) {
//			temp[index1] = p1.polynomial.at(i).coeff;
//			temp[index2] = p2.polynomial.at(i).coeff;
//		} else if(index1 < index2) {
//			temp[index2] = p2.polynomial.at(i).coeff;
//			temp[index1] = p1.polynomial.at(i).coeff;
//		} else {
//			temp[index1] = p1.polynomial.at(i).coeff + p2.polynomial.at(i).coeff;
//		}
//	}
//	cout << temp[2] << endl;
//	temp.freeTerm = p1.freeTerm + p2.freeTerm;
//	return temp;
}

Poly &Poly::operator=(const Poly &p) {

}


