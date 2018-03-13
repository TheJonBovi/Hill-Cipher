#pragma once

#include "stdafx.h"
#include "encrypt.h"

enum textType { plain, cipher};

void selectKey(int key[3][3]);

void multiply(const int key[3][3], const int plaintext[3][1], int result[3][1]);

int minor(const int key[3][3], const int row, const int column);

int determinant(const int key[3][3]);

void invert(const int in[][3], int out[][3]);

int gcdExtended(const int a, const int b, int *x, int *y);

void getInput(int text[3][1], const textType format);

void printMatrix(const int matrix[][3]);

void printText(const int text[3][1], const textType format);
