/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Teacher.cpp                                                       *
 *                                                                             *
 *  Reads from the text file Teachers.txt. Assigns personal information        *
 *  to teachers including courses enrolled, job classification, etc            *
 *******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include "Teacher.h"

using namespace std;

Teacher::Teacher(string tn) : Person () {
	defaultName = tn;
}

Teacher::Teacher(string name, string dOB, string gender, string uID, string type, string department, string courseName) : Person (name, dOB, gender, uID, type, department, courseName) {
} // Overloaded constructor

Teacher::~Teacher() {
}

string Teacher::getDefault() {
	return defaultName;
}

void Teacher::createTeacher(vector<Teacher>& newMyClass) {
	ifstream inFile;
	string myName, myDOB, myGender, myUID, myType, myDepartment, myCourseName, blankLine; // strings to read from file

	inFile.open("Teachers.txt");
	int numTeachers = getLines(inFile); // calculates how many teacher objects to create
	inFile.close();

	inFile.open("Teachers.txt");
	if (inFile.good()) {
		for (int i = 0; i < numTeachers; i++) {
			getline(inFile, myName); // read name of teacher
			getline(inFile, myDOB); // read DOB
			getline(inFile, myGender); // read gender
			getline(inFile, myUID); // read ID
			getline(inFile, myDepartment); // read department
			getline(inFile, myType); // read job type
			getline(inFile, myCourseName); // read courses enrolled
			getline(inFile, blankLine); // read blank line
			Teacher newTeacher(myName, myDOB, myGender, myUID, myType, myDepartment, myCourseName); // creates teacher object from overloaded constructor
			newMyClass.push_back(newTeacher); // pushes current teacher object into vector of teacher objects
		}
	}
	else
		cout << "File not read." << endl;
	inFile.close();
}

int Teacher::getLines(istream& myFile) {
	int numLines = 0;
	string line;

	while (getline(myFile, line)) {
		++numLines;
	}
	
	return (numLines+1)/8; // returns # of teacher objects to create, each teacher is 8 lines long
}

void Teacher::jobType() {
	string profession = getType(); // calls person's getType() to identify what the string was read from file
	string teacherName = getName(); // calls person's name to print
	string dpt = getDepartment(); // calls person's department to print

	cout << "PRINTING CLASSIFCATION FOR INDEXED TEACHER..." << endl;
	cout << teacherName << " is ";

	if (profession == "Professor") {
		cout << "a Professor in the " << dpt << " department." << endl;
	}
	else if (profession == "Adjunct") {
		cout << "an Adjunct in the " << dpt << " department." << endl;
	}
	else if (profession == "Lecturer") {
		cout << "a Lecturer in the " << dpt << " department." << endl;
	}
	else {
		cout << "not currently listed as a faculty type." << endl;
	}
	cout << "*******************************************************************" << endl;
}

void Teacher::printTeachersInFile(vector<Teacher>& newMyClass) {
	int size = newMyClass.size();
	cout << "PRINTING TEACHERS FROM FILE..." << endl;
	for (int i = 0; i < size; i++) 
		cout << newMyClass[i].getName() << endl; // prints only the names of teachers from file
	cout << "*******************************************************************" << endl;
}

void Teacher::printAllTeachers(vector<Teacher>& newMyClass) {
	int size = newMyClass.size();
	for (int i = 0; i < size; i++) {
		cout << "Teacher Name: " << newMyClass[i].getName() << endl;
		cout << "DOB: " << newMyClass[i].getDOB() << endl;
		cout << "Gender: " << newMyClass[i].getGender() << endl;
		cout << "uID: " << newMyClass[i].getUID() << endl;
		cout << "Profession: " << newMyClass[i].getType() << endl;
		cout << "Department: " << newMyClass[i].getDepartment() << endl;
		cout << "Courses Teaching: " << newMyClass[i].getCourseName() << endl;
		cout << "\n";
	}
}