#include <iostream>
using namespace std;
int matrixDeter(int a[3][3]){
	return a[0][0] * a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1] - a[0][2]*a[1][1]*a[2][0] - a[0][0]*a[1][2]*a[2][1] - a[0][1]*a[1][0]*a[2][2];
}
int main(){
	int matrix[3][3];
	//заполнение 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++){
			cin >> matrix[i][j];
		}
	}
	cout << matrixDeter(matrix);
	return 0;
}