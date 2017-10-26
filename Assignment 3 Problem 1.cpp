#include <iostream>

using namespace std;

int numDrinks, numSandwiches, bill, drinksCost, sandwichCost, sandwichType;
int soda = 2, water = 1, tenin = 3, twelve = 5;
char drinkType, yesNo;
void displayMenu()
{
	cout << "-----------------------------7-11 Convenient Store-----------------------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda (S).............................................................$2" << endl;
	cout << "\tWater (W)............................................................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inch.............................................................$3" << endl;
	cout << "\t12 inch.............................................................$5" << endl;
}
void askNumDrinks()
{
	cout << "How many drinks? ";
	cin >> numDrinks;
}
void askNumSandwiches()
{
	cout << "How many sandwiches? ";
	cin >> numSandwiches;
}
void askDrinkType()
{
	cout << "\tWhat kind of drink? (S = Soda, W = Water) ";
	cin >> drinkType;
}
void askSandwichType()
{
	cout << "\tWhat kind of sandwich? (10/12 inch) ";
	cin >> sandwichType;
}
void continueYesNo()
{
	cout << "Continue? (Y/N) ";
	cin >> yesNo;
}
void displayBill()
{
	cout << "Total bill: $" << bill << endl;
}

int main()
{
	_asm
	{
		call displayMenu
	doWhile:
		call askNumDrinks
		call askDrinkType
		mov eax, numDrinks
		cmp drinkType, 'S'
		Je Soda
		cmp drinkType, 'W'
		Je Water
	Soda:
		imul soda
		mov drinksCost, eax
		Jmp Sandwich
	Water:
		imul water
		mov drinksCost, eax
		Jmp Sandwich
	Sandwich:
		call askNumSandwiches
		call askSandwichType
		mov ebx, numSandwiches
		cmp sandwichType, 10
		Je Ten
		cmp sandwichType, 12
		Je Twelve
	Ten:
		mov ebx, numSandwiches
		imul tenin
		mov sandwichCost, ebx
		add eax, ebx
		Jmp Calculate
	Twelve:
		imul twelve
		add eax, ebx
	Calculate:
		//add sandwichCost, eax
		mov bill, ebx
		call displayBill
	cont:
		call continueYesNo
		cmp yesNo, 'Y'
		Je doWhile
	done:

	}
	cout << sandwichCost << endl;
	cout << drinksCost << endl;


	system("pause");
	return 0;
}