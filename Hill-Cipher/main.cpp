// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "encrypt.h"
#include <iostream>

using namespace std;

enum options { encrypt = 1, decrypt, exitprogram };

int main()
{
	int choice;
	bool programRun = true;

	while (programRun)
	{
		cout << "************Hill-Dixon Tool************\n";
		cout << endl;
		cout << " 1 - Encrypt\n";
		cout << " 2 - Decrypt\n";
		cout << " 3 - Exit\n";
		cout << endl;
		cout << " Enter your choice and press return: ";

		cin >> choice;

		cout << endl;

		switch (choice)
		{
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

