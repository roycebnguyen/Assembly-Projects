/*---------------------------------------------------------------------------------
//Name: Nguyen, Royce & Alharbi, Abdulrahman
//Course: CPSC 240
//Due Date: September 28, 2017
//Assignment: Project No. 5 Part 2
//Purpose: Check if a 4-digit hex PIN is even or not
----------------------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

int beefCount, fadeCount, cabeCount;
int checkBeef, checkFade, checkCabe;
int isEven = 2, counter = 0; // Divide total with this to see if there is remainder
string pin[3] = { "BEEF", "FADE", "CABE" }; // Array for PIN combinations
void valid()
{
	cout << pin[counter] << " is a valid ID for the family" << endl;
}
void invalid()
{
	cout << pin[counter] << " is not a valid ID for the family" << endl;
}
int main()
{
	_asm
	{
	BEEF:
		mov eax, 1111000000000000b
		mov checkBeef, 0xbeef
		and eax, checkBeef
		shr eax, 12
		mov beefCount, eax
		mov eax, 0000111100000000b
		and eax, checkBeef
		shr eax, 8
		add beefCount, eax
		mov eax, 0000000011110000b
		and eax, checkBeef
		shr eax, 4
		add beefCount, eax
		mov eax, 0000000000001111b
		and eax, checkBeef
		add beefCount, eax
		mov eax, beefCount		
		cwd
		idiv isEven
		cmp edx, 0
		Je BeefEven
		call invalid
		Jmp Done
	BeefEven:
		call valid
	FADE:
		mov eax, 1111000000000000b
		mov checkFade, 0xfade
		and eax, checkFade
		shr eax, 12
		mov fadeCount, eax
		mov eax, 0000111100000000b
		and eax, checkFade
		shr eax, 8
		add fadeCount, eax
		mov eax, 0000000011110000b
		and eax, checkFade
		shr eax, 4
		add fadeCount, eax
		mov eax, 0000000000001111b
		and eax, checkFade
		add fadeCount, eax
		mov eax, fadeCount
		inc counter		
		cwd
		idiv isEven
		cmp edx, 0
		Je FadeEven
		call invalid
		Jmp Done
	FadeEven:
		call valid
	CABE:
		mov eax, 1111000000000000b
		mov checkCabe, 0xcabe
		and eax, checkCabe
		shr eax, 12
		mov cabeCount, eax
		mov eax, 0000111100000000b
		and eax, checkCabe
		shr eax, 8
		add cabeCount, eax
		mov eax, 0000000011110000b
		and eax, checkCabe
		shr eax, 4
		add cabeCount, eax
		mov eax, 0000000000001111b
		and eax, checkCabe
		add cabeCount, eax
		mov eax, cabeCount
		inc counter	
		cwd
		idiv isEven
		cmp edx, 0
		Je CabeEven
		call invalid
		Jmp Done
	CabeEven:
		call valid
	Done:
	
	}

	system("pause");
	return 0;
}
/*---------------Output-----------------
BEEF is a valid ID for the family
FADE is a valid ID for the family
CABE is not a valid ID for the family
Press any key to continue . . .
----------------------------------------*/