/*-----------------------------------------------
//Name: Nguyen, Royce & Alharbi, Abdulrahman
//Course: CPSC 240
//Assignment: Project No. 6 Part 3
//Due date: October 5, 2017
//Purpose: Return total numbers in a 3-D array
-----------------------------------------------*/

#include <iostream>

using namespace std;

int a[3][3][2] = { 1, 2, 3,
				   4, 5, 6,
				   7, 8, 9,
				   10, 11, 12,
				   13, 14, 15,
				   16, 17, 18 };

int position = 0, count = 4, totalShirts = 0, totalMedium = 0, totalShortSleeve = 0, totalRed = 0;


void displayTotal() 
{
	cout << "a) Total number of all shirts = " << totalShirts << endl;
}
void displayTotalMedium() 
{
	cout << "b) Total number of medium shirts = " << totalMedium << endl;
}
void displayTotalShortSleeve() 
{
	cout << "c) Total number of short sleeve shirts = " << totalShortSleeve << endl;
}
void displayTotalRed() 
{
	cout << "d) Total number of red shirts = " << totalRed << endl;
}

int main()
{
	_asm 
	{
		mov ebx, 0
	Loop1:
		cmp position, 18
		Je Done1
		mov eax, [a + ebx]
		add totalShirts, eax
		add ebx, 4
		inc position
		Jmp Loop1
	Done1:
		call displayTotal
		mov ebx, 8
		mov position, 0
	Loop2:
		cmp position, 3
		Je Done2
		mov eax, [a + ebx]
		add totalMedium, ebx
		add ebx, 4
		mov ecx, 8
		imul count
		mov eax, ecx
		inc position
		add count, 3
		Jmp Loop2
	Done2: 
		call displayTotalMedium
		mov eax, 8
		mov position, 0
	Loop3:
		cmp position, 9
		Je Done3
		imul position
		mov ecx, eax
		mov eax, 8
		inc position
		mov ebx, [a + ecx]
		add totalShortSleeve, ebx
		Jmp Loop3
	Done3:
		call displayTotalShortSleeve
		mov eax, 0
		mov position, 0
	Loop4:
		cmp position, 6
		Je Done4
		mov ebx, [a + eax]
		add totalRed, ebx
		inc position
		add eax, 4
		Jmp Loop4
	Done4:
		call displayTotalRed
	}

	getchar();
	return 0;
}
/*-----------------Output--------------------
a) Total number of all shirts = 171
b) Total number of medium shirts = 57
c) Total number of short sleeve shirts = 81
d) Total number of red shirts = 21

-------------------------------------------*/