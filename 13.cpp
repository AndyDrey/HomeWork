#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
void RandAndShow(int *p, const int aSize){
	for (int i = 0; i < aSize; i++){
		int x = rand() % aSize;
		int tmp = p[i];
		p[i] = p[x];
		p[x] = tmp;
	}
	for (int i = 0; i < aSize; i++){
		cout << p[i] << " ";
	}
}

int main() {
	srand(time(0));
	const int aSize = 50;
	int array[aSize];
	for (int i = 0, j = 1; j < 100; i++, j += 2){
		array[i] = j;
	}
	for (int i = 0; i < aSize; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	int *p = array;
	RandAndShow(p, aSize);
	return 0;
}