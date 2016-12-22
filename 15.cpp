#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

	//creating 1st array
	int **Arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		Arr[i] = new int[m];
	}

	//creating 2nd array
	int **newArr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		newArr[i] = new int[n];
	}

	//fullfill
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++){
			cin >> Arr[i][j];
		}
	}

	//90dgr rotation
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			newArr[i][n-j-1] = Arr[j][i];
		}
	}

	//output
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			cout << newArr[i][j] << " ";
		}
		cout << endl;
	}

	// deleting Arrays
	for (int i = 0; i < n; i++)
	{
		delete[] Arr[i];
	}
	for (int i = 0; i < m; i++)
	{
		delete[] newArr[i];
	}

	return 0;
}