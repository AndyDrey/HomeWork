#include <iostream>
#include <string>
using namespace std;

int main(){
	int count;
	cin >> count;
	int count100 = 0;
	int count200 = 0;
	for (size_t i = 0; i < count; i++)
	{
		int a = 0;
		cin >> a;
		if (a == 100)
		{
			count100++;
		}
		else
		{
			count200++;
		}
	}
	if (count100 != 0 && count100 % 2 != 0)
	{
		cout << "NO";
	}
	else if (count200 % 2 != 0)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
	return 0;
}