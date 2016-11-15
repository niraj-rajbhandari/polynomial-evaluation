/*
 * File: Utility.h
 * Class definition for Utility Class
 * Implementation can be found on source file: Utility.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: Niraj Rajbhandari
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <cstring>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <math.h>

#include "Polynomial.h"

class Utility {

public:
	Utility();

	/**
	 * Writes the coefficient into the output file
	 * @author Niraj Rajbhandari
	 *
	 * @param string outputFileName file to which to write the coefficients
	 * @param vector<ComplexNumber> coefficients coefficients which is to be written into the file
	 *
	 * @throws invalid_argument
	 */
	static void writeCoefficientsToFile(std::string outputFileName,
			std::vector<ComplexNumber> coefficients);

	/**
	 * Writes the polynomial to a file
	 * @author Niraj Rajbhandari
	 *
	 * @param string outputFileName file to which to write the polynomial
	 * @param Polynomial polynomial polynomial which is to be written into the file
	 *
	 * @throws invalid_argument
	 */
	static void writePolynomialToFile(const std::string outputFileName,
			Polynomial polynomial);

	/**
	 * Reads polynomial from the text file
	 * @author Niraj Rajbhandari
	 *
	 * @param string inputFileName file from which to read the polynomial
	 * @param Polynomial polynomial reference to the polynomial which stores the read polynomial
	 *
	 * @throws invalid_argument
	 */
	static void readPolynomialFromFile(const std::string inputFileName,
			Polynomial &polynomial);

	/**
	 * Reads coefficients from the text file
	 * @author Niraj Rajbhandari
	 *
	 * @param string inputFileName file from which to read the coefficient
	 * @param vector<ComplexNumber> coefficients reference to the vector which stores the read coefficients
	 *
	 * @throws invalid_argument
	 */
	static void readCoefficientsFromFile(std::string inputFileName,
			std::vector<ComplexNumber> &coefficients);

	/**
	 * Generates random polynomial
	 * @author Niraj Rajbhandari
	 *
	 * @param Polynomial polynomial reference to the polynomial which stores the randomly generated polynomial
	 */
	static void generateRandomPolynomial(Polynomial &polynomial);

	/**
	 * Calculates kth root of unity
	 * @author Niraj Rajbhandari
	 *
	 * @param unsigned int coefficientCount number of terms in the polynomial
	 * @param unsigned int k kth root
	 *
	 * @return ComplexNumber kth root of unity
	 */
	static ComplexNumber calculateRootOfUnity(
			const unsigned int coefficientCount, const unsigned int k);

	/**
	 * Evaluate a polynomial at nth root of unity
	 * @author Niraj Rajbhandari
	 *
	 * @param Polynomial polynomial reference to the polynomial to be evaluated at nth root of unity
	 * @param bool decreaseByHalf flag to calculate power by using decrease-by-half algorithm or not
	 *
	 */
	static void evaluatePolynomial(Polynomial &polynomial,
			bool decreaseByHalf);

	/**
	 * Evaluate a polynomial for nth root of unity using FFT
	 * @author Niraj Rajbhandari
	 *
	 * @param vector coefficients coefficients of the polynomial to be evaluated
	 */
	static void FFT(std::vector<ComplexNumber> &coefficients);

	/**
	 * Evaluate a polynomial using Horner's method
	 * @author Niraj Rajbhandari
	 *
	 * @param Polynomial polynomial reference to the polynomial to be evaluated
	 *
	 */
	static void hornerEvaluation(Polynomial &polynomial);

	/**
	 * Splits a string by a delimiter
	 * @author Niraj Rajbhandari
	 *
	 * @param string inputString string to be split by delimiter
	 * @param char delim delimiter to split the string
	 * @param vector<string> referene to the vector where you want to store the splitted string
	 *
	 */
	static void splitString(const std::string &inputString, const char delim,
			std::vector<std::string> &elems);

	/**
	 * Generates random integer between min and max
	 * @author Niraj Rajbhandari
	 *
	 * @param int min minimum of the range for random value
	 * @param int max maximum of the range for random value
	 * @return int random value between min and max
	 */
	static int generateRandomNumber(int min, int max);

	/**
	 * Calculates the exponentiation of a base to some power using decrease by half algorithm
	 * @author Niraj Rajbhandari
	 *
	 * @param ComplexNumber base
	 * @param unsigned int power
	 * @return ComplexNumber returns the result of exponentiation
	 */
	static ComplexNumber powerByHalf(ComplexNumber base, unsigned int power);

	/**
	 * Calculates the exponentiation of a base to some power
	 * @author Niraj Rajbhandari
	 *
	 * @param ComplexNumber base
	 * @param unsigned int power
	 *
	 * @returns ComplexNumber ComplexNumber exponentiated to given power
	 */
	static ComplexNumber power(ComplexNumber base, unsigned int power);

	/**
	 * Split a vector into two vectors
	 * @author Niraj Rajbhandari
	 *
	 * @param vector<ComplexNumber> vectorToSlice vector that needs to be sliced
	 * @param vector<ComplexNumber> firstSlice pass by reference to the vector
	 * 											where you want to store the first part of split vector
	 * @param vector<ComplexNumber> secondSlice pass by reference to the vector
	 * 											where you want to store the second part of the split vector
	 * @param unsigned int itemToSelect defines which item to select to put into the first slice of the split vector
	 */
	static void split(std::vector<ComplexNumber> vectorToSlice,
			std::vector<ComplexNumber> &firstSlice,
			std::vector<ComplexNumber> &secondSlice,
			const unsigned int sliceEach);

	/**
	 * Rounds a value off
	 * @author Niraj Rajbhandari
	 *
	 * @param double val value to be rounded off
	 */
	static double roundOf(double val);

	/**
	 * Validates user's integer input
	 * @author Niraj Rajbhandari
	 *
	 * @param unsigned int input reference to the variable which will store the user input
	 * @param string requestMsg message to be displayed to request for input
	 */
	static void validateUserInput(unsigned int &input, std::string requestMsg);

};

#endif /* UTILITY_H_ */
