//File: integer.cc

#include "integer.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**************
* CONSTRUCTOR *
**************/

Integer::Integer(){
	value = 0;
	binvalue = 0;
	negative = 0;
}

/*********************
* CREATION FUNCTIONS *
*********************/

void Integer::getInteger(){
	string input;
	cin.ignore();	

	//Place string from cin into 'value' field
	getline(cin, input);
	InfInt temp = input;

	//We want to work with positive values
	if(temp < 0){
		//Make positive
		temp = temp * -1;
		//Turn on negative flag
		negative = 1;	
	}

	value = temp;
	
	//Converts to binary and stores in binvalue
	convertToBin();
}

void Integer::getBin(){
	string input;
	cin.ignore();

	getline(cin, input);
	InfInt temp = input;

	//We want to work with positive values
	if(temp < 0){
		//Make positive
		temp = temp * -1;
		//Turn on negative flag
		negative = 1;
	}

	binvalue = temp;

	//Converts to decimal and places in value
	convertBinToDec();
}

void Integer::convertToBin(){
	InfInt sum = 0, i = 1, rem;

	//Make a copy so we don't alter the current value
	Integer temp = *this;

	//If negative 'value'
	if(temp.value < 0){
		//Turn on negative flag
		negative = 1;

		//Make 'value' positive
		temp.value = temp.value * -1;
	}

	//Convert to binary
	do{
		rem = temp.value % 2;
		sum = sum + (i * rem);
		temp.value = temp.value / 2;	
		i = i * 10;

	} while(temp.value > 0);

	#define DEBUGconvertToBin
	#ifndef DEBUGconvertToBin
	
	cout << "The binary representation is: " << sum << endl;

	#endif

	binvalue = sum;
}

void Integer::convertBinToDec(){
        InfInt power = 2;
        value = 0;

        if(binvalue.digitAt(0) == 1){
                value = 1;
        }

        for(int i = 1; i < binvalue.numberOfDigits(); i++){
                value = value + (power * binvalue.digitAt(i));
                power = power * 2;
        }
}

/********************
* DISPLAY FUNCTIONS *
********************/

void Integer::displayDec() const{
	if(negative == 1)
		cout << "-" << value;

	else
		cout << value;
}

void Integer::displayBinToDec(){
	InfInt power = 2;

	if(binvalue.digitAt(0) == 1){
		value = 1;
	}

	//Convert from binary to decimal
	for(int i = 1; i < binvalue.numberOfDigits(); i++){
		value = value + (power * binvalue.digitAt(i));
		power = power * 2;
	}	
	
	if(negative == 0){
		cout << value << endl;
	}

	else if(negative == 1){
		cout << "-" << value << endl;
	}

	
}

void Integer::displayBin() const{
	if(negative == 1)
		cout << "-" << binvalue;

	else
		cout << binvalue;
}

string Integer::displaySciNot(int n) const{
	string SciNot, 
	temp = value.toString(); //Convert value into a string

	InfInt a = temp.length() - 1; 

	if(negative == 1)
		SciNot += "-";
	
	SciNot += temp.at(0);
	SciNot += ".";

	if(n > temp.length()){
		for(int i = 1; i < temp.length(); i++)
			SciNot += temp.at(i);

		for(int i = temp.length(); i < n; i++)
			SciNot += "0";
	}
	
	else{
		for(int i = 1; i < n; i++){
			SciNot += temp.at(i);	
		}
	}

	SciNot += "e";
	temp = a.toString();
	SciNot += temp;

	cout << SciNot;

	return SciNot;
}

/**********************
* OPERATION FUNCTIONS *
**********************/

Integer Integer::add(const Integer x) const{
	if(negative == 0 && x.negative == 0){
		return addPositive(x);
	}

	else if(negative == 0 && x.negative == 1){
		return subtractPositive(x);
	}

	else if(negative == 1 && x.negative == 0){
		return x.subtractPositive(*this);
	}	

	else if(negative == 1 && x.negative == 1){
		Integer sum;
		sum = addPositive(x);
		sum.negative = 1;
		return sum;
	}
}

Integer Integer::subtract(const Integer x) const{
	if(negative == 0 && x.negative == 0){
		return subtractPositive(x);
	}

	else if(negative == 0 && x.negative == 1){
		return addPositive(x);
	}

	else if(negative == 1 && x.negative == 0){
                Integer difference;
                difference = addPositive(x);
                difference.negative = 1;
                return difference;
	}
	
	else if(negative == 1 && x.negative == 1){
		return x.subtractPositive(*this);
	}
}

Integer Integer::multiply(const Integer x) const{
	if(negative == 0 && x.negative == 0)
		return multiplyPositive(x);

	else if(negative == 0 && x.negative == 1){
		Integer product;
		product = multiplyPositive(x);
		product.negative = 1;
		return product;
	}

	else if(negative == 1 && x.negative == 0){
                Integer product;
                product = multiplyPositive(x);
                product.negative = 1;
                return product;
	}

	else if(negative == 1 && x.negative == 1)
		return multiplyPositive(x);
}

Integer Integer::divide(const Integer x) const{
        if(negative == 0 && x.negative == 0)
                return dividePositive(x);

        else if(negative == 0 && x.negative == 1){
                Integer quotient;
                quotient = dividePositive(x);
                quotient.negative = 1;
                return quotient;
        }

        else if(negative == 1 && x.negative == 0){
                Integer quotient;
                quotient = dividePositive(x);
                quotient.negative = 1;
                return quotient;
        }

        else if(negative == 1 && x.negative == 1)
                return dividePositive(x);
}

Integer Integer::exponent(const Integer x) const{
	Integer answer;
	answer.value = 1;
	InfInt temp = value;

	//Using right-to-left binary exponentiation
	for(int i = 0; i < x.binvalue.numberOfDigits(); i++){
		if(x.binvalue.digitAt(i) == 1){
			answer.value = answer.value * temp;
		}	

		temp = temp * temp;
	}

	if(negative == 1 && x.value % 2 == 1)
		answer.negative = 1;

	/* This increases computational time significantly */
	//answer.convertToBin();	
	return answer;
}

Integer Integer::factorial() const{
	Integer answer, temp = *this;
	answer.value = 1;	

	if(temp.value < 0)
		temp.value = temp.value * -1;

	for(InfInt i = 2; i <= temp.value; i++){
		answer.value = answer.value * i;
	}

	return answer;
}

Integer Integer::squareRoot() const{
	Integer answer, temp = *this;

	if(temp.value < 0){
		temp.value = temp.value * -1;
	}

	answer.value = value.intSqrt();

	return answer;
}

/***********************
* OVERLOADED OPERATORS *
***********************/

Integer Integer::operator+(const Integer x) const{
	return add(x);
}

Integer Integer::operator-(const Integer x) const{
	return subtract(x);
}

Integer Integer::operator*(const Integer x) const{
	return multiply(x);
}

Integer Integer::operator/(const Integer x) const{
	return divide(x);
}

Integer Integer::operator^(const Integer x) const{
	return exponent(x);
}


/********************
* PRIVATE FUNCTIONS *
********************/

Integer Integer::addPositive(const Integer x) const{
	Integer sum;
	InfInt power = 1;

	sum.value = value + x.value;

	#define DEBUGaddPositive
	#ifndef DEBUGaddPositive

	sum.convertToBin();
	cout << "The binary representation of the sum is: " << sum.binvalue << endl;

	#endif

	return sum;
}


Integer Integer::subtractPositive(const Integer x) const{
	Integer difference;
	InfInt power = 1;

	difference.value = value - x.value;
	
	if(difference.value < 0){
		difference.negative = 1;
		difference.value = difference.value * -1;
	}

        #define DEBUGsubtractPositive
        #ifndef DEBUGsubtractPositive

	difference.convertToBin();
        cout << "The binary representation of the difference is: " << difference.binvalue << endl;

        #endif
	return difference;
}	

Integer Integer::multiplyPositive(const Integer x) const{
	Integer product;

	product.value = value * x.value;
	
	#define DEBUGmultiplyPositive
	#ifndef DEBUGmultiplyPositive

	product.convertToBin();
	cout << "The binary representation of the product is: " << product.binvalue << endl;

	#endif

	return product;
}

Integer Integer::dividePositive(const Integer x) const{
	Integer quotient;
	InfInt power = 1;

	quotient.value = value / x.value;

	#define DEBUGdividePositive
	#ifndef DEBUGdividePositive

	quotient.convertToBin();
	cout << "The binary representation of the quotient is: " << quotient.binvalue << endl;

	#endif

	return quotient;
}


























