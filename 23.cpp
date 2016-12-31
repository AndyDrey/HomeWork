#include <iostream>
#include <map>
#include <assert.h>
#include <string>
using namespace std;

map<char, int> rToAr= { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };

class RomanNumber
{
	char* m_rNumber;
	int m_arNumber;
	int ConvertToArNumber(char* romanNumb){
		int prev = 1;
		int number = 0;
		for (int i = strlen(romanNumb); i >= 0; i--)
		{
			for (auto it = rToAr.begin(); it != rToAr.end(); ++it)
			{
				if (romanNumb[i] == it->first){
					if (it->second >= prev)
					{
						number += it->second;
					}
					else
					{
						number -= it->second;
					}
					prev = it->second;
					break;
				}
			}
		}
		return number;
	}
public:
	RomanNumber(char* romanNumb) : m_rNumber(romanNumb){
		m_arNumber = ConvertToArNumber(romanNumb);
	}

	RomanNumber(const RomanNumber& obj){
		m_rNumber = obj.m_rNumber;
	}

	//OPERATORS OVERLOAD

	explicit operator int() {
		return m_arNumber;
	}

	int operator+ (const RomanNumber& rhs){
		return this->m_arNumber + rhs.m_arNumber;
	}

	int operator- (const RomanNumber& rhs){
		return this->m_arNumber - rhs.m_arNumber;
	}

	int operator* (const RomanNumber& rhs){
		return this->m_arNumber * rhs.m_arNumber;
	}

	int operator/ (const RomanNumber& rhs){
		return this->m_arNumber / rhs.m_arNumber;
	}



	friend int operator+= (RomanNumber& lhs,const RomanNumber& rhs){
		lhs.m_arNumber += rhs.m_arNumber;
		return lhs.m_arNumber;
	}

	friend int operator-= (RomanNumber& lhs, const RomanNumber& rhs){
		lhs.m_arNumber -= rhs.m_arNumber;
		return lhs.m_arNumber;
	}

	friend int operator*= (RomanNumber& lhs, const RomanNumber& rhs){
		lhs.m_arNumber *= rhs.m_arNumber;
		return lhs.m_arNumber;
	}

	friend int operator/= (RomanNumber& lhs, const RomanNumber& rhs){
		lhs.m_arNumber /= rhs.m_arNumber;
		return lhs.m_arNumber;
	}
	
	bool operator== (const RomanNumber& rhs){
		if (this->m_arNumber == rhs.m_arNumber)
		{
			return true;
		}
		else return false;
	}

	bool operator!= (const RomanNumber& rhs){
		return !(this->m_arNumber == rhs.m_arNumber);
	}

	bool operator> (const RomanNumber& rhs){
		if (this->m_arNumber > rhs.m_arNumber)
		{
			return true;
		}
		else return false;
	}

	bool operator>= (const RomanNumber& rhs){
		return this->m_arNumber > rhs.m_arNumber || this->m_arNumber == rhs.m_arNumber;
	}

	bool operator< (const RomanNumber& rhs){
		if (this->m_arNumber < rhs.m_arNumber){
			return true;
		}
		else return false;
	}

	bool operator<= (const RomanNumber& rhs){
		return this->m_arNumber < rhs.m_arNumber || this->m_arNumber == rhs.m_arNumber;
	}

	int operator++ (){
		++this->m_arNumber;
		return	this->m_arNumber;
	}

	int operator++ (int){
		int tmp = this->m_arNumber;
		this->m_arNumber++;
		return tmp;
	}

	int operator-- (){
		--this->m_arNumber;
		return this->m_arNumber;
	}

	int operator-- (int){
		int tmp = this->m_arNumber;
		this->m_arNumber--;
		return tmp;
	}

	friend ostream& operator<< (ostream& os, const RomanNumber& obj){
		os << "Your roman number is: " << obj.m_rNumber << " Your arabic number is: " << obj.m_arNumber;
		return os;
	}

	friend istream& operator>> (istream& is, const RomanNumber& obj){
		cout << " DONT USE OPERATOR \">>\"";
		return is;
	}

	//OPERATORS OVERLOAD TO WORK WITH INT
	friend int operator+ (const int a, const RomanNumber&rhs){
		return a + rhs.m_arNumber;
	}

	friend int operator+ (const RomanNumber&lhs, const int a){
		return lhs.m_arNumber + a;
	}

	friend int operator- (const int a, const RomanNumber&rhs){
		return a - rhs.m_arNumber;
	}

	friend int operator- (const RomanNumber&lhs, int a){
		return lhs.m_arNumber - a;
	}

	friend int operator* (const int a, const RomanNumber&rhs){
		return a * rhs.m_arNumber;
	}

	friend int operator* (const RomanNumber&lhs, const int a){
		return lhs.m_arNumber * a;
	}

	friend int operator/ (const int a, const RomanNumber&rhs){
		return a / rhs.m_arNumber;
	}

	friend int operator/ (const RomanNumber&lhs, const int a){
		return lhs.m_arNumber / a;
	}

	friend int operator+= (int a, const RomanNumber&rhs){
		a += rhs.m_arNumber;
		return a;
	}

	friend int operator+= (RomanNumber&lhs, const int a){
		lhs.m_arNumber += a;
		return lhs.m_arNumber;
	}

	friend int operator-= (int a, const RomanNumber&rhs){
		a -= rhs.m_arNumber;
		return a;
	}

	friend int operator-= (RomanNumber&lhs, const int a){
		lhs.m_arNumber -= a;
		return lhs.m_arNumber;
	}

	friend int operator*= (int a, const RomanNumber&rhs){
		a *= rhs.m_arNumber;
		return a;
	}

	friend int operator*= (RomanNumber&lhs, const int a){
		lhs.m_arNumber *= a;
		return lhs.m_arNumber;
	}

	friend int operator/= (int a, const RomanNumber&rhs){
		a /= rhs.m_arNumber;
		return a;
	}

	friend int operator/= (RomanNumber&lhs, const int a){
		lhs.m_arNumber /= a;
		return lhs.m_arNumber;
	}
	// COMPARSION WITH INTEGERS
	friend bool operator== (const int a, const RomanNumber& rhs){
		if (a == rhs.m_arNumber)
		{
			return true;
		}
		else return false;
	}

	friend bool operator== (const RomanNumber& lhs, const int a){
		if (lhs.m_arNumber == a)
		{
			return true;
		}
		else return false;
	}

	friend bool operator!= (const int a, const RomanNumber& rhs){
		return !(a == rhs.m_arNumber);
	}

	friend bool operator!= (const RomanNumber& lhs, const int a){
		return !(lhs.m_arNumber == a);
	}

	friend bool operator> (const int a, const RomanNumber& rhs){
		if (a > rhs.m_arNumber)
		{
			return true;
		}
		else return false;
	}

	friend bool operator> (const RomanNumber& lhs, const int a){
		if (lhs.m_arNumber > a)
		{
			return true;
		}
		else return false;
	}

	friend bool operator>= (const int a, const RomanNumber& rhs){
		return a > rhs.m_arNumber || a == rhs.m_arNumber;
	}

	friend bool operator>= (const RomanNumber& lhs, const int a){
		return lhs.m_arNumber > a ||lhs.m_arNumber == a;
	}

	friend bool operator< (const int a, const RomanNumber& rhs){
		if (a < rhs.m_arNumber){
			return true;
		}
		else return false;
	}

	friend bool operator< (const RomanNumber& lhs, const int a){
		if (lhs.m_arNumber < a){
			return true;
		}
		else return false;
	}

	friend bool operator<= (const int a, const RomanNumber& rhs){
		return a < rhs.m_arNumber || a == rhs.m_arNumber;
	}

	friend bool operator<= (const RomanNumber& lhs, const int a){
		return lhs.m_arNumber < a || lhs.m_arNumber == a;
	}
};


int main(){
	RomanNumber r1 = RomanNumber("MDIL");
	RomanNumber r2("MCDXLIX");
	cout << r1 << endl;
	cout << int(r1) << endl;
	assert(r1 == 1549);
	assert(r1 + 1 == 1550);
	assert(r1 + r2 >= r2);
	assert(r2 + r2 == r2 * 2);
	assert(r1 >  r2);
	assert(r1 != r2);

	return 0;
}