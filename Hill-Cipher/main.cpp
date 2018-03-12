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
	int chosenKey[3][3];
	auto programRun = true;

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
			cout << " Please select desired key: ";

			const int choice1[][3] = {
				{6, 24, 1},
				{13, 16, 10},
				{20, 17, 15}
			};

			// TODO: Make different key
			const int choice2[][3] = {
				{6, 24, 1},
				{13, 16, 10},
				{20, 17, 15}
			};

			// TODO: Make different key
			const int choice3[][3] = {
				{6, 24, 1},
				{13, 16, 10},
				{20, 17, 15}
			};

			int keyChoice;
			cin >> keyChoice;

			// Copy key to chosenKey
			for (int i{}; i < 3; i++)
			{
				for (int j{}; j < 3; j++)
				{
					chosenKey[i][j] = choice1[i][j];
				}
			}

				break;
			}

		case encrypt:
			{
			int output[3][1] = {{0}, {0}, {0}};
			int keyInv[3][3];

			for (int i{}; i < 3; i++)
			{
				for (int j{}; j < 3; j++)
				{
					keyInv[i][j] = 0;
				}
			}

			invert(chosenKey, keyInv);

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

