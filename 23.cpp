#include <iostream>
#include <map>
#include <cassert>
#include <string>
using namespace std;


class RomanNumber
{
	string m_roman;
	int m_arabic;
	static int ConvertToArabic(const char* roman){
		static const map<char, int> rToAr = {
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		};
		int prev = 1;
		int number = 0;
		for (int i = strlen(roman); i >= 0; i--)
		{
			auto it = rToAr.find(roman[i]);
			if (it != rToAr.end())
			{
				if (it->second >= prev)
				{
					number += it->second;
				}
				else
				{
					number -= it->second;
				}
				prev = it->second;
			}
		}
		return number;
	}
	static char* ConvertToRoman(int arab) {
		const int arabar[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
		const char* romanar[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
		static char roman[80];
		const int m = sizeof(arabar) / sizeof(int)-1, arabmax = arabar[m];
		const char romanmax = romanar[m][0];
		int i, n;
		if (!arab) {
			*roman = 0;
			return roman;
		}
		i = 0;
		while (arab>arabmax) {
			roman[i++] = romanmax;
			arab -= arabmax;
		}
		n = m;
		while (arab > 0) {
			if (arab >= arabar[n]) {
				roman[i++] = romanar[n][0];
				if (n & 1)
					roman[i++] = romanar[n][1];
				arab -= arabar[n];
			}
			else
				n--;
		}
		roman[i] = 0;
		return roman;
	}
public:
	RomanNumber() : m_roman("NaN"), m_arabic(0){}
	RomanNumber(const char* roman) : m_roman(roman), m_arabic(ConvertToArabic(roman)){}
	RomanNumber(int arabic) : m_roman(ConvertToRoman(arabic)), m_arabic(arabic){}
	RomanNumber(const RomanNumber& obj){
		m_roman = obj.m_roman;
		m_arabic = obj.m_arabic;
	}

	//OPERATORS OVERLOAD
	RomanNumber& operator= (const RomanNumber& rhs){
		this->m_roman = rhs.m_roman;
		this->m_arabic = rhs.m_arabic;
		return  *this;
	}

	explicit operator int() {
		return m_arabic;
	}

	RomanNumber& operator+= (const RomanNumber& rhs){
		this->m_arabic += rhs.m_arabic;
		return *this;
	}

	RomanNumber& operator-= (const RomanNumber& rhs){
		this->m_arabic -= rhs.m_arabic;
		return *this;
	}

	RomanNumber& operator*= (const RomanNumber& rhs){
		this->m_arabic *= rhs.m_arabic;
		return *this;
	}

	RomanNumber& operator/= (const RomanNumber& rhs){
		this->m_arabic /= rhs.m_arabic;
		return *this;
	}

	RomanNumber operator+ (const RomanNumber& rhs){
		return RomanNumber(*this) += rhs;
	}

	RomanNumber operator- (const RomanNumber& rhs){
		return RomanNumber(*this) -= rhs;
	}

	RomanNumber operator* (const RomanNumber& rhs){
		return RomanNumber(*this) *= rhs;
	}

	RomanNumber operator/ (const RomanNumber& rhs){
		return RomanNumber(*this) /= rhs;
	}

	bool operator== (const RomanNumber& rhs){
		return (this->m_arabic == rhs.m_arabic);
	}

	bool operator!= (const RomanNumber& rhs){
		return !(*this == rhs);
	}

	bool operator> (const RomanNumber& rhs){
		return (this->m_arabic > rhs.m_arabic);
	}

	bool operator>= (const RomanNumber& rhs){
		return *this > rhs || *this == rhs;
	}

	bool operator< (const RomanNumber& rhs){
		return (this->m_arabic < rhs.m_arabic);
	}

	bool operator<= (const RomanNumber& rhs){
		return *this < rhs || *this == rhs;
	}

	RomanNumber& operator++ (){
		++this->m_arabic;
		return	*this;
	}

	RomanNumber operator++ (int){
		RomanNumber tmp = *this;
		(*this)++;
		return tmp;
	}

	RomanNumber& operator-- (){
		--this->m_arabic;
		return *this;
	}

	RomanNumber operator-- (int){
		RomanNumber tmp = *this;
		(*this)--;
		return tmp;
	}

	friend ostream& operator<< (ostream& os, RomanNumber& obj){
		RomanNumber tmp = obj;
		tmp.m_roman = ConvertToRoman(tmp.m_arabic);
		os << "Your roman number is: " << obj.m_roman << " Your arabic number is: " << obj.m_arabic;
		return os;
	}

	friend istream& operator>> (istream& is, RomanNumber& obj){
		int arabic;
		is >> arabic;
		obj.m_arabic = arabic;
		return is;
	}

	//OPERATORS OVERLOAD TO WORK WITH INT
	friend int operator+ (const int a, const RomanNumber&rhs){
		return a + rhs.m_arabic;
	}

	int operator+ (const int a){
		return m_arabic + a;
	}

	friend int operator- (const int a, const RomanNumber&rhs){
		return a - rhs.m_arabic;
	}

	int operator- (const int a){
		return m_arabic - a;
	}

	friend int operator* (const int a, const RomanNumber&rhs){
		return a * rhs.m_arabic;
	}

	int operator* (const int a){
		return m_arabic * a;
	}

	friend int operator/ (const int a, const RomanNumber&rhs){
		return a / rhs.m_arabic;
	}

	int operator/ (const int a){
		return m_arabic / a;
	}

	friend int operator+= (int a, const RomanNumber&rhs){
		a += rhs.m_arabic;
		return a;
	}

	int operator+= (const int a){
		m_arabic += a;
		return m_arabic;
	}

	friend int operator-= (int a, const RomanNumber&rhs){
		a -= rhs.m_arabic;
		return a;
	}

	int operator-= (const int a){
		m_arabic -= a;
		return m_arabic;
	}

	friend int operator*= (int a, const RomanNumber&rhs){
		a *= rhs.m_arabic;
		return a;
	}

	int operator*= (const int a){
		m_arabic *= a;
		return m_arabic;
	}

	friend int operator/= (int a, const RomanNumber&rhs){
		a /= rhs.m_arabic;
		return a;
	}

	int operator/= (const int a){
		m_arabic /= a;
		return m_arabic;
	}
	// COMPARSION WITH INTEGERS
	friend bool operator== (const int a, const RomanNumber& rhs){
		return (a == rhs.m_arabic);
	}

	friend bool operator!= (const int a, const RomanNumber& rhs){
		return !(a == rhs.m_arabic);
	}

	friend bool operator!= (const RomanNumber& lhs, const int a){
		return !(lhs.m_arabic == a);
	}

	friend bool operator> (const int a, const RomanNumber& rhs){
		return (a > rhs.m_arabic);
	}

	friend bool operator> (const RomanNumber& lhs, const int a){
		return !(a > lhs.m_arabic) && !(a == lhs.m_arabic);
	}

	friend bool operator>= (const int a, const RomanNumber& rhs){
		return a > rhs.m_arabic || a == rhs.m_arabic;
	}

	friend bool operator>= (const RomanNumber& lhs, const int a){
		return lhs.m_arabic > a || lhs.m_arabic == a;
	}

	friend bool operator< (const int a, const RomanNumber& rhs){
		return (a < rhs.m_arabic);
	}

	friend bool operator< (const RomanNumber& lhs, const int a){
		return !(a < lhs.m_arabic) && !(a == lhs.m_arabic);
	}

	friend bool operator<= (const int a, const RomanNumber& rhs){
		return a < rhs.m_arabic || a == rhs.m_arabic;
	}

	friend bool operator<= (const RomanNumber& lhs, const int a){
		return lhs.m_arabic < a || lhs.m_arabic == a;
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
	assert(r1 > r2);
	assert(r1 != r2);

	return 0;
}