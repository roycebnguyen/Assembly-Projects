/*-----------------------------------------------------------
Name: Nguyen, Royce & Alharbi, Abdulrahman
Course: CPSC 240
Assignment: Project No. 7 Part 1
Due Date: October 12, 2017
Purpose: Calculate the area & perimeter using floating point
parameters for a triangle and rectangle
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>

using namespace std;

float a, b, c, h, triangleArea, trianglePerimeter;
float half = 0.5f;
float l, w, rectArea, rectPerimeter;

// 4.3 6.1 9.5 10.7
// 15.1 10.6

void displayMenu()
{
	cout << "Please enter for a, b, c, and h: ";
	cin >> a >> b >> c >> h;
	cout << "Please enter for length and width: ";
	cin >> l >> w;
}
void printResults()
{
	cout << fixed << setprecision(2);
	
	cout << "Triangle" << endl;
	cout << "\tArea...................... " << triangleArea << endl;
	cout << "\tPerimeter................. " << trianglePerimeter << endl << endl;

	cout << "Rectangle" << endl;
	cout << "\tArea...................... " << rectArea << endl;
	cout << "\tPerimeter................. " << rectPerimeter << endl;
}

int main()
{
	_asm
	{
		call displayMenu

		// Triangle Area
		fld half
		fld c
		fld h
		fmul
		fmul
		fstp triangleArea

		// Triangle Perimeter
		fld a
		fld b
		fld c
		fadd
		fadd
		fstp trianglePerimeter

		// Rectangle Area
		fld l
		fld w
		fmul
		fstp rectArea

		// Rectangle Perimeter
		fld l
		fld l
		fld w
		fld w
		fadd
		fadd
		fadd
		fstp rectPerimeter

		call printResults
	}

	system("pause");
	return 0;
}
/*---------------------Output---------------------
Please enter for a, b, c, and h: 4.3 6.1 9.5 10.7
Please enter for length and width: 15.1 10.6
Triangle
	Area...................... 50.83
	Perimeter................. 19.90

Rectangle
	Area...................... 160.06
	Perimeter................. 51.40
Press any key to continue . . .
-------------------------------------------------*/