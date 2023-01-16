#include "Student.h"

ostream& operator<<(ostream& os, Student& st)
{
	os << setw(12) << st.name << setw(12) << st.surname
		<< setw(5) << st.age << setw(6) << st.avg_ball;
	return os;
}

void min_max(vector<Student>& st)
{
	cout << endl;
	cout << "������� � ������������ ������� ������:";

	auto it = min_element(st.begin(), st.end(), [](Student s1, Student s2)
		{
			return s1.Get_avg() < s2.Get_avg();
		});

	cout << *it << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "������� � ����������� ������� ������: ";
	it = max_element(st.begin(), st.end(), [](Student s1, Student s2)
		{
			return s1.Get_avg() < s2.Get_avg();
		});

	cout << *it << endl;
}

void sort_st(vector<Student>& st)
{
	bool key = 1;
	int i=1;
	do
	{
		cout << "1 - ���������� �� �����" << endl;
		cout << "2 - ���������� �� �������" << endl;
		cout << "3 - ���������� �� �������� �����" << endl;
		char n;
		cout << "Enter: "; cin >> n; cout << endl;
		system("cls");
		if (n<'0'||n>'3')
		{
			cout << "������ �����" << endl << endl;
		}
		else
		{
			switch (n)
			{
				case '1':
				{
					sort(st.begin(), st.end(), [](Student s1, Student s2)
						{
							return s1.Get_name() < s2.Get_name();
						});
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '2':
				{
					sort(st.begin(), st.end(), [](Student s1, Student s2)
						{
							return s1.Get_surname() < s2.Get_surname();
						});
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '3':
				{
					sort(st.begin(), st.end(), [](Student s1, Student s2)
						{
							return s1.Get_avg() < s2.Get_avg();
						});
					i = 1;
					for (auto it : st)
					{
						cout << setw(4) << i << ")" << it << endl;
						i++;
					}
					key = 0;
				}break;
				case '0':
				{
					key = 0;
				}break;
			default:
				break;
			}
		}
		
	} while (key);
}

void show_menu()
{
	cout << "�������� �������� �� ������������������:" << endl;
	cout << "1 - ����������" << endl;
	cout << "2 - ������� �������� � ������������ � ����������� ������� ������" << endl;
	cout << "3 - ������� �� �����" << endl;
	cout << "0 - �����" << endl;
}

Student::Student(string _name, string _surname, int _age)
{
	name = _name; surname = _surname; age = _age;
	for (int i = 0; i < 10; i++)
		ball.push_back(rand() % 8 + 4);
	Set_avg();
}

void Student::Set_avg()
{
	int sum = 0;
	for (int i = 0; i < ball.size(); i++)
		sum += ball[i];
	avg_ball = (double)sum / ball.size();
}

Student Student::rand_name1()
{
	string* name = new string[10]
	{ "����������","���������","���","������","����","����","�������","�����","����","����" };
	string* surname = new string[10]
	{ "�������","������","�������","�����","��������","�������","���������","�����","������","�������" };
	Student st(name[rand() % 10], surname[rand() % 10], rand() % 16 + 16);
	return st;
}

Student Student::rand_name2()
{
	string* name = new string[10]
	{ "��������","�����","�������","�����", "����������","�����","����","���","�������","�����" };
	string* surname = new string[10]
	{ "���������","��������","��������","���������", "���������","������","��������","�������","�������","����������" };
	Student st(name[rand() % 10], surname[rand() % 10], rand() % 16 + 16);
	return st;
}
