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
	auto keySelectedFlag = false;

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
			selectKey(chosenKey);
			keySelectedFlag = true;
			break;

		case encrypt:
		{
			if (keySelectedFlag)
			{
				cout << " Please enter 3-digit plaintext: ";

				int input[3][1];
				// TODO: Check input is character / lowercase
				getInput(input, plain);
				cout << endl;

				int output[3][1];
				multiply(chosenKey, input, output);

				cout << " The ciphertext is: ";
				printText(output, cipher);
				cout << endl;
				cout << endl;
			}
			else
			{
				cout << " Please select a key first!";
				cout << endl << endl;
			}

			system("pause");
			system("CLS");
			break;
		}

		case decrypt:
		{
			if (keySelectedFlag)
			{
				cout << " Please enter 3-digit ciphertext: ";

				int input[3][1];
				// TODO: Check input is character / uppercase
				getInput(input, cipher);
				cout << endl;

				int output[3][1];
				int keyInv[3][3];
				invert(chosenKey, keyInv);
				multiply(keyInv, input, output);

				cout << " The plaintext is: ";
				printText(output, plain);
				cout << endl;
				cout << endl;
			}
			else
			{
				cout << " Please select a key first!";
				cout << endl << endl;
			}

			system("pause");
			system("CLS");
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

