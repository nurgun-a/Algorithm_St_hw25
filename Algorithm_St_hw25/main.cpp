#include "Student.h"

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool key_1 = 1;
	int size = 20;
	vector<Student> vSt;
	Gr g;
	Student* st = new Student[size];
	g.Creat_st(st);
	for (int i = 0; i < size; i++)
	{
		g(vSt, st[i]);
	}	

	char ch;
	do
	{
		cout << endl;
		show_menu();
		cout << "Enter: "; cin >> ch; cout << endl;
		system("cls");
		if (ch < '0' || ch>'3')
		{
			cout << "Ошибка ввода" << endl << endl;
		}
		else
		{
			switch (ch)
			{
				case '1':
				{
					sort_st(vSt);
				}break;
				case '2':
				{
					min_max(vSt);
				}break;
				case '3':
				{
					int f = 1;
					for (auto it : vSt)
					{
						cout << setw(4) << f << ")" << it << endl;
						f++;
					}
				}break;
				case '0':
				{

				}break;
			default:
				break;
			}
		}
	} while (key_1);
}