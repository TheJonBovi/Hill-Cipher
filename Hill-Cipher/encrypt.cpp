// encrypt.cpp : Routines for encryption and decryption
// some code snippets from Mr Rhea at https://stackoverflow.com/questions/983999/simple-3x3-matrix-inverse-code-c

#include "stdafx.h"
#include "encrypt.h"
#include <ostream>
#include <iostream>

void multiply(const int key[3][3], const int plaintext[3][1], int result[3][1]) 
{
	//result[0][0] = key[0][0] * plaintext[0][0] + key[0][1] * plaintext[1][0] + key[0][2] * plaintext[2][0];
	//result[1][0] = key[1][0] * plaintext[0][0] + key[1][1] * plaintext[1][0] + key[1][2] * plaintext[2][0];
	//result[2][0] = key[2][0] * plaintext[0][0] + key[2][1] * plaintext[1][0] + key[2][2] * plaintext[2][0];

	for (int y{0}; y < 3; y++)
		for (int x{0}; x < 3; x++)
		{
			result[y][x] = 0;
			for (int i{0}; i < 3; i++)
				result[y][x] += key[y][i] * plaintext[i][x];
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

void invert(const int in[][3], int out[][1])
{
	const auto det = determinant(in);

	const auto invDet = 1 / det;

	for (int y{0}; y < 3; y++)
		for (int x{0}; x < 3; x++)
		{
			// Rule is inverse = 1/det * minor of the TRANSPOSE matrix.
			// Note (y,x) becomes (x,y) INTENTIONALLY here!
			out[y][x] = minor(in, x, y) * invDet;

			/* (y0,x1)  (y1,x0)  (y1,x2)  and (y2,x1)  all need to be negated. */
			if (((x + y) % 2) == 1)
				out[y][x] = -out[y][x];
		}
}

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
