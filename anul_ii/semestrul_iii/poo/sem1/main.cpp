#include <string>
#include <iostream>
using namespace std;

typedef struct student{
	string name;
	string pren;
	int varsta;
	float med;
}student;

student creare(){
	student stud;
	cout << "enter student name" << endl;
	cin >> stud.name;
	cout << "enter student surname" << endl;
	cin >> stud.pren;
	cout << "enter student age" << endl;
	cin >> stud.varsta;
	cout << "enter student mark" << endl;
	cin >> stud.med;
	return stud;
}


int main()
{
	student stud = creare();
	cout << stud.name << endl;
	cout << stud.pren << endl;
	cout << stud.varsta << endl;
	cout << stud.med << endl;
	return 0;
}
