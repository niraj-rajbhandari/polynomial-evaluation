/*
 * ComplexNumber.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: destroyed
 */

#include "ComplexNumber.h"
ComplexNumber::ComplexNumber() {
	this->real = 0;
	this->imaginary = 0;
}
ComplexNumber::ComplexNumber(double r, double i) {
	this->real = i;
	this->imaginary = i;
}

void ComplexNumber::setReal(double r) {
	this->real = r;
}

void ComplexNumber::setImaginary(double i) {
	this->imaginary = i;
}

double ComplexNumber::getReal() {
	return this->real;
}

double ComplexNumber::getImaginary() {
	return this->imaginary;
}

void ComplexNumber::display() {
	std::cout << this->getReal() << ((this->getImaginary() < 0) ? " - " : " + ")
			<< fabs(this->getImaginary()) << "i";
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& b) {
	ComplexNumber complexNumber;
	complexNumber.setReal(this->getReal() + b.real);
	complexNumber.setImaginary(this->getImaginary() + b.imaginary);
	return complexNumber;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& b) {
	ComplexNumber complexNumber;
	complexNumber.setReal(this->getReal() - b.real);
	complexNumber.setImaginary(this->getImaginary() - b.imaginary);
	return complexNumber;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& b) {
	ComplexNumber complexNumber;
	double k1 = b.real * (this->getReal() + this->getImaginary());
	double k2 = this->getReal() * (b.imaginary - b.real);
	double k3 = this->getImaginary() * (b.real + b.imaginary);

	complexNumber.setReal(k1 - k3);
	complexNumber.setImaginary(k1 + k2);
	return complexNumber;
}

