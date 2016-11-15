/*
 * File: Utility.cpp
 * Implementation of class Utility which is defined in header file: Utility.h
 *
 *  Created on: Nov 6, 2016
 *      Author: Niraj Rajbhandari
 */

#include "Utility.h"

void Utility::writePolynomialToFile(const std::string outputFileName,
		Polynomial polynomial) {
	writeCoefficientsToFile(outputFileName, polynomial.getCoefficients());
}

void Utility::writeCoefficientsToFile(std::string outputFileName,
		std::vector<ComplexNumber> coefficients) {
	std::ofstream outputFile(outputFileName.c_str());
	if (!outputFile)
		throw std::invalid_argument(
				"Do not have the permission to create or write to the output file.");

	std::cout << std::endl << "Writing the polynomial to the file:"
			<< outputFileName << std::endl;
	std::cout << "0%" << std::setw(4) << "20" << std::setw(6) << "40"
			<< std::setw(5) << "60" << std::setw(5) << "80" << std::setw(6)
			<< "100%" << std::endl;
	std::cout << "|----|----|----|----|----|" << std::endl;

	unsigned int coefficientCount = coefficients.size();
	unsigned int percentChunk = 0.04 * coefficientCount;

	outputFile << coefficientCount << std::endl;
	for (unsigned int i = 0; i < coefficientCount; i++) {
		if (i % percentChunk == 0)
			std::cout << "*";
		ComplexNumber c = coefficients.at(i);
		outputFile << c.getReal() << "," << c.getImaginary() << " ";
	}
	std::cout << "*" << std::endl << "DONE!" << std::endl << std::endl;
}

void Utility::readCoefficientsFromFile(std::string inputFileName,
		std::vector<ComplexNumber> &coefficients) {
	std::ifstream inputFile(inputFileName.c_str());
	unsigned int coefficientCount;

	if (!inputFile)
		throw std::invalid_argument(
				"Input file not found. Please provide a correct input filename.Provide a valid file name or generate a polynomial and store it in a file before choosing this option.");
	std::cout << "0%" << std::setw(4) << "20" << std::setw(6) << "40"
			<< std::setw(5) << "60" << std::setw(5) << "80" << std::setw(6)
			<< "100%" << std::endl;
	std::cout << "|----|----|----|----|----|" << std::endl;
	inputFile >> coefficientCount;

	unsigned int percentChunk = 0.04 * coefficientCount;
	for (unsigned int i = 0; i < coefficientCount; i++) {
		if (i % percentChunk == 0)
			std::cout << "*";
		ComplexNumber c;
		std::vector<std::string> explodedString;
		std::string coeff;
		inputFile >> coeff;
		Utility::splitString(coeff, ComplexNumber::SEPARATOR, explodedString);
		if (explodedString.size() != 2)
			throw std::invalid_argument(
					"The complex number format provided in the file is not valid. The number should be of the form real,imaginary");
		std::string realPart = explodedString.at(0);
		std::string imaginaryPart = explodedString.at(1);
		c.setReal(std::atof(realPart.c_str()));
		c.setImaginary(std::atof(imaginaryPart.c_str()));
		coefficients.push_back(c);
	}
	std::cout << "*" << std::endl << "DONE!" << std::endl;
}

void Utility::readPolynomialFromFile(const std::string inputFileName,
		Polynomial &polynomial) {
	std::vector<ComplexNumber> coefficients;
	std::cout << std::endl << std::endl
			<< "Reading the polynomial from the file: " << inputFileName
			<< std::endl;

	Utility::readCoefficientsFromFile(inputFileName, coefficients);
	polynomial.setCoefficients(coefficients);
	polynomial.setCoefficientCount(coefficients.size());

}

void Utility::generateRandomPolynomial(Polynomial &polynomial) {

	std::cout << std::endl << std::endl << "Generating random polynomial..."
			<< std::endl;

	std::cout << "0%" << std::setw(4) << "20" << std::setw(6) << "40"
			<< std::setw(5) << "60" << std::setw(5) << "80" << std::setw(6)
			<< "100%" << std::endl;
	std::cout << "|----|----|----|----|----|" << std::endl;
	unsigned int percentChunk = ceil(0.04 * polynomial.getCoefficientCount());
	for (unsigned int i = 0; i < polynomial.getCoefficientCount(); i++) {
		if (i % percentChunk == 0)
			std::cout << "*";
		ComplexNumber complexNumber;
		complexNumber.setReal(
				Utility::generateRandomNumber(ComplexNumber::MIN_VALUE,
						ComplexNumber::MAX_VALUE));
		complexNumber.setImaginary(0);
		polynomial.setCoefficientAt(complexNumber, i);
	}
	std::cout << "*" << std::endl << "DONE!" << std::endl << std::endl;
}

int Utility::generateRandomNumber(int min, int max) {
	return min + (std::rand() % (int) (max - min + 1));
}

void Utility::hornerEvaluation(Polynomial &polynomial) {
	for (unsigned int k = 0; k < polynomial.getCoefficientCount(); k++) {
		ComplexNumber result;
		ComplexNumber rootOfUnity = Utility::calculateRootOfUnity(
				polynomial.getCoefficientCount(), k);
		std::vector<ComplexNumber> coefficients(polynomial.getCoefficients());
		std::reverse(coefficients.begin(), coefficients.end());
		result = coefficients.at(0);
		for (unsigned int i = 1; i < coefficients.size(); i++) {
			result = result + rootOfUnity;
			result = result + coefficients.at(i);
		}
		polynomial.getEvaluatedResults()[k] = result;
	}
}

ComplexNumber Utility::calculateRootOfUnity(unsigned int coefficientCount,
		unsigned int k) {
	ComplexNumber root;

	double theta = k * M_PI * 2 / coefficientCount;
	root.setReal(Utility::roundOf(cos(theta)));
	root.setImaginary(Utility::roundOf(sin(theta)));

	return root;

}

void Utility::evaluatePolynomial(Polynomial &polynomial, bool decreaseByHalf) {
	ComplexNumber evaluationResult, value;
	std::vector<ComplexNumber> rootsOfUnity(polynomial.getCoefficientCount());
	for (unsigned int k = 0; k < polynomial.getCoefficientCount(); k++) {
		rootsOfUnity[k] = Utility::calculateRootOfUnity(
				polynomial.getCoefficientCount(), k);
	}
	evaluationResult.setReal(0);
	evaluationResult.setImaginary(0);
	for (unsigned int k = 0; k < polynomial.getCoefficientCount(); k++) {

		value = (decreaseByHalf == false) ?
				Utility::power(rootsOfUnity[k], k) :
				Utility::powerByHalf(rootsOfUnity[k], k);
		value = polynomial.getCoefficients().at(k) * value;
		evaluationResult = value + evaluationResult;

		polynomial.setEvaluatedResultAt(evaluationResult, k);
	}

}

void Utility::FFT(std::vector<ComplexNumber> &coefficients) {
	unsigned int n = coefficients.size();
	if (n == 1)
		return;
	std::vector<ComplexNumber> odd;
	std::vector<ComplexNumber> even;

	Utility::split(coefficients, even, odd, 2);

	Utility::FFT(even);
	Utility::FFT(odd);

	for (unsigned int k = 0; k < n / 2; k++) {
		ComplexNumber oddPart = Utility::calculateRootOfUnity(n, k) * odd[k];
		coefficients[k] = even[k] + oddPart;
		coefficients[k + (n / 2)] = even[k] - oddPart;
	}
}

ComplexNumber Utility::powerByHalf(ComplexNumber base, unsigned int power) {
	if (power == 0) {
		ComplexNumber c;
		c.setReal(1);
		c.setImaginary(1);
		return c;
	}
	if (power % 2 == 0) {
		return Utility::powerByHalf(Utility::powerByHalf(base, power / 2), 2);
	} else
		return base * Utility::powerByHalf(base, power - 1);
}

ComplexNumber Utility::power(ComplexNumber base, unsigned int power) {
	ComplexNumber result = base;
	for (unsigned int i = 1; i < power; i++)
		result = result * base;
	return result;
}

void Utility::splitString(const std::string &inputString, const char delim,
		std::vector<std::string> &elems) {
	std::stringstream stringStream;
	stringStream.str(inputString);
	std::string item;
	while (std::getline(stringStream, item, delim))
		elems.push_back(item);
}

void Utility::split(std::vector<ComplexNumber> vectorToSlice,
		std::vector<ComplexNumber> &firstSlice,
		std::vector<ComplexNumber> &secondSlice,
		const unsigned int itemToSelect) {
	for (unsigned int i = 0; i < vectorToSlice.size(); i++)
		if (i % itemToSelect == 0)
			firstSlice.push_back(vectorToSlice.at(i));
		else
			secondSlice.push_back(vectorToSlice.at(i));
}

double Utility::roundOf(double value) {
	double result =
			(value > 0) ? floor(value * 10) / 10 : ceil(value * 10) / 10;
	return (fabs(result) == 0) ? fabs(result) : result;
}

void Utility::validateUserInput(unsigned int &input, std::string requestMsg) {
	while (true) {
		std::cout << requestMsg;
		if ((std::cin >> input) && input >= 0) {
			break;
		} else {
			std::cout << "Please enter a valid input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

