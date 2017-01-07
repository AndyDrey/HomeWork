#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
bool IfFunc(const T& elem){
	if (elem > 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
size_t count_if(T* arr, size_t length, bool(*p)(const T& elem)){
	size_t counter = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (p(arr[i]) == true){
			counter++;
		}
	}
	return counter;
}

template<typename T>
bool is_sorted(T* arr, size_t length){
	for (size_t i = 0; i < length-2; i++)
	{
		if (arr[i] >= arr[i+1])
		{
			return false;
		}
	}
	return true;
}

int main(){
	const int size = 10;
	int array[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double arrayD[size] = { 4.4, 1.1, 2.2, 3.3, 5.5, 6.6, 7.7, 10.1, 8.8, 9.9 };
	char arrayC[size] = { "abcdefghi" };
	assert(is_sorted(array, size) == is_sorted(arrayC, size));
	assert(is_sorted(arrayD, size) != true);
	assert(count_if(array, size, IfFunc) < count_if(arrayD, size, IfFunc));
	cout << is_sorted(array, size) << endl;
	cout << is_sorted(arrayD, size) << endl;
	cout << is_sorted(arrayC, size) << endl;
	cout << count_if(array, size, IfFunc) << endl;
	cout << count_if(arrayD, size, IfFunc) << endl;
	cout << count_if(arrayC, size, IfFunc) << endl;
	return 0;
}