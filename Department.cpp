/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Department.cpp                                                    *
 *                                                                             *
 *  Reads from the text file Departments.txt. Assigns information              *
 *  specific to a department: including students, teachers, courses            *
 *******************************************************************************/

#include <iostream>
#include <string>  // for using strings
#include <fstream> // for reading files
#include <istream>
#include <sstream>
#include <vector>  // for using vectors
#include "Department.h"

using namespace std;

/* The way Departments.txt should be read:
	Department name: DEPARTMENT_NAME
	Courses offered: COURSES_OFFERED
	Students in DPT: STUDENT_NAMES
	Teachers in DPT: TEACHER_NAMES
*/

Department::Department() {
}

Department::Department(string deptName, string coursesDPT, string studentsDPT, string teachersDPT) {
	dptName = deptName;
	crseDPT = coursesDPT;
	stdsDPT = studentsDPT;
	teachDPT = teachersDPT;
} // Overloaded constructor

Department::~Department() {
}

string Department::getDPT() {
	return dptName;
}

string Department::getCoursesDPT() {
	return crseDPT;
}

string Department::getStudentsDPT() {
	return stdsDPT;
}

string Department::getTeachersDPT() {
	return teachDPT;
}

void Department::createDepartment(vector <Department>& newMyClass) {
	ifstream inFile; // to open Departments.txt
	string dptName, coursesInDPT, studentsInDPT, teachersInDPT, blankLine;

	inFile.open("Departments.txt");
	int numDepartments = getLines(inFile);
	inFile.close();

	inFile.open("Departments.txt");
	if (inFile.good()) {
		for (int i = 0; i < numDepartments; i++) {
			getline(inFile, dptName); // reads department name
			getline(inFile, coursesInDPT); // reads courses in DPT
			getline(inFile, studentsInDPT); // reads students in DPT
			getline(inFile, teachersInDPT); // reads teachers in DPT
			getline(inFile, blankLine); // eats a blank line
			// creates department object from overloaded constructor
			Department newDepartment(dptName, coursesInDPT, studentsInDPT, teachersInDPT); 
			newMyClass.push_back(newDepartment); // pushes current department object into a vector of dpt objects
		}
	}
	else
		cout << "File not read." << endl;
	inFile.close();
}

int Department::getLines(istream& myFile) {
	int numLines = 0;
    string line;

    while (getline(myFile, line)) { // continues incrementing numLines until EOF
        ++numLines;
	}
    return (numLines+1)/5; // returns the number of departments contained in the file (each dpt is 5 lines long)
}

void Department::printCoursesInDPT(vector<Courses>& courseVector) {
	string myDPT = getDPT(); // gets department for particular index
	string courses = getCoursesDPT(); // gets list of courses based on string read from file
	stringstream ss(courses); // creates a string object copied from our list of courses
	string token; // token to read course names 

	cout << "PRINTING COURSES IN " << myDPT << " DEPARTMENT..." <<endl;
	while (getline(ss, token, ',')) { // reads the complete line, separating each course by the comma delimiter 
		Courses newCourse(token); // creates a Courses object using the default constructor and "token" as the course name
		courseVector.push_back(newCourse); // pushes back the course into our course vector
	}
	for (size_t i = 0; i < courseVector.size(); i++) { // cycles through entire vector
		cout << courseVector[i].getDefault() << endl; // prints the course vector of courses belonging to the DPT
	}
	cout << "*******************************************************************" << endl;
}

void Department::printStudentsInDPT (vector<Student>& studentVector) {
	string myDPT = getDPT(); // gets department for particular index
	string listOfStudents = getStudentsDPT(); // gets list of students based on string read from file
	stringstream ss(listOfStudents); // creates a string object copied from our list of students
	string token; // token to read names 

	cout << "PRINTING STUDENTS IN " << myDPT << " DEPARTMENT..." <<endl;
	while (getline(ss, token, ',')) { // reads the complete line, separating each name by the comma delimiter
		Student newStudent(token);
		studentVector.push_back(newStudent); // pushes back the name into our student vector
	}

	for (size_t i = 0; i < studentVector.size(); i++) { // cycles through entire vector
		cout << studentVector[i].getDefault() << endl; // prints the student vector of names belonging to the DPT
	}
	cout << "*******************************************************************" << endl;	
}

void Department::printTeachersInDPT(vector<Teacher>& teacherVector) {
	string teachers = getTeachersDPT(); // string of teachers read from file
	string myDPT = getDPT(); // gets department for particular index
	stringstream ss(teachers); // creates a string object copied from our list of teachers
	string token; // token to read teacher names 

	cout << "PRINTING TEACHERS IN " << myDPT << " DEPARTMENT..." <<endl;
	while (getline(ss, token, ',')) { // reads the complete line, separating each teacher by the comma delimiter 
		Teacher newTeacher(token); // creates a new teacher object with the current name of teacher
		teacherVector.push_back(newTeacher); // pushes back the names into our teacher vector
	}

	for (size_t i = 0; i < teacherVector.size(); i++) { // cycles through entire vector
		cout << teacherVector[i].getDefault() << endl; // prints the teacher vector of names belonging to the DPT
	}
	cout << "*******************************************************************" << endl;
}

void Department::printDepartmentsInFile(vector<Department>& newMyClass) {
	int size = newMyClass.size();
	cout << "PRINTING DEPARTMENTS FROM FILE..." << endl;
	for (int i = 0; i < size; i++)
		cout << newMyClass[i].getDPT() << endl; // prints only the names of departments from file
	cout << "*******************************************************************" << endl;
}

void Department::printAllDepartments(vector<Department>& newMyClass) {
	int size = newMyClass.size();
	for (int i = 0; i < size; i++) {
		cout << "Department Name: " << newMyClass[i].getDPT() << "\n";
		cout << "Courses Offered: " << newMyClass[i].getCoursesDPT() << "\n";
		cout << "Students in DPT: " << newMyClass[i].getStudentsDPT() << "\n";
		cout << "Teachers in DPT: " << newMyClass[i].getTeachersDPT() << "\n";
		cout << "\n";
	}
}