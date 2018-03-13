// encrypt.cpp : Routines for encryption and decryption
// some code snippets from Mr Rhea at https://stackoverflow.com/questions/983999/simple-3x3-matrix-inverse-code-c
// algorithm for extended euclidain gcd from https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

#include "stdafx.h"
#include "encrypt.h"
#include <ostream>
#include <iostream>

using namespace std;

void selectKey(int key[3][3])
{
			const int choice1[][3] = {
				{6, 24, 1},
				{13, 16, 10},
				{20, 17, 15}
			};

			const int choice2[][3] = {
				{3, 10, 20},
				{20, 9, 17},
				{9, 4, 17}
			};

			const int choice3[][3] = {
				{2, 4, 5},
				{9, 2, 1},
				{3, 17, 7}
			};

			cout << "     Key 1" << endl;
			printMatrix(choice1);
			cout << endl;
			cout << "     Key 2" << endl;
			printMatrix(choice2);
			cout << endl;
			cout << "     Key 3" << endl;
			printMatrix(choice3);
			cout << endl;

			cout << " Please select desired key: ";
			int keyChoice;
			cin >> keyChoice;
			cout << endl;

			switch (keyChoice)
			{
			case 1:

				// Copy key to chosenKey
				for (int i{}; i < 3; i++)
				{
					for (int j{}; j < 3; j++)
					{
						key[i][j] = choice1[i][j];
					}
				}

				break;

			case 2:

				// Copy key to chosenKey
				for (int i{}; i < 3; i++)
				{
					for (int j{}; j < 3; j++)
					{
						key[i][j] = choice2[i][j];
					}
				}

				break;

			case 3:
			default:

				// Copy key to chosenKey
				for (int i{}; i < 3; i++)
				{
					for (int j{}; j < 3; j++)
					{
						key[i][j] = choice3[i][j];
					}
				}

				break;
			}

			system("CLS");
			cout << flush;
	
}

void multiply(const int key[3][3], const int plaintext[3][1], int result[3][1]) 
{
	for (int y{}; y < 3; y++)
	{
		result[y][0] = 0;
		for (int i{}; i < 3; i++)
			result[y][0] += key[y][i] * plaintext[i][0];
	}
}

int minor(const int key[3][3], const int row, const int column)
{
	const auto x1 = column == 0 ? 1 : 0;
	const auto x2 = column == 2 ? 1 : 2;
	const auto y1 = row == 0 ? 1 : 0;
	const auto y2 = row == 2 ? 1 : 2;

	const auto ret = key[y1][x1] * key[y2][x2]
				   - key[y1][x2] * key[y2][x1];

	return ret;
}

int determinant(const int key[3][3])
{
	const auto ret = key[0][0] * (minor(key, 0, 0))
				   - key[0][1] * (minor(key, 0, 1))
				   + key[0][2] * (minor(key, 0, 2));
	return ret;
}

void invert(const int in[][3], int out[][3])
{
	const auto det = determinant(in);

	int modInverse, tempY;
	gcdExtended(det, 26, &modInverse, &tempY);
	const auto invDet = (modInverse + 26) % 26;

	for (int y{}; y < 3; y++)
		for (int x{}; x < 3; x++)
		{
			// Rule is inverse = 1/det * minor of the TRANSPOSE matrix.
			out[y][x] = minor(in, x, y) * invDet;

			/* (y0,x1)  (y1,x0)  (y1,x2)  and (y2,x1)  all need to be negated. */
			if (((x + y) % 2) == 1)
				out[y][x] = -out[y][x];

			// Forces elements to be between 0 and 26
			out[y][x] = ((out[y][x] % 26) + 26) % 26;
		}
}

// TODO: Get rid of references to y (not needed)
// TODO: Make void?
int gcdExtended(const int a, const int b, int *x, int *y)
{
	//Base case
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}	

	int x1, y1;
	const auto gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

void getInput(int text[3][1], const textType format)
{
	for (int i{}; i < 3; i++)
	{
		char rawInput;
		cin >> rawInput;

		int currentChar;
		if (format == plain) currentChar = rawInput - 97;
		
		else currentChar = rawInput - 65; 

		text[i][0] = currentChar;
	}
}

void printMatrix(const int matrix[][3])
{
	for (size_t i = 0; i<3; i++)
	{
		cout << " [ ";
		for (size_t j = 0; j < 3; j++)
		{
			if(matrix[i][j] < 10)
			cout << matrix[i][j] << "  ";
			else
			cout << matrix[i][j] << " ";
		}
		cout << "] ";
		cout << std::endl;
	}
}

void printText(const int text[3][1], const textType format)
{
	for (int i{}; i < 3; i++)
	{
		if (format == plain)
			cout << char((text[i][0] % 26) + 97);
		else
			cout << char((text[i][0] % 26) + 65);
	}
}