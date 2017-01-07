#include <iostream>
#include <string>
using namespace std;


class BinaryTree{
public:
	string m_value;
	BinaryTree* l;
	BinaryTree* r;
	BinaryTree(const string& value) : m_value(value){}
	void AddLeft(BinaryTree* left) {
		l = left;
	};
	void AddRight(BinaryTree* right){
		r = right;
	};
	string Serialize()
	{
		string ser = m_value;
		if (l || r){
			ser += "(";
			if (l){
				ser += l->Serialize();
			}
			else
				ser += ", ";
			if (r)
			{
				ser += r->Serialize();
			}
			else
				ser += ")";
		}
		return ser;
	}
	friend ostream& operator<< (ostream& os, BinaryTree& obj);
};

ostream& operator<< (ostream& os, BinaryTree& obj){
	os << obj.Serialize();
	return os;
}

int main(){
	BinaryTree root("+");
	BinaryTree left1("1");
	BinaryTree right2("2");
	root.AddLeft(&left1);
	root.AddRight(&right2);
	cout << root.Serialize();
	BinaryTree left3("3");
	BinaryTree right4("4");
	left1.AddLeft(&left3);
	left1.AddRight(&right4);
	cout << root.Serialize();
	cout << root;
	return 0;
}
