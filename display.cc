//File: display.cc
//Name: Dylan Tokita

#include <iostream>
#include "display.h"

using namespace std;

#define LENGTH 100
#define HEIGHT 100

void displayWelcome(){
	clearScreen();
	displayStars(LENGTH);
	displayStars(LENGTH), cout << endl;

        cout << "Welcome to the Calculator." << endl << endl;
        cout << "Please enter your selection below." << endl << endl;
	cout << "Enter 'S' or 's' to start." << endl;
	cout << "Enter 'AS' or 'as' to start using last answer as first integer." << endl << endl;
	cout << "Enter 'D' or 'd' to change the input to decimal." << endl;
	cout << "Enter 'B' or 'b' to change the input to binary." << endl << endl;
	cout << "Enter 'Z' or 'z' to toggle decimal output." << endl;
	cout << "Enter 'X' or 'x' to toggle binary output." << endl;
	cout << "Enter 'C' or 'c' to toggle scientific notation output." << endl;
	cout << "Enter 'F' or 'f' to change the number of digits you wish to float in scientific notation." << endl << endl;
	cout << "Enter 'H' or 'h' for help and limitations of this calculator." << endl << endl;
	cout << "Enter 'Q' or 'q' to quit." << endl << endl;	

	displayStars(LENGTH);
	displayStars(LENGTH);
	promptUser();
}

void displayStars(int n){
	for(int i = 0; i < n; i++)
		cout << "*";

	cout << endl;
}

void blankLine(){
	cout << endl;
}

void clearScreen(){
	for(int i = 0; i < HEIGHT; i++)
		cout << endl;
}

void promptUser(){
	cout << "Please enter your selection: ";
}

void displayHelp(){
	clearScreen();
	displayStars(LENGTH);
	displayStars(LENGTH), cout << endl;

	cout << "Help and Limitations." << endl << endl;
	cout << "Help" << endl << endl;

	cout << "To use this calculator, press 'S' or 's' at the welcome screen." << endl;
	cout << "Follow the prompts given by the calculator in order to get the answer." << endl << endl;
	
	cout << "Note: By default, full decimal output is enabled. Follow prompts on welcome screen" << endl;
	cout << "to change the output type. (Multiple can be enabled at once.)" << endl << endl;

	cout << "Limitations" << endl << endl;

	cout << "This calculator is designed to accept positive and negative integers." << endl;
	cout << "This calculator can perform addition, subtraction, multiplicaiton and division" << endl;
	cout << "on both positive and negative integers. However it can only take positive" << endl;
	cout << "exponents when performing exponentiations. When calculating factorials," << endl;
	cout << "The aboslute value will be taken. All answers are integers." << endl << endl;

	cout << "Enter 'Q' or 'q' to return to the welcome screen." << endl << endl;

	displayStars(LENGTH);
	displayStars(LENGTH);
	promptUser();
}

void displayCalculator(){
	clearScreen();
	displayStars(LENGTH);
	displayStars(LENGTH), cout << endl;

	cout << "Note:" << endl;
	cout << "'+' denotes addition." << endl;
	cout << "'-' denotes subtraction." << endl;
	cout << "'*' denotes multiplication." << endl;
	cout << "'/' denotes division." << endl;
	cout << "'^' denotes exponentiation." << endl;
	cout << "'$' denotes square root." << endl;
	cout << "'!' denotes factorial." << endl << endl;

	cout << "Please enter integers/operands one at a time. (Wait to be prompted)" << endl << endl;

	displayStars(LENGTH);
	displayStars(LENGTH);
}












