#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High, const int i, const int j);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);
void Search(int** a, const int n, const int max, const int i, const int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -14;
	int High = 27;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];
	Create(a, n, Low, High,0,0);
	PrintRows(a, n, 0);
	Search(a, n,0,0,0);
	PrintRows(a, n, 0);
	for (int i = 0; i < n; i++)delete[] a[i];
	delete[] a;
	return 0;
}void Create(int** a, const int n, const int Low, const int High, const int i, const int j)
{
	if(i<n)
	{
		if(j<n){ a[i][j] = Low + rand() % (High - Low + 1); Create(a, n, Low, High, i, j+1);}
		Create(a, n, Low, High, i+1, j );
	}
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)PrintRow(a, rowNo, N, colNo + 1);
	else cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{ 
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)PrintRows(a, N, rowNo + 1);
	else cout << endl;
}
void Search(int** a, const int n, int max, int i, int j)
{
	if (i < n)
	{
		if (j < n) {
			if ((i + 1) % 2 == 0)
			{
				if (a[i][j] > max) { max = a[i][j]; }
			}
			else { max = -20; }
			if (max != -20)
			{
				swap(a[i][i], max);
			}
			Search(a, n, 0, i, j+1);
		}
		Search(a, n, 0, i+1, j);
	}
}