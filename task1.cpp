#include <iostream>
#include <vector>

using namespace std;

class HTMLElemen{
public:
	unsigned Width() const;
	unsigned Height() const;
	bool Hidden() const;
	virtual string Render() = 0;
};

class HTMLButtonElement : public HTMLElemen{
public:
	const string& Title() const;
	string Render() override{
		return "<button>title-of-the-button</button>\n";
	}
};

class HTMLImageElement : public HTMLElemen{
public:
	const string& Url() const;
	string Render() override{
		return "<img src=\"../../smiley.gif\" height=\"42\" width=\"42\">\n";
	}
};

class HTMLTextAreaDocument : public HTMLElemen{
public:
	const string& Content() const;
	string Render() override{
		return "<textarea>\ncontent-of-the-text-area\n</textarea>\n";
	}
};


int main(int argc, char *argv[])
{
	HTMLButtonElement a1;
	HTMLImageElement a2;
	HTMLTextAreaDocument a3;
	cout << a1.Render();
	cout << a2.Render();
	cout << a3.Render();
	return 0;
}