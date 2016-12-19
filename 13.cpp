#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
void RandAndShow(int *p){
	for (int i = 0; i < 50; i++){
		int x = rand() % 50;
		int tmp = p[i];
		p[i] = p[x];
		p[x] = tmp;
	}
	for (int i = 0; i < 50; i++){
		cout << p[i] << " ";
	}
}

int main() {
	srand(time(0));
	int array[50];
	for (int i = 0, j = 1; j < 100; i++, j += 2){
		array[i] = j;
	}
	for (int i = 0; i < 50; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	int *p = array;
	RandAndShow(p);
	return 0;
}