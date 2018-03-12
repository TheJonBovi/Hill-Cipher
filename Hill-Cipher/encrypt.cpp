// encrypt.cpp : Routines for encryption and decryption
// some code snippets from Mr Rhea at https://stackoverflow.com/questions/983999/simple-3x3-matrix-inverse-code-c
// algorithm for extended euclidain gcd from https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

#include "stdafx.h"
#include "encrypt.h"
#include <ostream>
#include <iostream>

void multiply(const int key[3][3], const int plaintext[3][1], int result[3][1]) 
{
	//result[0][0] = key[0][0] * plaintext[0][0] + key[0][1] * plaintext[1][0] + key[0][2] * plaintext[2][0];
	//result[1][0] = key[1][0] * plaintext[0][0] + key[1][1] * plaintext[1][0] + key[1][2] * plaintext[2][0];
	//result[2][0] = key[2][0] * plaintext[0][0] + key[2][1] * plaintext[1][0] + key[2][2] * plaintext[2][0];

	for (int y{ 0 }; y < 3; y++)
	{
		result[y][0] = 0;
		for (int i{ 0 }; i < 3; i++)
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

	for (int y{0}; y < 3; y++)
		for (int x{0}; x < 3; x++)
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

// TODO: Clean this up / format nicer
void print(const int a[][3])
{
	for (size_t i = 0; i<3; i++)
	{
		for (size_t j = 0; j<3; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int gcdExtended(int a, int b, int *x, int *y)
{
	// Base Case ( do I really need this?)
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
