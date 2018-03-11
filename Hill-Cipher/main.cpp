// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "encrypt.h"
#include <iostream>

using namespace std;

enum options { keychoice = 1, encrypt, decrypt, exitprogram };

int main()
{
	int choice;
	bool programRun = true;

	while (programRun)
	{
		cout << "************ Hill-Dixon Tool ************\n";
		cout << endl;
		cout << " 1 - Key Select\n";
		cout << " 2 - Encrypt\n";
		cout << " 3 - Decrypt\n";
		cout << " 4 - Exit\n";
		cout << endl;
		cout << " Enter your choice and press return: ";

		cin >> choice;

		cout << endl;

		switch (choice)
		{
		case keychoice:
			{
			const int choice1[][3] = {
				{6, 1, 1},
				{4, -2, 5},
				{2, 8, 7}
			};
			
			const int choice2[][3] = {
				{6, 24, 1},
				{13, 16, 10},
				{20, 17, 15}
			};

			int output[3][1] = {{0}, {0}, {0}};

			invert(choice1, output);

			break;
			}

		case encrypt:
			{

			break;
			}

		case decrypt:
			{

			break;
			}

		case exitprogram: 
			cout << " End of Program.\n";
			programRun = false;

			break;

		default: 
			cout << " Not a Valid Choice. Choose again. \n";
			cin >> choice;
			cout << endl;

			break;
		}
	}
    return 0;
}

