/**
 * File: ComplexNumber.h
 * Definition of class ComplexNumber
 * Implementation can be found in source file: ComplexNumber.cpp
 *
 * @author: Niraj Rajbhandari
 */
#ifndef ComplexNumber_h
#define ComplextNumber_h

#include <iostream>
#include <math.h>
class ComplexNumber {
private:
	double real;
	double imaginary;
public:
	static const char SEPARATOR = ',';
	static const int MAX_VALUE = 10;
	static const int MIN_VALUE = -10;
	ComplexNumber();
	ComplexNumber(double r, double i);
	void setReal(double r);
	double getReal();

	void setImaginary(double i);
	double getImaginary();

	void display();

	//Operator overloading
	ComplexNumber operator-(const ComplexNumber& b);
	ComplexNumber operator+(const ComplexNumber& b);
	ComplexNumber operator*(const ComplexNumber& b);

};
#endif
