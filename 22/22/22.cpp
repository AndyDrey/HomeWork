#include <iostream>

using namespace std;

class String
{
	char* m_arr = nullptr;
	size_t m_size;
	char* m_copy = nullptr;
	int m_counter = 1;
	int * m_ptrcounter = &m_counter;
public:
	String(char * str, size_t size) : m_size(size), m_arr(new char[size])
	{
		for (size_t i = 0; i < size; i++)
		{
			m_arr[i] = str[i];
		}
	}
	String(const String & object)
	{
		m_arr = object.m_arr;
		m_ptrcounter = object.m_ptrcounter;
		(*m_ptrcounter)++;
	}
	void Change()
	{
		m_copy = new char[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			m_copy[i] = m_arr[i];
		}
	}
	void Show(){
		cout << m_arr;
	}
	void GetCount(){
		cout << *m_ptrcounter;
	}
};



int main(){
	char example[] = { "Hello" };
	char example2[] = { "HelloWorld" };
	String str(example, sizeof(example));
	String str2 = str;
	String str3(example2, sizeof(example2));
	str.Show();
	cout << endl;
	str.GetCount();
	cout << endl;
	str2.Show();
	cout << endl;
	str2.GetCount();
	cout << endl;
	str3.Show();
	cout << endl;
	str3.GetCount();
	cout << endl;
	return 0;
}