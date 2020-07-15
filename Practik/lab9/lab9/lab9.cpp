#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;





void vvod(int** a, int n)
{
	int i, j;
	cout << "Введите элементы массива:  ";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

int maxA(int** a, int k, int n)
{
	int max = a[0][k]; int i = 0;
	while (i < n - 1)
	{
		if (max < a[i + 1][k])
			max = a[i + 1][k];
		i = i + 1;
	}
	return max;
}



int** programm(int** a, int n)
{
	int i, j,l,k,b,maxX; int p;
	 b = 0; k = n-1;
	while (k != 0)
	{
		j = 0;
		while (j < n - 1)
		{
			maxX = maxA(a, j, n);
			if (maxX < maxA(a, j + 1, n))
			{
				l = j;
				for (i = 0; i < n; i++)
				{
					p = a[i][l];
					a[i][l] = a[i][l + 1];
					a[i][l + 1] = p;
				}
			}
			b = b + 1;
			j = j + 1;
		}
		k = k - 1;
	}
		return a;
}


void vivod(int** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
			if (j == n-1) 
			{ 
				cout << "\n";
			}
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	int n, i;
	cout << "Введите число n= ";
	cin >> n;
	int** a = new int* [n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	vvod(a,n);
	cout << "Исходная матрица: \n";
	vivod(a,n);
	programm(a, n);
	cout << "Преобразованная матрица: \n";
	vivod(a, n);
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	system("pause");
}