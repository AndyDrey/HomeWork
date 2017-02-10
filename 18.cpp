#include <iostream>

using namespace std;

struct Professor
{
	char name[20];
	unsigned short age;
	unsigned int salary;
};

struct Student
{
	char name[20];
	unsigned short age;
	float gpa;
	Professor* supervisior;
};

void FindAverageMark(Student *p, int exampleInt){
	float averageMark = 0;
	for (size_t i = 0; i < exampleInt; i++)
	{
		averageMark += p[i].gpa;
	}
	cout << " Average mark is: " << averageMark / exampleInt << endl;
}

void FindBestStudent(Student *p, int exampleInt)
{
	int bestMark = p[0].gpa;
	int bestIndex = 0;
	for (size_t i = 1; i < exampleInt; i++)
	{
		if (p[i].gpa > bestMark)
		{
			bestMark = p[i].gpa;
			bestIndex = i;
		}
	}
	cout << "Best student is: " << p[bestIndex].name << "whith average mark = " << p[bestIndex].gpa << ".He is " << p[bestIndex].age << endl;
}

void FindWorstStudent(Student *p, int exampleInt)
{
	int worstMark = p[0].gpa;
	int worstIndex = 0;
	for (size_t i = 1; i < exampleInt; i++)
	{
		if (p[i].gpa < worstMark)
		{
			worstMark = p[i].gpa;
			worstIndex = i;
		}
	}
	cout << "Worst student is: " << p[worstIndex].name << "whith average mark = " << p[worstIndex].gpa << ".He is " << p[worstIndex].age << endl;
}

void FindSupervisiorOlderThen50(Student *p, int exampleInt)
{
	for (size_t i = 0; i < exampleInt; i++)
	{
		if (p[i].supervisior->age > 50)
		{
			cout << p[i].name << " whith average mark " << p[i].gpa << ".He is " << p[i].age << endl;
		}
	}
}

int main()
{
	const int exampleInt = 2;
	Professor professors[exampleInt];
	for (size_t i = 0; i < exampleInt; i++)
	{
		cout << "Add some information about professor\n";
		cin >> professors[i].name >> professors[i].age >> professors[i].salary;
	}
	Student group[exampleInt];
	for (int i = 0; i < exampleInt; i++)
	{
		cout << "Add some information about student\n";
		cin >> group[i].name >> group[i].age >> group[i].gpa;
		group[i].supervisior = professors+i;
	}
	Student *p = group;

	FindAverageMark(p, exampleInt);
	FindBestStudent(p, exampleInt);
	FindWorstStudent(p, exampleInt);
	FindSupervisiorOlderThen50(p, exampleInt);

	return 0;
}