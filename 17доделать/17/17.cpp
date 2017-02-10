#include <iostream>

using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b != c)
	{
		cout << "Умножение невозможно";
		return 0;
	}
	int **pA = new int*[a];
	for (size_t i = 0; i < a; i++)
	{
		pA[i] = new int[b];
	}
	int **pB = new int*[c];
	for (size_t i = 0; i < c; i++)
	{
		pB[i] = new int[d];
	}
	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < b; j++)
		{
			cin >> pA[i][j];
		}
	}
	for (size_t i = 0; i < c; i++)
	{
		for (size_t j = 0; j < d; j++)
		{
			cin >> pB[i][j];
		}
	}
	int **pC = new int*[a];
	for (size_t i = 0; i < a; i++)
	{
		pC[i] = new int[d];
	}
	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < d; j++)
		{
		    pC[i][j] = 0;
		}
	}

	//counting
	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < d; j++)
		{
			for (int k = 0; k < b; k++)
			{
				pC[i][j] += pA[i][k] * pB[k][j];
			}
		}
	}

	//output
	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < d; j++)
		{
			cout << pC[i][j] << " ";
		}
		cout << endl;
	}
	
	//deleting
	for (size_t i = 0; i < a; i++)
	{
		delete[]pA[i];
	}
	for (size_t i = 0; i < c; i++)
	{
		delete[]pB[i];
	}
	for (size_t i = 0; i < a; i++)
	{
		delete[]pC[i];
	}
	return 0;
}
