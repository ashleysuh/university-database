/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Student.cpp                                                       *
 *                                                                             *
 *  Reads from the text file Student.txt. Assigns personal information         *
 *  to students including courses enrolled, graduate level, etc                *
 *******************************************************************************/

#include <iostream>
#include <string>  // for using strings
#include <fstream> // for reading files
#include <istream>
#include <sstream> // for string splitting
#include <vector>  // for using vectors
#include "Student.h"
using namespace std;

Student::Student(string sn) : Person () {
	defaultName = sn;
}

Student::Student(string name, string dOB, string gender, string uID, string type, string department, string courseName, string grades) : Person (name, dOB, gender, uID, type, department, courseName) {
	grade = grades;
} // Overloaded constructor to create student objects

Student::~Student() {
}

string Student::getDefault() {
	return defaultName;
}

void Student::createStudent(vector <Student>& newMyClass) {
	ifstream inFile; // opens Students.txt
	string myName, myDOB, myGender, myUID, myType, myDepartment, myCourseName, myGrade, blankLine;

	inFile.open("Students.txt");
	int numStudents = getLines(inFile);
	inFile.close(); // opens & closes file to read # of lines--to create # of student objects

	inFile.open("Students.txt");
	if (inFile.good()) {
		for (int i = 0; i < numStudents; i++) {
			getline(inFile, myName); // reads name
			getline(inFile, myDOB); // reads DOB
			getline(inFile, myGender); // reads gender
			getline(inFile, myUID); // reads UID
			getline(inFile, myType); // reads type
			getline(inFile, myDepartment); // reads dpt 
			getline(inFile, myCourseName); // reads courses
			getline(inFile, myGrade); // reads grades
			getline(inFile, blankLine); // reads new line
			Student newStudent(myName, myDOB, myGender, myUID, myType, myDepartment, myCourseName, myGrade); // creates new student object
			newMyClass.push_back(newStudent); // pushes current student object back into vector, until EOF
		}
	}
	else 
		cout << "File not read." << endl;

	inFile.close();
}

void Student::degreeType() {
	string gradLevel = getType(); // calls person's getType() to identify what the string was read from file
	string courseTA = getCourseName(); // calls person's courses if student is a TA
	string studentName = getName(); // calls person's name to print

	cout << "PRINTING DEGREE TYPE FOR INDEXED STUDENT..." << endl;
	cout << studentName << " is ";

	if (gradLevel == "Undergraduate") {
		cout << "an Undergraduate.\n" << endl;
	}
	else if (gradLevel == "Graduate TA") {
		cout << "a Graduate: Teaching Assistant.\n";
		cout << "Student is teaching: " << courseTA << endl; 
	}
	else if (gradLevel == "Graduate RA") {
		cout << "a Graduate: Research Assistant.\n" << endl;
	}
	else {
		cout << "not currently enrolled in a degree program.\n" << endl;
	}
	cout << "*******************************************************************" << endl;
}

void Student::printGrades() {
	string myCourse = getCourseName(); // gets courses for particular student index
	string myGrade = getGrade(); // gets grades for particular student 
	string myName = getName(); // gets student name for particular index
	stringstream ss1(myCourse); // creates a string object copied from our list of students
	stringstream ss2(myGrade); // reads string of grades to separate with delimiter 
	string token1, token2; // token to read courses 
	string level = getType();

	if (level == "Undergraduate") {
		cout << "PRINTING GRADES FOR STUDENT " << myName << "..." <<endl;
		while (getline(ss1, token1, ',')) { // reads the complete line of courses, separating each one by the comma delimiter 
			courseVector.push_back(token1); // pushes back the individual course into the course vector
		}
		while (getline(ss2, token2, ',')) { // reads the complete line of grades, separating each one by the comma delimiter
			gradeVector.push_back(token2); // pushes the individual grade into the grade vector
		}

		for (size_t i = 0; i < courseVector.size(); i++) // cycles through entire vector
			cout << courseVector.at(i) << ": " << gradeVector.at(i) << endl; // prints the course and respective grade
	}
	else
		cout << "Student either has no grades to report, or is a graduate student." << endl;
	cout << "*******************************************************************" << endl;
}

int Student::getLines(istream& myFile) {
    int numLines = 0;
    string line;

    while (getline(myFile, line)) { // continues incrementing numLines until EOF
        ++numLines;
	}
    return (numLines+1)/9; // returns the number of students contained in the file (each student is 9 lines long)
}

string Student::getGrade() {
	return grade; // returns grades belonging to a student
}

void Student::printStudentsInFile(vector<Student>& newMyClass) {
	int size = newMyClass.size(); // determines the size of the vector, since it was already created previously
	cout << "PRINTING STUDENTS FROM FILE..." << endl; 
	for (int i = 0; i < size; i++) {
		cout << newMyClass[i].getName() << endl; // prints only the names of the students from the vector
	}
	cout << "*******************************************************************" << endl;
}

void Student::printAllStudents(vector <Student>& newMyClass) {
	int size = newMyClass.size(); // determines the size of the vector, since it was already created previously
	for (int i = 0; i < size; i++) { // prints the entire contents of student vector
		cout << "Student Name: " << newMyClass[i].getName() << endl;
		cout << "DOB: " << newMyClass[i].getDOB() << endl;
		cout << "Gender: " << newMyClass[i].getGender() << endl;
		cout << "uID: " << newMyClass[i].getUID() << endl;
		cout << "Classification: " << newMyClass[i].getType() << endl;
		cout << "Department: " << newMyClass[i].getDepartment() << endl;
		cout << "Courses Enrolled: " << newMyClass[i].getCourseName() << endl;
		cout << "Grade: " << newMyClass[i].getGrade() << endl;
		cout << "\n";
	}
}