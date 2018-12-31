#include <iostream>
#include <string>
#include <list>

using namespace std;
#pragma region Struct
struct Student
{
	int _id;
	string _name;
	float _score;
};

#pragma endregion

#pragma region declare function and properties


void InsertStudent(int id, string name, float score,list<Student> *students);
void InsertStudent(Student s, list<Student> *students);
bool CheckExists(int id, list<Student> students);

#pragma endregion




int main() {

	list<Student> students;
	Student s;
	s._id = 1;
	s._name = "abc xyz";
	s._score = 7.5;
	InsertStudent(s,&students);
	for each (auto item in students)
	{
		cout << item._id;
	}
	system("pause");
	return 0;
}

void InsertStudent(int id, string name, float score, list<Student> *students) {
	if (CheckExists(id,* students))
	{
		Student s;
		s._id = id;
		s._name = name;
		s._score = score;
		students->push_back(s);
		cout << "\nadd complete\n";
		return;
	}
	cout << "\nthis ID was exists\n";
}

void InsertStudent(Student s, list<Student> *students) {
	//list<Student> a = *students;
	if (CheckExists(s._id,* students))
	{
		students->push_back(s);
		cout << "\nadd complete\n";
	}
	else
	{
		cout << "\nthis ID was exists\n";
	}
	return;
}

bool CheckExists(int id,list<Student> students) {
	for each (auto item in students)
	{
		if (item._id == id)
		{
			return false;
		}
	}
	return true;
}
