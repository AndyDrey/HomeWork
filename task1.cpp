#include <iostream>
#include <assert.h>

using namespace std;

template<typename T, int sizeV>
class Vector{
private:
	T *m_data;
	int m_size;
	int m_amount = 0;
public:
	Vector(): m_size(sizeV){
		m_data = new T[m_size];
	};
	Vector(const Vector &obj){
		m_data = new T[obj.m_size];
		m_size = obj.m_size;
		m_amount = obj.m_amount;
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = obj.m_data[i];
		}
	};
	~Vector(){
		delete[] m_data;
	};
	void push_back(const T& elem){
		m_data[m_amount] = elem;
		++m_amount;
	}
	size_t size() const{
		return m_amount;
	}
	size_t capacity() const{
		return m_size;
	}
	T& operator[] (size_t pos){
		return m_data[pos];
	}
	const T& operator[](size_t pos) const{
		return m_data[pos];
	}
	void insert(size_t pos, const T& value){
		if (pos == m_amount)
		{
			m_data[pos] = value;
			m_amount++;
		}
		else
		{
			for (size_t i = m_amount-1; i > pos; i--)
			{
				m_data[i] = m_data[i - 1];
			}
			m_data[pos] = value;
			m_amount++;
		}
	}
	void erase(size_t pos){
		if (pos == m_amount-1)
		{
			m_data[pos] = 0;
			m_amount--;
		}
		else
		{
			for (size_t i = pos; i < m_amount - 1; i++)
			{
				m_data[i] = m_data[i + 1];
			}
			m_amount--;
		}
	}
	T& front(){
		return *m_data;
	}
	T& back(){
		return *(m_data + m_amount - 1);
	}
	Vector& operator=(const Vector& rhs)
	{
		m_data = new T[rhs.m_size];
		m_size = rhs.m_size;
		m_amount = rhs.m_amount;
		for (size_t i = 0; i < rhs.m_size; i++)
		{
			m_data[i] = rhs.m_data[i];
		}
		return *this;
	}
	template<typename T, int l, int r>
	friend bool operator== (const Vector<T, l>& lhs, const Vector<T, r>& rhs);
	template<typename T, int l, int r>
	friend bool operator!= (const Vector<T, l>& lhs, const Vector<T, r>& rhs);
	template<typename T, int l, int r>
	friend bool operator> (const Vector<T, l>& lhs, const Vector<T, r>& rhs);
	template<typename T, int l, int r>
	friend bool operator< (const Vector<T, l>& lhs, const Vector<T, r>& rhs);
	template<typename T, int l, int r>
	friend bool operator>=(const Vector<T, l>& lhs, const Vector<T, r>& rhs);
	template<typename T, int l, int r>
	friend bool operator<=(const Vector<T, l>& lhs, const Vector<T, r>& rhs);
};

template<typename T, int l, int r>
bool operator== (const Vector<T, l>& lhs, const Vector<T, r>& rhs){
	if (lhs.m_amount != rhs.m_amount)
	{
		return false;
	}
	else if (lhs.m_size != rhs.m_size)
	{
		return false;
	}
	for (int i = 0; i < lhs.m_amount; i++)
	{
		if (lhs.m_data[i] != rhs.m_data[i])
		{
			return false;
		}
	}
	return true;
}
template<typename T, int l, int r>
bool operator!= (const Vector<T, l>& lhs, const Vector<T, r>& rhs){
	return !(lhs == rhs);
}
template<typename T, int l, int r>
bool operator> (const Vector<T, l>& lhs, const Vector<T, r>& rhs){
	if (lhs.m_amount > rhs.m_amount)
	{
		return true;
	}
	else if (lhs.m_size > rhs.m_size)
	{
		return true;
	}
	else if (lhs.m_amount < rhs.m_amount)
	{
		return false;
	}
	else if (lhs.m_size < rhs.m_size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lhs.m_amount; i++)
		{
			if (lhs.m_data[i] < rhs.m_data[i])
			{
				return false;
			}
		}
	}
	return true;
}
template<typename T, int l, int r>
bool operator< (const Vector<T, l>& lhs, const Vector<T, r>& rhs){
	if (lhs.m_amount < rhs.m_amount)
	{
		return true;
	}
	else if (lhs.m_size < rhs.m_size)
	{
		return true;
	}
	else if (lhs.m_amount > rhs.m_amount)
	{
		return false;
	}
	else if (lhs.m_size > rhs.m_size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lhs.m_amount; i++)
		{
			if (lhs.m_data[i] > rhs.m_data[i])
			{
				return false;
			}
		}
	}
	return true;
}
template<typename T, int l, int r>
bool operator>=(const Vector<T, l>& lhs, const Vector<T, r>& rhs){
	return (lhs == rhs || lhs > rhs);
}
template<typename T, int l, int r>
bool operator<=(const Vector<T, l>& lhs, const Vector<T, r>& rhs){
	return (lhs == rhs || lhs < rhs);
}

int main(){
	Vector<int, 5> v1;
	Vector<int, 5> v5;
	Vector<int, 5> v2;
	Vector<int, 6> v3;
	Vector<int, 6> v4;
	for (size_t i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i);
		v3.push_back(i);
		v4.push_back(i+1);
	}
	v5 = v1;
	assert(v1 == v2);// amount, capacity and values must be equal to get true(my own overloading)
	assert(v1 < v3);
	assert(v4 > v3);
	assert(v1 <= v3);
	assert(v4 >= v3);
	assert(v1[0] == v2[0]);
	assert(v1[0] != v4[0]);
	assert(v1.size() == v2.size());
	assert(v1.capacity() != v3.capacity());
	cout << "====================================================" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "v1[" << i << "] = " << v1[i] << " ";
		cout << "v2[" << i << "] = " << v2[i] << " ";
		cout << "v3[" << i << "] = " << v3[i] << " ";
		cout << "v4[" << i << "] = " << v4[i] << " ";
		cout << "v5[" << i << "] = " << v5[i] << endl;
	}
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[" << i << "] = " << v1[i] << " ";
		cout << "v5[" << i << "] = " << v5[i] << endl;
	}
	cout << endl << "FONT AND BACK v1 " << v1.front() << " " << v1.back() << endl;
	v1.insert(5, 10);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[" << i << "] = " << v1[i] << " ";
		cout << "v5[" << i << "] = " << v5[i] << endl;
	}
	cout << endl << "FONT AND BACK v1 " << v1.front() << " " << v1.back() << endl;
	v1.erase(1);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << "v1[" << i << "] = " << v1[i] << " ";
		cout << "v5[" << i << "] = " << v5[i] << endl;
	}
	cout << endl << "FONT AND BACK v1 " << v1.front() << " " << v1.back() << endl;
	return 0;
}