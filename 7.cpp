#include <iostream>
using namespace std;

void cat(char *p, char c1[], char c2[], int dlnew){
	for (int i = 0; i < strlen(c1); i++)
	{
		p[i] = c1[i];
	}
	for (int i = strlen(c1), j = 0; i < dlnew && j < strlen(c2); i++, j++)
	{
		p[i] = c2[j];
	}
	p[dlnew] = 0;
}
int main(){
	char c1[80] = {};
	char c2[80] = {};
	gets_s(c1);
	gets_s(c2);
	int dl = strlen(c1) + strlen(c2);
	char*p = new char[dl + 1];
	cat(p, c1, c2, dl);
	cout << p << endl;
	delete[]p;
	return 0;
}