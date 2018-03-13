#pragma once

#include "stdafx.h"
#include "encrypt.h"

enum textType { plain = 1, cipher};

void multiply(const int key[3][3], const int plaintext[3][1], int result[3][1]);

int minor(const int key[3][3], const int row, const int column);

int determinant(const int key[3][3]);

void invert(const int in[][3], int out[][3]);

void printMatrix(const int a[][3]);

int gcdExtended(int a, int b, int *x, int *y);

void getInput(int text[3][1], const textType format);

void printText(const int text[3][1], const textType format);
