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

			cout << " Please select desired key: ";
			int keyChoice;
			cin >> keyChoice;
			cout << endl;

			switch (keyChoice)
			{
				case 1:
				{

					const int choice1[][3] = {
						{6, 24, 1},
						{13, 16, 10},
						{20, 17, 15}
					};

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

			case 2:
				{
					// TODO: Make different key
					const int choice2[][3] = {
						{6, 24, 1},
						{13, 16, 10},
						{20, 17, 15}
					};

					// Copy key to chosenKey
					for (int i{}; i < 3; i++)
					{
						for (int j{}; j < 3; j++)
						{
							chosenKey[i][j] = choice2[i][j];
						}
					}

					break;
				}

			case 3:
			default:
				{
					// TODO: Make different key
					const int choice3[][3] = {
						{6, 24, 1},
						{13, 16, 10},
						{20, 17, 15}
					};

					// Copy key to chosenKey
					for (int i{}; i < 3; i++)
					{
						for (int j{}; j < 3; j++)
						{
							chosenKey[i][j] = choice3[i][j];
						}
					}

					break;
				}
			}

			system("CLS");
			cout << flush;
			break;

		case encrypt:
			{
			// TODO: Add check to see if key is selected
			cout << " Please enter 3-digit plaintext: ";

			int input[3][1];
			getInput(input, plain);
			cout << endl;

			int output[3][1];
			int keyInv[3][3];

			invert(chosenKey, keyInv);

			multiply(chosenKey, input, output);

			cout << " The ciphertext is: ";
			printText(output, cipher);
			cout << endl;
			cout << endl;

			system("pause");
			system("CLS");

			break;
			}

		case decrypt:
			{
			// TODO: Add check to see if key is selected

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

