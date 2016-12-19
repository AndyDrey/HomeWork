#include <iostream>
using namespace std;

void cat(char *p, char c1[], char c2[], int dlnew, int dl1, int dl2){
	for (int i = 0; i < dl1; i++)
	{
		p[i] = c1[i];
	}
	for (int i = dl1, j = 0; i < dlnew && j < dl2; i++, j++)
	{
		p[i] = c2[j];
	}
	p[dlnew] = 0;
}
int main(){
	char c1[80];
	char c2[80];
	gets_s(c1);
	gets_s	(c2);
	int dl = strlen(c1) + strlen(c2);
	char*p = new char[dl + 1];
	cat(p, c1, c2, dl, strlen(c1), strlen(c2));
	cout << p << endl;
	delete[]p;
	return 0;
}