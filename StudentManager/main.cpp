#include <iostream>
#include <string>
#include <list>
#include <fstream>
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


void InsertStudent(int id, string name, float score, list<Student> *students);
void InsertStudent(Student s, list<Student> *students);
bool CheckExists(int id, list<Student> students);
void RangeScore(list<Student> *students);
bool Compare(const Student &a, const Student &b);
void OpenFileWrite(ofstream &of, list<Student> students);
void OpenFileRead(ifstream &fin, list<Student>* fileReads);
#pragma endregion




int main() {

	list<Student> students;
	Student s;
	s._id = 1;
	s._name = "abc xyz";
	s._score = 7.5;
	InsertStudent(s, &students);
	InsertStudent(2, "xyz abc", 8, &students);
	InsertStudent(3, "obc haha", 7.2, &students);

	// open file and write
	ofstream of;
	OpenFileWrite(of, students);

	// open and read
	ifstream fin;
	list<Student> fileReads;
	OpenFileRead(fin, &fileReads);

	of.close();
	system("pause");
	return 0;
}

void OpenFileRead(ifstream &fin, list<Student> *fileReads) {
	// read file
	fin.open("studenmanager.txt");

	Student s;
	// reading file from file in to student
	//fin.read((char*)&s, sizeof(s));

	string temp;

	getline(fin, temp);

	cout << temp;

	/*while (!fin.eof()) {
		cout << s._id << endl;
		fin.read((char*)&s, sizeof(s));
	}*/
}

void RangeScore(list<Student> *students) {
	students->sort(Compare);
}

void OpenFileWrite(ofstream &of, list<Student> students) {
	of.open("studenmanager.txt");

	for each (auto item in students)
	{
		of << item._id << "\t" << item._name << "\t\t" << item._score << endl;
	}
}

bool Compare(const Student &a, const Student &b) {
	return a._score > b._score;
}

void InsertStudent(int id, string name, float score, list<Student> *students) {
	if (CheckExists(id, *students))
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
	if (CheckExists(s._id, *students))
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

bool CheckExists(int id, list<Student> students) {
	for each (auto item in students)
	{
		if (item._id == id)
		{
			return false;
		}
	}
	return true;
}
