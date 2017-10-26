#include <iostream>

using namespace std;

char choice, cont, doneAnswer;
int numCorrect = 0, numWrong = 0, answer, checkAnswer;
int randomNum1, randomNum2;

void printMenu()
{
	cout << "------------Practice Addition & Subtraction----------------" << endl;
	cout << "a.  Practice Addition" << endl;
	cout << "b.  Practice Subtraction" << endl;
}
void getInput()
{
	cout << "\tEnter your choice (a/b): ";
	cin >> choice;
}
void addition()
{
	randomNum1 = rand() % 100;
	randomNum2 = rand() % 100;
	cout << randomNum1 << " + " << randomNum2 << " = ? ";
	cin >> answer;
}
void subtraction()
{
	randomNum1 = rand() % 100;
	randomNum2 = rand() % 100;
	cout << randomNum1 << " - " << randomNum2 << " = ? ";
	cin >> answer;
}
void printCorrect()
{
	cout << "\t\t\tCORRECT" << endl;
}
void printWrong()
{
	cout << "\t\t\tWRONG" << endl;
}
void printResults()
{
	cout << "\tNo. of CORRECT answers = " << numCorrect << endl;
	cout << "\tNo. of WRONG answers = " << numWrong << endl;
}
void askCont()
{
	cout << "\t\t\tContinue (y/n)? ";
	cin >> cont;
}
void askDone()
{
	cout << "Are you done (y/n)? ";
	cin >> doneAnswer;
}
void printDone()
{
	cout << "\t\tHave a nice day" << endl;
}
int main()
{
	_asm
	{
		call printMenu
	doWhile:
		call getInput
		cmp choice, 'a'
		Je Addition
		cmp choice, 'b'
		Je Subtraction
	Addition:
		cmp choice, 'a'
		Jne Subtraction
		call addition
		mov eax, randomNum1
		add eax, randomNum2
		cmp answer, eax
		Je Correct
		Jne Wrong
	Subtraction:
		call subtraction
		mov ebx, randomNum1
		sub ebx, randomNum2
		cmp answer, ebx
		Je Correct
		Jne Wrong
	Correct:
		call printCorrect
		inc numCorrect
		Jmp Cont
	Wrong:
		call printWrong
		inc numWrong
		Jmp Cont
	Cont:
		call askCont
		cmp cont, 'y'
		Je Addition
		cmp cont, 'n'
		call printResults
		mov numWrong, 0
		mov numCorrect, 0
		call askDone
		cmp doneAnswer, 'y'
		Je Done
		cmp doneAnswer, 'n'
		Je doWhile
	Done:
		call printDone
	}


	system("pause");
	return 0;
}
/*--------------------------Output--------------------------
------------Practice Addition & Subtraction----------------
a.  Practice Addition
b.  Practice Subtraction
	Enter your choice (a/b): a
		41 + 67 = ? 108
			CORRECT
			Continue (y/n)? y
		34 + 0 = ? 32
			WRONG
			Continue (y/n)? n
		No. of CORRECT answers = 1
		No. of WRONG answers = 1
	Are you done (y/n)? n
	Enter your choice (a/b): b
		69 - 24 = ? 50
			WRONG
			Continue (y/n)? y
		78 - 58 = ? 33
			WRONG
			Continue (y/n)? n
		No. of CORRECT answers = 0
		No. of WRONG answers = 2
	Are you done (y/n)? y
		Have a nice day
Press any key to continue . . .
-------------------------------------------------------------*/