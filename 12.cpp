#include <iostream>
using namespace std;

void SwapAndShow(int *p)
{
	for (int i = 0; i < 12; i += 2)
	{
		swap(p[i], p[i + 1]);
	}
	for (int i = 0; i < 12; i++)
	{
		cout << p[i] << " ";
	}
}
int main() {

	int *p;
	p = new int[12];
	for (int i = 0; i < 12; i++)
	{
		cin >> p[i];
	}
	SwapAndShow(p);
	
	delete[] p;

	return 0;
}