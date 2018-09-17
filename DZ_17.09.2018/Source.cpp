#include<iostream>
#include<string>
using namespace std;

struct Clothes
{
	string name;
	string color;
	int size;
	int heigh;

	void enter_cloth()
	{
		cin >> name >> color >> size >> heigh;
	}
	void print_cloth()
	{
		cout << name << " " << color << " " << size << " " << heigh << endl;
	}
	bool cmp_by_size(double cmp_size)
	{
		return (size >= cmp_size);
	}
	bool cmp_by_heigh(double cmp_heigh)
	{

		return (heigh >= cmp_heigh);
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, choice;
	int c_size, c_heigh;
	bool f = true;

	Clothes* cc;
	cout << "¬ведите количество одежды: ";
	cin >> n;
	cc = new Clothes[n];
	for (int i = 0; i < n; i++)
	{
		cc[i].enter_cloth();
	}
	while (true)
	{
		cout << "1 - ¬ывести список одежды с размером больше или равно заданному." << endl;
		cout << "2 - ¬ывести список одежды с длиной больше или равно заданному." << endl;
		cout << "3 - ¬ывести весь список." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: 
		{
			cin >> c_size;
			for (int i = 0; i < n; i++)
			{
				if (cc[i].cmp_by_size(c_size) == true)
					cc[i].print_cloth();
			}
		}
			break;
		case 2:
		{
			cin >> c_heigh;
			for (int i = 0; i < n; i++)
			{
				if (cc[i].cmp_by_heigh(c_heigh) == true)
					cc[i].print_cloth();
			}
		}
			break;
		case 3: for (int i = 0; i < n; i++)
		{
			cc[i].print_cloth();
		}
			break;
		default: f = false;
			break;
		}
	}
	delete[] cc;
	system("pause");
}