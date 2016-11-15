/*
 * File: Polynomial.h
 * Class definition for Polynomial Class
 * Implementation can be found in source file: Polynomial.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: Niraj Rajbhandari
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <iostream>
#include <iomanip>
#include "ComplexNumber.h"

class Polynomial {
private:
	unsigned int coefficientCount;
	unsigned int degree;
	std::vector<ComplexNumber> coefficients;
	std::vector<ComplexNumber> evaluatedResult;
public:
	Polynomial();
	Polynomial(unsigned int coeffCount);

	void setCoefficientCount(unsigned int coeffCount);
	unsigned int getCoefficientCount();

	void setDegree(unsigned int deg);
	unsigned int getDegree();

	void setCoefficientAt(ComplexNumber coeff, unsigned int position);
	void setCoefficients(std::vector<ComplexNumber>coeff);
	std::vector<ComplexNumber> getCoefficients();

	void setEvaluatedResultAt(ComplexNumber result, unsigned int position);
	void setEvaluatedResults(std::vector<ComplexNumber> results);
	std::vector<ComplexNumber> getEvaluatedResults();

	void displayCoefficients();

};

#endif /* POLYNOMIAL_H_ */
