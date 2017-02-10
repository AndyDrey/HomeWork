#include <iostream>

using namespace std;
template <typename T>
T Multiply(const T & a){
	return a * 3;
}

template <typename T>
bool Check(const T& a){
	if (a > 25)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
T Add(const T& a, const T& b){
	return a + b;
}

template <typename T>
T* Map(T* p, const int size, T(*pFunc)(const T& a)){
	for (size_t i = 0; i < size; i++)
	{
		p[i] = pFunc(p[i]);
	}
	return p;
}

template <typename T>
T* Filter(T* p, const int size, bool(*pFunc)(const T& a), int &filteredArraySize){
	filteredArraySize = 0;
	for (int i = 0; i < size; i++)
	if (pFunc(p[i]))
	{
		filteredArraySize++;
	}
	T* newArr = new T[filteredArraySize];
	for (int i = 0, j = 0; i < size && j < filteredArraySize; i++)
	if (pFunc(p[i]))
	{
		newArr[j] = p[i];
		j++;
	}
	return newArr;
}

template <typename T>
T Reduce(T* p, const int size, T(*pFunc)(const T& a, const T& b)){
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
	double arrayD[size] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1 };
	char arrayC[size] = { "abcdefghi" };
	cout << endl << "==========================MAP FUNCTIONS===========================\n";
	Map(array, size, Multiply);
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << "=====================================================\n";
	Map(arrayD, size, Multiply);
	for (size_t i = 0; i < size; i++)
	{
		cout << arrayD[i] << " ";
	}
	cout << endl << "=====================================================\n";
	Map(arrayC, size, Multiply);
	for (size_t i = 0; i < size; i++)
	{
		cout << arrayC[i] << " ";
	}
	cout << endl << "========================CHECK FUNCTIONS=============================\n";
	int* newMass = Filter(array, size, Check, filteredArraySize);
	for (size_t i = 0; i < filteredArraySize; i++)
	{
		cout << newMass[i] << " ";
	}
	cout << endl << "=====================================================\n";
	double* newMassD = Filter(arrayD, size, Check, filteredArraySize);
	for (size_t i = 0; i < filteredArraySize; i++)
	{
		cout << newMassD[i] << " ";
	}
	cout << endl << "=====================================================\n";
	char* newMassC = Filter(arrayC, size, Check, filteredArraySize);
	for (size_t i = 0; i < filteredArraySize; i++)
	{
		cout << newMassC[i] << " ";
	}
	cout << endl << "=============================REDUCE FUNCTIONS========================\n";
	cout << Reduce(array, size, Add); 
	cout << endl << "=====================================================\n";
	cout << Reduce(arrayD, size, Add);
	cout << endl << "=====================================================\n";
	cout << Reduce(arrayC, size, Add);

	delete[] newMass;
	delete[] newMassD;
	delete[] newMassC;

	return 0;
}