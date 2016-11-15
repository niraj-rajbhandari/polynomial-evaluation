/*
 * File: Polynomial.cpp
 * Implementation of the class Polynomial which is defined in header file : Polynomial.h
 *
 *  Created on: Nov 6, 2016
 *      Author: Niraj Rajbhandari
 */

#include "Polynomial.h"

Polynomial::Polynomial() {

}

Polynomial::Polynomial(unsigned int coeffCount) {
	this->coefficientCount = coeffCount;
	this->degree = coeffCount - 1;

}

void Polynomial::setCoefficientCount(unsigned int coeffCount) {
	this->coefficientCount = coeffCount;
	this->coefficients.resize(coeffCount);
	this->evaluatedResult.resize(coeffCount);
}

unsigned int Polynomial::getCoefficientCount() {
	return this->coefficientCount;
}

void Polynomial::setDegree(unsigned int deg) {
	this->degree = deg;
}

unsigned int Polynomial::getDegree() {
	return this->degree;
}

void Polynomial::setCoefficientAt(ComplexNumber coeff, unsigned int position) {
	this->coefficients[position] = coeff;
}

void Polynomial::setCoefficients(std::vector<ComplexNumber> coeff) {
	this->coefficients = coeff;
}

std::vector<ComplexNumber> Polynomial::getCoefficients() {
	return this->coefficients;
}

void Polynomial::setEvaluatedResultAt(ComplexNumber result, unsigned int position){
	this->evaluatedResult[position]=result;
}

void Polynomial::setEvaluatedResults(std::vector<ComplexNumber> results) {
	this->evaluatedResult = results;
}

std::vector<ComplexNumber> Polynomial::getEvaluatedResults() {
	return this->evaluatedResult;
}

void Polynomial::displayCoefficients() {
	std::cout << "The coefficients in the polynomial are: " << std::endl
			<< std::endl;
	for (unsigned int i = 0; i < this->getCoefficientCount(); i++) {
		this->coefficients[i].display();

		if (i % this->getCoefficientCount() == 9)
			std::cout << std::endl;
		else
			std::cout << std::setw(5);
	}
	std::cout<<std::endl<<std::endl;
}
