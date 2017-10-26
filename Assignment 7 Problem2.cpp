/*-----------------------------------------------------------
Name: Nguyen, Royce & Alharbi, Abdulrahman
Course: CPSC 240
Assignment: Project No. 7 Part 2
Due Date: October 12, 2017
Purpose: To find the two real roots of a quadratic equation
given a, b, and c
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>

using namespace std;

float  x1, x2, a, b, c, numerator;
float four = 4.0f, two = 2.0f, negative = -1.0f;
// 2.1 4.5 1.7
void displayMenu()
{
	cout << "To see the real roots of aX^2 + bX + c = 0, enter the a,b, and c values: ";
	cin >> a >> b >> c;
}
void displayAnswer()
{
	cout << fixed << setprecision(2) << "\tX1 = " << x1 << "\tX2 = " << x2 << endl;
}

int main()
{
	_asm
	{
		call displayMenu
		fld b
		fld b
		fmul		// b^2

		fld four
		fld a
		fld c
		fmul
		fmul		// 4ac
		
		fsub		// b^2 - 4ac
		fsqrt		// sqrt(b^2 - 4ac)
		fstp numerator

		fld negative
		fld b			// -b
		fmul
		fld numerator
		fadd			// -b + sqrt(b^2 - 4ac)

		fld two
		fld a
		fmul			// 2a
		fdiv			// (-b + sqrt(b^2 - 4ac)) / 2a
		fstp x1

		fld negative
		fld b	
		fmul			// -b
		fld numerator
		fsub			// -b - sqrt(b^2 - 4ac)

		fld two
		fld a
		fmul			// 2a
		fdiv			// (-b - sqrt(b^2 - 4ac)) / 2a
		fstp x2

		call displayAnswer
	}

	system("pause");
	return 0;
}