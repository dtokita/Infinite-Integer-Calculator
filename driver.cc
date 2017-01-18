//Fil: driver.cc

#include "infint.h"
#include "integer.cc"
#include "display.h"
#include <iostream>

using namespace std;

main(){
	Integer a, b, sum, difference, product, quotient, answer;

	a.getInteger();
	b.getInteger();

	a.convertToBin();
	b.convertToBin();

	sum = a.add(b);
	difference = a.subtract(b);
	product = a.multiply(b);
	quotient = a.divide(b);
	answer = a.exponent(b);

	cout << endl <<"The sum is: ";	
	sum.displayBinToDec();

	cout << "The difference is: ";
	difference.displayBinToDec();

	cout << "The product is: ";
	product.displayBinToDec();

	cout << "The quotient is: ";
	quotient.displayBinToDec();

	cout << "The answer is: ";
	answer.displayDec();
	cout << endl << endl;
}
