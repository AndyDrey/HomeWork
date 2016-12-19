#include <iostream>

using namespace std;

void Shifr(char *c, char *s){
	for (int i = 0; i < strlen(c); i++)
	{
		cout << *((((strchr(s, c[i]) - s) + 5) % 16) +s);
	}
}

int main(){
	char c[20];
	char shifr[17] = "abcdefgh123456-0";
	cin >> c;
	Shifr(c, shifr);
	return 0;
}