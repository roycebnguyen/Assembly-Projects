/*-----------------------------------------------------------
Name: Nguyen, Royce & Alharbi, Abdulrahman
Course: CPSC 240
Assignment: Project No. 7 Part 3
Due Date: October 12, 2017
Purpose: Calculate the total bill with floating point
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>

using namespace std;

float totalPrice, drinksPrice, sandwichesPrice, numDrinks, numSandwiches;
float sodaPrice = 2.25f, waterPrice = 1.75f;
float tenInchPrice = 3.45f, twelveInchPrice = 5.25;
char drinkChoice, sandwichChoice;

void displayMenu()
{
	cout << "------------------7-11 Convienient Store------------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(S)......................................$2.25" << endl;
	cout << "\tWater(W).....................................$1.75" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inches....................................$3.45" << endl;
	cout << "\t12 inches....................................$5.25" << endl << endl;
}
void getInput()
{
	cout << "How many drinks? ";
	cin >> numDrinks;

	cout << "\tWhat kind of drink (S=Soda, W=Water)? ";
	cin >> drinkChoice;

	cout << "How many sandwiches? ";
	cin >> numSandwiches;

	cout << "\tWhat size of sandwich (10/12 inches)? ";
	cin >> sandwichChoice;
}
void printTotal()
{
	cout << "Your total bill = " << totalPrice << endl;
}

int main()
{
	_asm
	{
		call displayMenu
		call getInput
	Drinks:
		fld numDrinks
		cmp drinkChoice, 'S'
		Je Soda
		cmp drinkChoice, 'W'
		Je Water
	Soda:
		fld sodaPrice
		fmul
		fstp drinksPrice
		Jmp Sandwiches
	Water:
		fld waterPrice
		fmul
		fstp drinksPrice
		Jmp Sandwiches
	Sandwiches:
		fld numSandwiches
		cmp sandwichChoice, '10'
		Jmp Ten
		cmp sandwichChoice, '12'
		Jmp Twelve
	Ten:
		fld tenInchPrice
		fmul
		fstp sandwichesPrice
		Jmp Total
	Twelve:
		fld twelveInchPrice
		fmul
		fstp sandwichesPrice
	Total:
		fld drinksPrice
		fld sandwichesPrice
		fadd
		fstp totalPrice
		call printTotal
	}

	system("pause");
	return 0;
}
/*-------------------------Output-------------------------
------------------7-11 Convienient Store------------------
Drinks
Soda(S)......................................$2.25
Water(W).....................................$1.75
Sandwiches
10 inches....................................$3.45
12 inches....................................$5.25

How many drinks? 2
	What kind of drink (S=Soda, W=Water)? S
How many sandwiches? 3
	What size of sandwich (10/12 inches)? 10
Your total bill = 14.85
Press any key to continue . . .
--------------------------------------------------------*/
