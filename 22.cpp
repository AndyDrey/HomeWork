#include <iostream>
#include <cassert>
using namespace std;

class String
{
	char* m_buffer;
	size_t* m_counter;
public:
	String(const char* str) : m_buffer(new char[strlen(str) + 1]), m_counter(new size_t(1))
	{
		strcpy(m_buffer, str);
	}

	String(const String & object) : m_buffer(object.m_buffer), m_counter(object.m_counter)
	{
		(*m_counter)++;
	}

	~String(){
		(*m_counter)--;
		if ((*m_counter) == 0)
		{
			delete[] m_buffer;
			delete m_counter;
		}
		m_buffer = nullptr;
	}
	void ChangeElement(const char value, size_t index)
	{
		if (count()>1)
		{
			String tmp(m_buffer);
			std::swap(*this, tmp);
		}
		m_buffer[index] = value;
	}
	void swap(String& other)
	{
		std::swap(m_buffer, other.m_buffer);
		std::swap(m_counter, other.m_counter);
	}

	String& operator = (const String& rhs)
	{
		if (&rhs != this)
		{
			String tmp(rhs);
			swap(tmp);
		}
		return *this;
	}

	String& operator = (const char* value)
	{
		String(value).swap(*this);
		return *this;
	}

	const char& operator[](size_t index)
	{
		return m_buffer[index];
	}

	size_t count() const
	{
		return *m_counter;
	}

	const char *GetString()const
	{
		return m_buffer;
	}
};



int main(){
	char example[] = { "Hello" };
	char example2[] = { "HelloWorld" };
	String str(example);
	String str2 = str;
	String str3(example2);
	assert(str.count() == str2.count());
	assert(str.count() == 2);
	assert(strcmp(str.GetString(), "Hello") == 0);
	assert(strcmp(str2.GetString(), "Hello") == 0);
	str2.ChangeElement('x', 0);
	assert(strcmp(str2.GetString(), "xello") == 0);
	assert(str.count() == 1);
	assert(str2.count() == 1);
	String s("abc");
	assert(s.count() == 1);
	{
		String s2 = s;
		assert(s.count() == 2);
		assert(s2.count() == 2);
	}
	assert(s.count() == 1);
	cout << "PASSED!!!" << endl;
	return 0;
}