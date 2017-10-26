//Royce Nguyen
//CPSC 240
//09/14/2017
//Project 3 Problem 2
//Status: DONE

#include <iostream>

using namespace std;

int score, average, counter = 0;
void displayMenu()
{
	cout << "Let's compute your score's average: " << endl;
}
void askScore()
{
	cout << "Enter your score (-1) to stop: ";
	cin >> score;
	if (score != -1)
		counter++;
}
void displayAverage()
{
	cout << "\tYour average is " << average << endl;
}
int main()
{
	_asm
	{
		call displayMenu
		mov ebx, score
	doWhile:
		call askScore
		cmp score, -1
		Je done
		add score, ebx
		mov ebx, score
		Jmp doWhile
	done:
		mov eax, ebx
		cdq
		mov ecx, counter
		idiv ecx
		mov average, eax
		call displayAverage

	}

	system("pause");
	return 0;
}

/*--------------------------------------Output-------------------------------------------
Let's compute your score's average:
Enter your score(-1) to stop : 70
Enter your score(-1) to stop : 88
Enter your score(-1) to stop : 90
Enter your score(-1) to stop : 77
Enter your score(-1) to stop : -1
	Your average is 81
Press any key to continue . . .
---------------------------------------------------------------------------------------*/