/*
 * main.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: destroyed
 */

#include <iostream>

#include "Utility.h"

Polynomial polynomial;
std::string inputFile;
std::string outputFile;
std::string resultFile;

void navigate();
void displayMenu();
void writeOptions();
void readOption();
void randomPolynomialOption();

int main() {
	navigate();
}

void navigate() {
	bool showMenu = true;
	unsigned int option;
	do {
		try {
			displayMenu();
			std::cin >> option;
			switch (option) {
			case 1:
				randomPolynomialOption();
				break;
			case 2:
				readOption();
				break;
			case 3:
				writeOptions();
				break;
			case 4:
				if (polynomial.getCoefficientCount() > 0)
					Utility::evaluatePolynomial(polynomial, false);
				else
					std::cout
							<< "Please generate a random polynomial or read the polynomial from a file."
							<< std::endl;
				break;
			case 5:
				if (polynomial.getCoefficientCount() > 0)
					Utility::evaluatePolynomial(polynomial, true);
				else
					std::cout
							<< "Please generate a random polynomial or read the polynomial from a file."
							<< std::endl;
				break;
			case 6:
				if (polynomial.getCoefficientCount() > 0)
					Utility::hornerEvaluation(polynomial);
				else
					std::cout
							<< "Please generate a random polynomial or read the polynomial from a file."
							<< std::endl;
				break;
			case 7:
				if (polynomial.getCoefficientCount() > 0) {
					std::vector<ComplexNumber> coefficients =
							polynomial.getCoefficients();
					Utility::FFT(coefficients);
					polynomial.setEvaluatedResults(coefficients);
				}
				else
					std::cout
							<< "Please generate a random polynomial or read the polynomial from a file."
							<< std::endl;
				break;
			case 8:
				showMenu = false;
				break;
			default:
				std::cout <<std::endl<<std::endl<< "Please select a proper option"<<std::endl<<std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
						'\n');
				break;

			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl << std::endl;
		}

	} while (showMenu);
}

void displayMenu() {
	std::cout << "Please select an option (1-8): " << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << "1. Generate a random polynomial" << std::endl;
	std::cout << "2. Read the polynomial from the file" << std::endl;
	std::cout << "3. Write the polynomial to the file" << std::endl;
	std::cout << "4. Naive evaluation of polynomial on nth root of unity"
			<< std::endl;
	std::cout
			<< "5. Naive evaluation of polynomial on nth root of unity with decrease-by-half algorithm"
			<< std::endl;
	std::cout << "6. Horner's method for polynomial evaluation" << std::endl;
	std::cout << "7. Fast Fourier Transformation for polynomial evaluation"
			<< std::endl;
	std::cout << "8. Exit" << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << "Your choice is: ";
}

void writeOptions() {
	bool showWriteMenu = false;
	unsigned int option;
	std::string fileName;
	std::cout
			<< "Please provide the name of the file where to store the polynomial";
	std::cin >> fileName;
	std::cout << std::endl;
	do {
		std::cout << "Choose an option (1-3):" << std::endl;
		std::cout << "1. Write the generated polynomial" << std::endl;
		std::cout << "2. Write the evaluated results" << std::endl;
		std::cout << "3. Cancel" << std::endl;
		std::cout << "Your choice is: ";
		std::cin >> option;
		switch (option) {
		case 1:
			if (polynomial.getCoefficientCount() > 0) {
				outputFile = fileName;
				Utility::writePolynomialToFile(outputFile, polynomial);
			} else {
				std::cout
						<< "Please generate a polynomial before writing to the file.";
			}
			break;
		case 2:
			if (polynomial.getEvaluatedResults().size() > 0) {
				resultFile = fileName;
				Utility::writeCoefficientsToFile(resultFile,
						polynomial.getEvaluatedResults());
			} else {
				std::cout
						<< "Polynomial has not yet been evaluated for nth root of unity. Please evaluate the polynomial first";
			}
			break;
		case 3:
			break;
		default:
			std::cout << "Please select a correct option" << std::endl;
			showWriteMenu=true;
			break;
		}
	} while (showWriteMenu);
}

void readOption() {
	std::cout
			<< "Please provide the name of the file which is stores the polynomial: ";
	std::cin >> inputFile;
	Utility::readPolynomialFromFile(inputFile, polynomial);

}

void randomPolynomialOption() {
	unsigned int degree;
	std::string requestMsg =
			"Please provide the degree of the polynomial to generate: ";
	Utility::validateUserInput(degree, requestMsg);
	std::cout<<"degree: "<<degree<<std::endl;
	polynomial.setCoefficientCount((degree + 1));
	std::cout<<"coefficient count: "<<polynomial.getCoefficientCount()<<std::endl;
	Utility::generateRandomPolynomial(polynomial);
	polynomial.displayCoefficients();
}
