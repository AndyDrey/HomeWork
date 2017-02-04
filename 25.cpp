#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

template<typename T, int N = 16>
class stack
{
private:
	T m_data[N];
	int m_last;
public:
	stack()
		: m_data()
		, m_last(0)
	{

	}

	void push(const T& value)
	{
		m_data[m_last++] = value;
	}

	T pop()
	{
		return m_data[--m_last];
	}
};



template<int N>
class stack<bool, N>
{
private:
	char m_data[N];
	int m_last;
public:
	stack()
		: m_data()
		, m_last(0)
	{
	}

	void push(const bool& value)
	{
		int num_elem = (m_last) / 8;
		int offset_elem = (m_last) % 8;

		m_data[num_elem] ^= (-value ^ m_data[num_elem]) & (1 << (7 - offset_elem));

		m_last++;
	}

	bool pop()
	{
		int num_elem = (--m_last) / 8;
		int offset_elem = (m_last) % 8;
		bool result = (1 & (m_data[num_elem] >> (7 - offset_elem)));
		return result;
	}
};

int main(){
	srand(time(NULL));
	const int stackSize = 32;
	stack<char, stackSize> justStack;
	stack<bool, stackSize/8> specialStack;
	for (size_t i = 0; i < stackSize; ++i)
	{
		bool value = rand() % 2;
		justStack.push(value);
		specialStack.push(value);
	}
	for (size_t i = 0; i < stackSize; ++i)
	{
		bool justStackValue = justStack.pop();
		bool specialStackValue = specialStack.pop();
		cout << justStackValue << " " << specialStackValue << endl;
		assert(justStackValue == specialStackValue);
	}
	return 0;
}