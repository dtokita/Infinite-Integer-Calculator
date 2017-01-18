#include "infint.h"
#include "display.h"
#include "integer.cc"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main(){
	char c, d; //Characters for user input in switch statement

	int n = 7; //Default value for number of digits floated

	bool quit = 0, //False to continue calculator, true to quit
	binout = 0, //False to supress binary output, true to display binary
	decout = 1, //False to supress decimal output, true to display decimal
	scinot = 0, //False to supress scientific notation output, true to display scientific notation
	binmode = 0, //False to turn off binary input, true to turn on binary input
	ansmode = 0; //False to turn off ans feature, true to turn on as feature

	Integer ans;

	displayWelcome(); //Display the initial welcome screen

	while(!quit){
		c = getchar();
	
		Integer a, b, answer;
	
		switch(c){
			//Help screen
			help:
			case 'H':
			case 'h':
				displayHelp();
				d = getchar();

				if(d == 'Q' || d == 'q')
						break;
				else
					goto help;

				break;

			//Start the calculator
			case 'S':
				goto s;

			s:
			case 's':{
				clock_t t;
				
				displayCalculator();
				//If ans feature is turned off
				if(!ansmode){
					//If binary input is turned off
					if(!binmode){
						cout << "Note: You are in decimal input mode." << endl << "Enter the first integer of arbitrary size: ";
						a.getInteger();
					}
					
					//If binary input is turned on
					else{
						cout << "Note: You are in binary input mode." << endl << "Enter the first binary number of arbitrary size: ";
						a.getBin();
					}		
				}

				//If ans feature is enabled
				else{
					//Set first input to the previous answer (0 if first run)
					a = ans;
					ansmode = 0;
					cin.ignore();
				}	

				displayCalculator();
				cout << "Enter the operand: ";
				d = getchar();

				//Factorial and square root are dependent only on first input
				if(d == '!')
					goto factorial;

				if(d == '$')
					goto sqrt;
				

				displayCalculator();

				//If binary input is turned off
				if(!binmode){
					cout << "Note: You are in decimal input mode." << endl << "Enter the second integer of arbitrary size: ";	
					b.getInteger();
				}

				//If binary input is turned on
				else{
					cout << "Note: You are in binary input mode." << endl << "Enter the second binary number of arbitrary size: ";
					b.getBin();
				}

				//Perform the appropriate calculation based on inputted operand
				switch(d){
					case '+':
						t = clock();
						answer = a + b;
						break;
					
					case '-':
						t = clock();
						answer = a - b;
						break;
	
					case '*':
						t = clock();
						answer = a * b;
						break;

					case '/':
						t = clock();
						answer = a / b;
						break;

					case '^':
						t = clock();
						answer = a ^ b;
						break;

					factorial:
					case '!':
						cin.ignore();
						t = clock();
						answer = a.factorial();
						break;
					
					sqrt:
					case '$':
						cin.ignore();
						t = clock();
						answer = a.squareRoot();

					default:
						break;
				}

				//Display binary if binary output is enabled
				if(binout){
					t = clock() - t;
					answer.convertToBin();
					a.displayBin();
					cout << " " << d << " ";
					b.displayBin();
					cout << " = ";
					answer.displayBin();
					cout << endl << endl;
				}

				//Display decimal if decimal output is enabled
				if(decout){
					t = clock() - t;
					a.displayDec();
					cout << " " << d << " ";
					b.displayDec();
					cout << " = ";
					answer.displayDec();
					cout << endl << endl;
				}
				
				//Display scientific notation if scientific output is enabled
				if(scinot){
					t = clock() - t;
					a.displaySciNot(n);
					cout << " " << d << " ";
					b.displaySciNot(n);
					cout << " = ";
					answer.displaySciNot(n);
					cout << endl << endl;
				}

				//Store in case user wants to use ans feature
				ans = answer;

				//Display computation time
				cout << "The calculation took " << ((float)t)/CLOCKS_PER_SEC << " seconds." << endl;

				cout << "Press enter to continue.";
				getchar();
			
				break;
			}

			//Quit
			case 'Q':
			case 'q':
				quit = 1;
				break;

			//Decimal input
			case 'D':
			case 'd':
				binmode = 0;
				break;

			//Binary input
			case 'B':
			case 'b':
				binmode = 1;
				break;

			//Ans feature
			case 'A':
			case 'a':
				ansmode = 1;
				break;			

			//Toggle decimal output
			case 'Z':
			case 'z':
				if(decout){
					decout = 0;
					cout << "Decimal output has been toggled off. Press enter to continue.";
				}

				else{
					decout = 1;
					cout << "Decimal output has been toggled on. Press enter to continue.";
				}

				cin.ignore();
				getchar();
				break;

			//Toggle binary output
			case 'X':
			case 'x':
                                if(binout){
                                        binout = 0;
                                        cout << "Binary output has been toggled off. Press enter to continue.";
                                }

                                else{
                                        binout = 1;
                                        cout << "Binary output has been toggled on. Press enter to continue.";
                                }

				cin.ignore();
				getchar();
				break;

			//Toggle scientific notation output
			case 'C':
			case 'c':
                                if(scinot){
                                        scinot = 0;
                                        cout << "Scientific notation output has been toggled off. Press enter to continue.";
                                }

                                else{
                                        scinot = 1;
                                        cout << "Scientific notation output has been toggled on. Press enter to continue.";
                                }
				
				cin.ignore();
				getchar();
				break;

			//Change float value
			case 'F':
			case 'f':
				cout << "Enter the number of digits you wish to float: ";
				scanf("%d", &n);
		
			default:
				break;	
		}
		
		displayWelcome();
	}
}



















