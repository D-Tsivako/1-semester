#include <fstream>
#include <iostream>
#include "Student.h"

using namespace std;

Student* Read(char*);
void Write(char* binaryFile, Student* students, int number);
void DisplayFile(char*);
void SystemFun();

int main()
{
	char fileName[] = "C:/Users/Lenovo/Documents/vs/22.05.2019 para/text.txt";
	char binaryFile[N] = "binary.bin";
	Student* student = new Student[9];
	student = Read(fileName);
	
	Write(binaryFile, student, 9);
	DisplayFile(binaryFile);
	cout << endl;

	system("pause");
}


Student* Read(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	Student* student = new Student[9];
	char name[30];
	char secondName[30];
	char faculty[30];
	int marks[4];

	for (int i = 0; i < 9; i++)
	{
		streamIn >> name;
		streamIn >> secondName;
		streamIn >> faculty;
		
		for (int j = 0; j < 4; j++)
		{
			streamIn >> marks[j];
		}

		student[i].SetStudent(name, secondName, faculty, marks);
	}
	return student;
}


void Write(char* binaryFile, Student* student, int n)
{
	ofstream streamOut;
	streamOut.open(binaryFile, ios::binary);
	
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	
	int buffSize = sizeof(Student);
	
	for (int i = 0; i < n; i++)
	{
		streamOut.write((char*)&student[i], buffSize);
	}
	streamOut.close();
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}
	
	int bufSize = sizeof(Student);
	Student* man = new Student;
	
	while (streamIn.read((char*)man, bufSize))
	{
		man->DisplayStudent();
	}
	
	streamIn.close();
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}