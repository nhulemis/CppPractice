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
void OutputData(list<Student> students);

#pragma endregion




int main() {

	list<Student> students;
	Student s;
	s._id = 1;
	s._name = "abc haha";
	s._score = 7.5;
	InsertStudent(s, &students);
	InsertStudent(2, "xyz tao lao", 8, &students);
	InsertStudent(3, "obc thien dia", 7, &students);
	InsertStudent(4, "met roi nghe", 7.2, &students);
	InsertStudent(5, "hihi abc xyz", 7.3, &students);

	RangeScore(&students);


	// open file and write
	ofstream of;
	OpenFileWrite(of, students);

	//	OutputData(students);

		// open and read
	ifstream fin;
	list<Student> fileReads;
	OpenFileRead(fin, &fileReads);

	OutputData(fileReads);

	of.close();
	system("pause");
	return 0;
}

void OutputData(list<Student> students) {
	cout << "id \t name \t\t\t score\n";
	for each (auto item in students)
	{
		cout << item._id << "\t" << item._name << "\t\t" << item._score << endl;
	}
}

void OpenFileRead(ifstream &fin, list<Student> *fileReads) {
	// read file
	fin.open("studenmanager.txt");
	if (!fin)
	{
		return;
	}

	// reading file from file in to student
	//fin.read((char*)&s, sizeof(s));

	string temp;

	//getline(fin, temp);
	int id;
	string firstName, lastName;

	float score;
	
//	getline(fin, temp);
	//cout << temp;
	while (getline(fin,temp))
	{
		Student s;
		s._id = std::stoi(temp);
		getline(fin, temp);
		s._name = temp ;
		getline(fin, temp);
		s._score = std::stof(temp);
		fileReads->push_back(s);	
	}

}

void RangeScore(list<Student> *students) {
	students->sort(Compare);
}

void OpenFileWrite(ofstream &of, list<Student> students) {
	of.open("studenmanager.txt");
	if (!of)
	{
		return;
	}
	for each (auto item in students)
	{
		of << item._id << "\n" << item._name << "\n" << item._score << endl;
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
