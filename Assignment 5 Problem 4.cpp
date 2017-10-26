#include <iostream>
#include <algorithm>

using namespace std;

int floorNumber, numPeople = 0;
short a, t, n;
void displayBin()
{
	unsigned short x = 1 << 15, t;
	cout << "AX = ";
	for (int i = 1; i <= 16; i++)
	{
		t = n &x;
		if (t == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
		if (i % 4 == 0)
		{
			cout << " ";
		}
		n = n << 1;
	}
	cout << endl;
}
void getFloors()
{
	floorNumber = 2 + (rand() % 16);	//Gets random floors from 2-16
}
void printOutput()
{
	cout << "Elevator will stop at floors no. ";
}
void printFloor()
{
	cout << floorNumber << " ";
}
int main()
{
	_asm
	{
		
		mov n, 0x0001
		call displayBin
		mov ax, 0x0001
		mov a, 0000000000000001b
		call printOutput
	Loop1:
		cmp numPeople, 10
		Je Done
		and a, ax
		call getFloors
		call printFloor
		cmp floorNumber, 2
		Je Floor2
		Jne NotFloor2
	Floor2:
		sal a, 1
		inc numPeople
		Jmp Loop1
	NotFloor2:

	Done:
	}
	cout << endl;

	system("pause");
	return 0;
}