#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Student
{
protected:	
	string name, surname;
	int age;
	vector <int> ball;
	double avg_ball;
public:
	Student(){}
	Student(string _name, string _surname, int _age);
	void Set_avg();
	friend ostream& operator << (ostream& os, Student& st);
	Student rand_name1();
	Student rand_name2();
	double Get_avg(){return avg_ball;}
	string Get_name(){return name;}	
	string Get_surname(){return surname;}
	int Get_age(){return age;}
};

class Gr : protected Student
{
public:
	void operator() (vector<Student> &st, Student s){st.push_back(s);}
	void Creat_st(Student *& stu)
	{
		int size = 20;
		for (int i = 0; i < size; i++)
		{
			if(i<10)stu[i] = stu[i].rand_name1();
			else stu[i] = stu[i].rand_name2();
		}
			
	}	
};
void min_max(vector<Student>& st);
void sort_st(vector<Student>& st);

void show_menu();