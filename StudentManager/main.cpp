#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include<Windows.h>
#include <vector>

using namespace std;

#pragma region Struct
struct Student
{
	int _id;
	string _name;
	float _score;
};

#pragma endregion

#pragma region declare function

void InsertStudent(int id, string name, float score, list<Student> *students);
void InsertStudent(Student s, list<Student> *students);
bool CheckExists(int id, list<Student> students);
void RangeScore(list<Student> *students);
bool Compare(const Student &a, const Student &b);
void OpenFileWrite(ofstream &of, list<Student> students);
void OpenFileRead(ifstream &fin, list<Student>* fileReads);
void OutputData(list<Student> students);
void ShowMenu();
void InputStudent(list<Student> *students);
bool AllowFileName(string fname);

// use vector for manager
void InsertStudentIntoVector(vector<Student> *listStudent);
bool CheckExistsInVector(Student s, vector<Student> list);
#pragma endregion




int main() {

	list<Student> students;

	vector<Student> listStudent;

	InsertStudent(2, "xyz tao lao", 8, &students);
	InsertStudent(3, "obc thien dia", 7, &students);
	InsertStudent(4, "met roi nghe", 7.2, &students);
	InsertStudent(5, "hihi abc xyz", 7.3, &students);

	system("cls");

	ofstream of;

	ifstream fin;

	int sc;
	do
	{
		//
		ShowMenu();
		cout << "your choose : ";
		cin >> sc;
		switch (sc)
		{
		case 1: 
			InputStudent(&students);
		//	InsertStudentIntoVector(&listStudent);
			cout << "\n\n";
			break;
		case 2:
			OutputData(students);
			cout << "\n\n";
			break;
		case 3:
			OpenFileWrite(of, students);
			of.close();
			break;
		case 4:
			students.clear();
			OpenFileRead(fin, &students);
			break;
		default:
			sc = 0;
			break;
		}
	} while (sc != 0);

	system("pause");
	return 0;
}

void InsertStudentIntoVector( vector<Student> *listStudent){
	Student s;
	int id;
	string name;
	float score;
	cout << "ID : ";
	cin >> s._id;
	cin.ignore();
	cout << "Name : ";
	getline(cin, s._name);
	fflush(stdin);
	//cin.ignore();
	cout << "Score : ";
	cin >> s._score;

	if (CheckExistsInVector(s,*listStudent))
	{
		listStudent->push_back(s);
		cout << "\t add complete \n";
		return;
	}
	cout << "\t id was exists\n";
}

bool CheckExistsInVector(Student s, vector<Student> list) {
	for each (auto var in list)
	{
		if (s._id== var._id)
		{
			return false;
		}
	}
	return true;
}

bool AllowFileName(string fname){
	if (fname.find(".txt") || fname.find(".cpp"))
	{
		return true;
	}
	return false;
}

void InputStudent(list<Student> *students) {
	int id;
	string name;
	float score;
	cout << "ID : ";
	cin >> id;
	cin.ignore();
	cout << "Name : ";
	getline(cin, name);
	fflush(stdin);
	//cin.ignore();
	do
	{
		cout << "Score : ";
		cin >> score;

	} while (score>=0 && score <=10);
	InsertStudent(id, name, score, students);
}

void ShowMenu() {
	cout << "-----------Menu-----------\n";
	cout << "\t 1. Input\n";
	cout << "\t 2. Display\n";
	cout << "\t 3. Save to file\n";
	cout << "\t 4. Load from file\n";
	cout << "\t 0. exit\n";
	cout << "--------------------------\n\t";
}

void OutputData(list<Student> students) {
	cout << "id \t name \t\t\t score\n";
	for each (auto item in students)
	{
		cout << item._id << "\t" << item._name << "\t\t" << item._score << endl;
	}
}

void OpenFileRead(ifstream &fin, list<Student> *fileReads) {
	string fname;
	cout << "please input file name with format *.txt or *.cpp\nIf you don't input file name,we will set 'studentmanager.txt' as default\n file name : ";
	cin.ignore();
	getline(cin, fname);
	if (size(fname) == 0)
	{
		fname = "studentmanager.txt";
	}
	if (!AllowFileName(fname))
	{
		cout << "format file not support\n";
		return;
	}

	// read file
	fin.open(fname);
	if (!fin)
	{
		cout << "open file fail\n";
		return;
	}

	string temp;

	while (getline(fin, temp))
	{
		Student s;
		s._id = std::stoi(temp);
		getline(fin, temp);
		s._name = temp;
		getline(fin, temp);
		s._score = std::stof(temp);
		fileReads->push_back(s);
	}

	cout << "\n\nRead complete\n\n";
}

void RangeScore(list<Student> *students) {
	students->sort(Compare);
}

void OpenFileWrite(ofstream &of, list<Student> students) {
	string fname;
	cout << "please input file name with format *.txt or *.cpp\nIf you don't input file name,we will set 'studentmanager.txt' as default\n file name : ";
	cin.ignore();
	getline(cin, fname);
	if (size(fname)==0)
	{
		fname = "studentmanager.txt";
	}
	if (!AllowFileName(fname))
	{
		cout << "format file not support\n";
		return;
	}
	of.open(fname);
	if (!of)
	{
		cout << "open file fail\n";
		return;
	}
	for each (auto item in students)
	{
		of << item._id << "\n" << item._name << "\n" << item._score << endl;
	}
	cout << "\n\nSave complete\n\n";
	of.close();
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
		cout << "\nadd complete";
	//	Sleep(2000);
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


