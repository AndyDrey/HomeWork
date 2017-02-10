#include <iostream>
#include <string>
using namespace std;

template<typename T>
class BinaryTree{
public:
	T m_value;
	BinaryTree* l = nullptr;
	BinaryTree* r = nullptr;
	BinaryTree(const T& value) : m_value(value){}
	void AddLeft(BinaryTree* left) {
		l = left;
	};
	void AddRight(BinaryTree* right){
		r = right;
	};
	string Serialize()
	{
		ostringstream stream;
		stream << m_value;
		string str = stream.str();
		if (l || r){
			ser += "(";
			if (l){
				ser += l->Serialize();
				ser += ",";
			}
			else
				ser += ",";
			if (r)
			{
				ser += r->Serialize();
				ser += ")";
			}
			else
				ser += ")";
		}
		return ser;
	}
	friend ostream& operator<< (ostream& os, BinaryTree& obj);
};

template<typename T>
ostream& operator<< (ostream& os, BinaryTree<T>& obj){
	os << obj.Serialize();
	return os;
}

int main(){
	BinaryTree<int> root(1);
	BinaryTree<int> left1(2);
	BinaryTree<int> right2(3);
	root.AddLeft(&left1);
	root.AddRight(&right2);
	BinaryTree<int> left3(4);
	BinaryTree<int> right4(5);
	left1.AddLeft(&left3);
	left1.AddRight(&right4);
	BinaryTree<int> left5(6);
	BinaryTree<int> right6(7);
	right2.AddLeft(&left5);
	right2.AddRight(&right6);
	cout << root.Serialize() << endl;
	return 0;
}
