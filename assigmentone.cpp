/**********************************************************
**Program: assigmentone.cpp
**Author: Tanish Hupare
**Despcription: This program will estimate the monthly mortgage payment for an individual based on what they input into the terminal
**Input: Home price(in dollars), Down payment (in dollars), Lenght of loan (in dollars),
Annual interest rate (in years)
**Output: Monthly mortgage payment, total paid, principle paid, interest paid.
*******************/
//tanish
#include <iostream> 
#include <iomanip>: setprecision()
#include <cmath>: pow()

int main()
{

// this string is outputing the introduction to the mortage calculator
	std::cout << "hello and welcome to the mortage calculator" << std::endl << std::endl;

// these variables are all the inputs that will be needed for the calculations

	double hprice;
	double dpay;
	double lofloan;
	double irate;
 
// the code below is to let the user intput their informations for each statment 
// input will go towards the variables
	std::cout << "enter the house price, in dollars: ";
	std::cin >> hprice;
	std::cout << std::endl;

	std::cout << "enter the down payment, in dollar: ";
	std::cin >> dpay;

	std::cout << "enter the lenght of loan, in years: ";
	std::cin >> lofloan;

	std::cout << "enter the Annual Interest Rate, in percentage: ";
	std::cin >> irate;
	std::cout << std::endl;

// below are math operators that will go towards the main monthly motrgage equations
// the reason we split this up is because it simplyfies the monthly mortgage equation
// assigning variables will help in writing the code for the monthly mortgage

	double mp;
	mp = hprice - dpay;


	double ri;
	ri = (irate / 100) / 12;

	double pn;
	pn = lofloan * 12;

// the code below is the equation for the monthly mortgage 
// it uses all the varibles from the code above to calculate the monthly mortgage payment

	double e;
	e = 1 + ri;
	
	double r;
	r = pow(e,pn);

	double m;
	m = (mp *(ri*r))/(r-1);
	std::cout << "Your estimated monthly payment is: $ " << m << std::endl;

// below will output all the infromation regarding the idviduals payments such as total paid, principle paid, total interest paid
	std:: cout << std:: fixed << std:: setprecision(2);
	std:: cout << "total paid: " << m * 12 * 15 << std:: endl;
	std:: cout << "Principal paid: " << mp << std:: endl;
	std:: cout << "total interest paid: " << m * 12 * 15 - mp << std::endl;

//end of code, thank you!!




return 0;


}
