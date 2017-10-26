/*---------------------------------------------
//Name: Nguyen, Royce & Alharbi, Abdulrahman
//Course: CPSC 240
//Assignment: Project No. 6 Part 1
//Due date: October 5, 2017
//Purpose: Return total numbers in array
---------------------------------------------*/
#include <iostream>

using namespace std;

int s[4][4] = { 10, 20, 30, 40,
20, 10, 40, 30,
5, 15, 20, 25,
30, 25, 20, 15 };
int total;
void displayTotal()
{
	cout << total << endl;
}
void printAllShirts()
{
	cout << "a) Total number of all shirts = ";
}
void printBlackShirts()
{
	cout << "b) Total number of black shirts = ";
}
void printLargeShirts()
{
	cout << "c) Total number of large shirts = ";
}

int main()
{
	int i = 0;
	_asm
	{
		mov total, 0
		mov i, 0
		mov ebx, 0
	AllShirts:
		cmp i, 16
		Je Done1
		mov eax, [s + ebx]
		add total, eax
		add ebx, 4
		inc i
		Jmp AllShirts
	Done1:
		call printAllShirts
		call displayTotal
		mov total, 0
		mov i, 0
		mov ebx, 8
	LargeShirts :
		cmp i, 4
		Je Done2
		mov eax, [s + ebx]
		add total, eax
		add ebx, 16
		inc i
		Jmp LargeShirts
	Done2 :
		call printLargeShirts
		call displayTotal
		mov total, 0
		mov i, 0
		mov ebx, 48
	BlackShirts :
		cmp i, 4;
		Je Done3
		mov eax, [s + ebx]
		add total, eax
		add ebx, 4
		inc i
		Jmp BlackShirts
	Done3 :
		call printBlackShirts
		call displayTotal
	}

	getchar();
	return 0;
}
/*-----------------Output--------------------
a) Total number of all shirts = 355
c) Total number of large shirts = 110
b) Total number of black shirts = 90

-------------------------------------------*/