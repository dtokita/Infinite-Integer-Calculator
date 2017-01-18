//File: integer.h

#include "infint.h"

using namespace std;

class Integer{
	public:
	/* Constructor */
	Integer();
	//Initializes all private fields to 0

	/* Creation Functions */
	void getInteger();
	//This function allows the user to input an integer of arbitrary size
	//and stores the value in the 'value' field of this class.

	void getBin();
	//This function allows the user to input an integer of arbitrary size
	//and stores the value in the 'binvalue' field of this class.

	void convertToBin();
	//This function takes the value in 'value', converts it to binary
	//and then stores in 'binvalue'.

        void convertBinToDec();
        //This function takes the value in 'binvalue', converts to to decimal
        //and then stores in 'value'

	/* Operation Functions */
	Integer add(const Integer x) const;
	//This function adds two integers of arbitrary length
	//and returns an Integer class with the sum stored in 
	//'value'

	Integer subtract(const Integer x) const;
	//This function subtracts two integers of arbitrary length
	//and returns an Integer class with the difference stored in
	//'value'

	Integer multiply(const Integer x) const;
	//This function multiplies two integers of arbitrary length
	//and returns an Integer class with the product stored in 
	//'value'	

	Integer divide(const Integer x) const;
	//This function divides two integers of arbitrary length
	//and returns an Integer class with the quotient stored in
	//'value'

	Integer exponent(const Integer x) const;
	//This function takes a positive integer as an input and will
	//raise the base to the given, positive power. An integer class
	//containing the answer in 'value' is returned.

	Integer factorial() const;
	//This function takes an integer and takes the absolute value 
	//and performs the factorial operation. An integer class
	//containing the answer in 'value' is returned. 

	Integer squareRoot() const;

	/* Overloaded operators */
	Integer operator+(const Integer x) const;
	Integer operator-(const Integer x) const;
	Integer operator*(const Integer x) const;
	Integer operator/(const Integer x) const;
	Integer operator^(const Integer x) const;

	/* Display Functions */
	inline void displayDec() const; 
	//This function will display 'value' in decimal form.

	void displayBinToDec();
	//This function will display 'binvalue' in decimal form.

	void displayBin() const;
	//This function will display 'binvalue' in binary form.

	string displaySciNot(int n = 7) const;
	//This function will display 'value' in scientific notation
	//with n significant digits.

	private:
	InfInt value;
	//This InfInt holds the decimal representation of the Integer.

	InfInt binvalue;
	//This InfInt holds the binary representation of the Integer.
	
	bool negative;
	//If false, the Integer is positive, if true, the Integer is negative.

        Integer addPositive(const Integer x) const;
	//This function adds two positive integers of arbitrary length
	//and returns an Integer class with the sum stored in 'binvalue'

        Integer subtractPositive(const Integer x) const;
	//This funciton subtracts two positive integers of arbitrary length
	//and returns an Integer class with the difference stored in 'binvalue'
	
	Integer multiplyPositive(const Integer x) const;
	//This function multiplies two positive integers of arbitrary length
	//and returns an Integer class with the product stored in 'binvalue'

	Integer dividePositive(const Integer x) const;
	//This function divides two positive integers of arbitrary length
	//and returns an Integer class with the quotient stored in 'binvalue'

};
