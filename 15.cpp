#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	//�������� ���������� �������
	int **Arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		Arr[i] = new int[m];
	}
	//�������� ������� ���������� �������
	int **newArr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		newArr[i] = new int[n];
	}

	//����������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++){
			cin >> Arr[i][j];
		}
	}
	//������� �� 90 �������� �� ������� �������
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			newArr[i][n-j-1] = Arr[j][i];
		}
	}
	//�����
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			cout << newArr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}