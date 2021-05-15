#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int n = 3;
int row = n, column = n;

void fill_array_3x3(int** array)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = rand() % 9;
		}
	}
}


void print_array(int** array)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
}

int** flip_array_3x3(int** array)
{
	// trapsose
	for (int r = 0; r < 3; r++) {
		for (int c = r; c < 3; c++) {
			swap(array[r][c], array[c][r]);
		}
	}
	//reverse elements on row order
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3 / 2; c++) {
			swap(array[r][c], array[r][3 - c - 1]);
		}
	}
	return array;
}

int** flip_array_6x6(int** array1, int** array2)
{
	int local_i;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 6; ++j)
			array2[i][j] = array1[i][j];

	for (int i = 3; i < 6; i++)
	{
		if (i == 3)
			local_i = i - 1;
		if (i == 4)
			local_i = i - 3;
		if (i == 5)
			local_i = 0;
		for (int j = 0; j < 6; j++)
		{
			array2[i][j] = array1[local_i][5 - j];
		}
	}

	return array2;
}

int main()
{
	srand(time(NULL));
	setlocale(0, "");

	int** array3 = new int* [n];
	int** array6 = new int* [n];
	int** array9 = new int* [6];


	for (int i = 0; i < row; ++i)
		array3[i] = new int[n];

	for (int i = 0; i < 3; ++i)
		array6[i] = new int[6];

	for (int i = 0; i < 6; ++i)
		array9[i] = new int[6];

	fill_array_3x3(array3);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array6[i][j] = array3[i][j];
		}
	}

	flip_array_3x3(array3);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 3; j <= 5; ++j)
		{
			array6[i][j] = array3[i][j - 3];
		}
	}

	flip_array_6x6(array6, array9);

	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j)
			cout << array9[i][j] << " ";
		cout << endl;
	}
	delete[] array3;
	delete[] array6;
	delete[] array9;
}