#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
class ASTBinaryNode{
	T a;
	T b;
public:
	ASTBinaryNode(const T& left, const T& right) : a(left), b(right){}
	virtual T evaluate() const = 0;
	T GetA() const {
		return a;
	}
	T GetB() const {
		return b;
	}
};

template<typename T>
class ASTBinaryNodePlus : public ASTBinaryNode<T>
{
public:
	ASTBinaryNodePlus(const T& left, const T& right) : ASTBinaryNode(left, right) {}
	T evaluate() const override{
		return this->GetA() + this->GetB();
	}
};

template<typename T>
class ASTBinaryNodeMinus : public ASTBinaryNode<T>
{
public:
	ASTBinaryNodeMinus(const T& left, const T& right) : ASTBinaryNode(left, right) {}
	T evaluate() const override{
		return this->GetA() - this->GetB();
	}
}; 

template<typename T>
class ASTBinaryNodeDivide : public ASTBinaryNode<T>
{
public:
	ASTBinaryNodeDivide(const T& left, const T& right) : ASTBinaryNode(left, right) {}
	T evaluate() const override{
		return this->GetA() / this->GetB();
	}
};

template<typename T>
class ASTBinaryNodeMultiply : public ASTBinaryNode<T>
{
public:
	ASTBinaryNodeMultiply(const T& left, const T& right) : ASTBinaryNode(left, right) {}
	T evaluate() const override{
		return this->GetA() * this->GetB();
	}
};
int main(){
	const int size = 4;
	int x = 20;
	int y = 10;
	double xD = 12.5;
	double yD = 3.7;
	ASTBinaryNode<int>* ASTB[size];
	ASTB[0] = new ASTBinaryNodePlus<int>(x, y);
	ASTB[1] = new ASTBinaryNodeMinus<int>(x, y);
	ASTB[2] = new ASTBinaryNodeDivide<int>(x, y);
	ASTB[3] = new ASTBinaryNodeMultiply<int>(x, y);
	assert(ASTB[3]->evaluate() > ASTB[2]->evaluate());
	for (size_t i = 0; i < size; i++)
	{
		cout << ASTB[i]->evaluate() << endl;
	}
	ASTBinaryNode<double>* ASTBD[size];
	ASTBD[0] = new ASTBinaryNodePlus<double>(xD, yD);
	ASTBD[1] = new ASTBinaryNodeMinus<double>(xD, yD);
	ASTBD[2] = new ASTBinaryNodeDivide<double>(xD, yD);
	ASTBD[3] = new ASTBinaryNodeMultiply<double>(xD, yD);
	assert(ASTBD[0]->evaluate() != ASTBD[1]->evaluate());
	for (size_t i = 0; i < size; i++)
	{
		cout << ASTBD[i]->evaluate() << endl;
	}

	for (size_t i = 0; i < size; i++)
	{
		delete ASTB[i];
		delete ASTBD[i];
	}

	return 0;
}