//
// Created by krystian on 12.11.18.
//

#include <iostream>
#include <math.h>
#include "Poly.h"




Poly::Poly(double coeff) {
	if (coeff != 0) {
		polynomial[0] = coeff;
	}
}




Poly::Poly(const Poly& p) {
	for(pair<int, double> w : p.polynomial) {
		this->polynomial.emplace(w);
	}
}




double& Poly::operator[] (const int index) {
	return polynomial[index];
}




ostream& operator<<(ostream &os, const Poly &poly) {
	bool sign = false;			// while true it doesn't allow to print a + sign when minus sign has already occured
	bool wasNoDigit = true;		// while true it doesn't allow to print a + sign if there was no number before
	//	os << "words no:" << poly.words_no << endl;
	for (pair<int, double> it : poly.polynomial) {
		double coeff = it.second;
		int index = it.first;

		if(coeff < 0) {
			os << " - ";
			sign = true;
		}

		if(!wasNoDigit && !sign) {
				os << " + ";
		}

		wasNoDigit = false;

//		if(coeff != 0) {
		os << fabs(coeff);
//		} else {
//			wasZero = true;
//		}

		if(index >= 1) {
			os << "x";
		}

		if(index > 1) {
			os << "^" << index;
		}
		sign = false;
	}
	return os;
}




Poly operator+(const Poly &p1, const Poly &p2) {
	Poly temp(p1);			//initializing temp with one of inputted polynomials
	int index1;
	for(pair<int, double> it : p2.polynomial) {
		index1 = it.first;
		temp[index1] = temp[index1] + p2.polynomial.at(index1);
		if(temp.polynomial.at(index1) == 0) temp.polynomial.erase(index1);
	}
	//	for (unsigned int i = 0; i < greaterPolyWords_no; i++) {

//	return temp;
//	temp.freeTerm = p1.freeTerm + p2.freeTerm;
//	cout << temp[2] << endl;
//	}
//		}
//			temp[index1] = p1.polynomial.at(i).coeff + p2.polynomial.at(i).coeff;
//		} else {
//			temp[index1] = p1.polynomial.at(i).coeff;
//			temp[index2] = p2.polynomial.at(i).coeff;
//		} else if(index1 < index2) {
//			temp[index2] = p2.polynomial.at(i).coeff;
//			temp[index1] = p1.polynomial.at(i).coeff;
//		if(index1 > index2) {
//
//		}
//			index2 = p2.polynomial.at(i).index;
//		if(i < p2.words_no) {
//
//		}
//			index1 = p1.polynomial.at(i).index;
//		if(i < p1.words_no) {
//
//		index2 = 0;
//		index1 = 0;
	return temp;
}




Poly operator-(const Poly &p1, const Poly &p2) {
	Poly temp(p1);
	int index;
	for(pair<int, double> it : p2.polynomial) {
		index = it.first;
		temp[index] = temp[index] - p2.polynomial.at(index);
		if(temp.polynomial.at(index) == 0) temp.polynomial.erase(index);
	}
	return temp;
}

Poly operator*(const Poly &p1, const Poly &p2) {
	Poly result;
	Poly temp;
	for(pair<int, double> it1 : p1.polynomial) {
		temp.polynomial.clear();
		for(pair<int, double> it2 : p2.polynomial) {
			temp[it1.first + it2.first] = it1.second * it2.second;
		}
		result = operator+(temp, result);
	}
	return result;
}

Poly operator-(const Poly &p) {
	Poly temp;
	for(pair<int,double> it : p.polynomial) {
		temp[it.first] = -(it.second);
	}
	return temp;
}

double Poly::operator()(const double val) {
	double result = 0;
	for(pair<int, double> it : polynomial) {
		if(it.first != 0) {
			result += (it.second * pow(val, it.first));
		} else {
			result += it.second;
		}
	}
	return result;
}


