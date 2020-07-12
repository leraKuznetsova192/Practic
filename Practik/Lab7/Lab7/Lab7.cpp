#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#define N 5
using namespace std;


int read_mat(int a[][N])
{
	printf("Введите элементы матрицы : \n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
}


int read_mat_file(int a[][N])
{
	ifstream f("111.txt");
	printf("Файл открыт\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			f >> a[i][j];
	}
	f.close();
}

int* vvod_X(int a[][N], int x[N], void (*pfunc) (int mas[][N]))
{
	int q, p, t, s;
	pfunc(a);

	for (int i = 0; i < N; i++)
	{
		q = 0; p = 0; t = 0; s = 0;
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] > 0)
			{
				q = q + a[i][j];
				p = p + 1;
			}
			else
			{
				t = t + a[i][j];
				s = s + 1;
			}
		}
		if (p == 5)
			x[i] = q;
		else
		{
			if (s == 5)
				x[i] = t;
			else
				x[i] = 0;
		}
	}
	return x;
}

void vivodAX(int a[N][N], int x[N], int i, int j)
{
	printf("Матрица a:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("Массив x:\n");
	for (i = 0; i < N; i++)
		printf("%d ", x[i]);
}

void vivodY(int y, int x[N],int i)
{
	int t; i = 0;
	while (x[i]!=0)
	{
			t = i+1;
			i = i + 1;
	}
	if (t > 0)
	{
		for (i = t; i < N; i++)
			y = y + x[i];
	}
	else printf("\n Невозможно посчитать Y");
	printf("\n Y=%d", y);
	ofstream f("111.txt");
	f << "Массив x:\n";
	for (i = 0; i < N; i++)
	{
		f << x[i] << ' ';
	}
	f << "\n Y:" << y;
	f.close();

}


void programma()
{
	int c, i = 0, j = 0, a[N][N], x[N] = { 0,0,0,0,0 }, y = 0;
	setlocale(LC_CTYPE, "");
	void (*PointX)(int a[][N]);

	printf("Ввод матрицы:\n 1- с клавиатуры\n 2-чтение с файла\n");
	cin >> c;
	if (c == 1)
	{
		PointX = &read_mat;
		vivodAX(a, x, i, j);
		vivodY(y, x,i);
	}
	else
	{
		ifstream f("111.txt");
		if (f.is_open())
		{
			PointX = &read_mat_file;
			vivodAX(a, x, i, j);
			vivodY(y, x,i);
		}
		else
		{
			printf("Файл не открыт\n");
			f.close();
		}
	}
}

int main(void)
{
	programma();
}