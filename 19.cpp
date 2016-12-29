#include <iostream>

using namespace std;

int Multiply(const int & a){
	return a * 3;
}

bool Check(const int& a){
	if ((a % 2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Add(const int& a, const int& b){
	return a + b;
}

int* Map(int* p, const int size, int(*pFunc)(const int& a)){
	for (size_t i = 0; i < size; i++)
	{
		p[i] = pFunc(p[i]);
	}
	return p;
}

int* Filter(int* p, const int size, bool(*pFunc)(const int& a), int &filteredArraySize){
	int newSize = 0;
	for (int i = 0; i < size; i++)
	if (pFunc(p[i]))
	{
		newSize++;
	}
	int* newArr = new int[newSize];
	filteredArraySize = newSize;
	for (int i = 0, j = 0; i < size, j < newSize; i++)
	if (pFunc(p[i]))
	{
		newArr[j] = p[i];
		j++;
	}
	return newArr;
}

int Reduce(int* p, const int size, int(*pFunc)(const int& a, const int& b)){
	for (size_t i = 1; i < size; i++)
	{
		p[0] = pFunc(p[0], p[i]);
	}
	return p[0];
}

int main(){
	const int size = 10;
	int filteredArraySize = 0;
	int array[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//pointer to Multiply func
	int (*pMultiply)(const int & a);
	pMultiply = Multiply;
	//pointer to Check func
	bool (*pCheck)(const int& a);
	pCheck = Check;
	//pointer to Add func
	int (*pAdd)(const int& a, const int& b);
	pAdd = Add;
	// 1st array appear
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << "=====================================================\n";
	Map(array, size, pMultiply);
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	
	cout << endl << "=====================================================\n";
	int* newMass = Filter(array, size, pCheck, filteredArraySize);
	for (size_t i = 0; i < filteredArraySize ; i++)
	{
		cout << newMass[i] << " ";
	}

	cout << endl << "=====================================================\n";
	cout << Reduce(array, size, pAdd);
	return 0;
}