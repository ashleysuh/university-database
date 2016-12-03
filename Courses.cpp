/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Courses.cpp                                                       *
 *                                                                             *
 *  Reads from the text file Courses.txt. Assigns information specific         *
 *  to a course including students enrolled, department, etc                   *
 *******************************************************************************/

#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Courses.h"

using namespace std;

/* The way Courses.txt should be read:
	Course Name: COURSE_NAME
	Department Name: DEPARTMENT_NAME
	Students Enrolled: STUDENTS_ENROLLED
	Teachers Enrolled: TEACHERS_ENROLLED
	TAs Enrolled: TAs_ENROLLED
*/

Courses::Courses(string cn) {
	defaultCourse = cn;
}

Courses::Courses(string cName, string dName, string sName, string tName, string taName) {
	courseName = cName;
	dptName = dName;
	studentsEnr = sName;
	teachersEnr = tName;
	TA = taName;
} // Overloaded constructor

string Courses::getDefault() {
	return defaultCourse;
}

Courses::~Courses() {
}

string Courses::getTA() {
	return TA;
}

string Courses::getCourseN() {
	return courseName;
}

string Courses::getDptN() {
	return dptName;
}

string Courses::getStuN() {
	return studentsEnr;
}

string Courses::getTeaN() {
	return teachersEnr;
}

int Courses::getLines(istream& myFile) {
	int numLines = 0; 
	string line;

	while (getline(myFile, line)) { 
		++numLines; // increments numLines each time a line is read from the file
	}
	return (numLines+1)/6; // returns the # of course objects to create (each course is 6 lines long)
}

void Courses::createCourses(vector<Courses>& newMyClass) {
	ifstream inFile;
	string cn, dn, sn, tn, ta, bl;

	inFile.open("Courses.txt");
	int numCourses = getLines(inFile);
	inFile.close();

	inFile.open("Courses.txt");
	if (inFile.good()) {
		for (int i = 0; i < numCourses; i++) {
			getline(inFile, cn); // read course name
			getline(inFile, dn); // read department name
			getline(inFile, sn); // read students enrolled
			getline(inFile, tn); // read teachers enrolled
			getline(inFile, ta); // read TA 
			getline(inFile, bl); // read blank line
			Courses newCourse(cn, dn, sn, tn, ta); // creates a course object using overloaded constructor
			newMyClass.push_back(newCourse); // pushes current course object into a vector
		}
	}
	else
		cout << "File not read." << endl;
	inFile.close();
}

void Courses::printStudentsInCourse(vector<Student>& studentVector) {
	string myCourse = getCourseN(); // gets course name for particular index
	string listOfStudents = getStuN(); // gets the string of students enrolled
	stringstream ss(listOfStudents); // ss splits the line of students enrolled
	string token; // token to read line

	cout << "PRINTING STUDENTS ENROLLED IN " << myCourse << "..." << endl;
	while (getline(ss, token, ',')) { // uses ',' as a delimiter to separate each student
		Student newStudent(token); // creates student object with teacher name as default argument
		studentVector.push_back(newStudent); // pushes teacher object (with name) enrolled into a vector 
	}

	for (size_t i = 0; i < studentVector.size(); i++) {
		cout << studentVector[i].getDefault() << endl; // prints the students enrolled 
	}
	cout << "*******************************************************************" << endl;
}

void Courses::printTeachersInCourse(vector<Teacher>& teacherVector) {
	string teachers = getTeaN(); // gets string of teachers enrolled from file
	string myCourse = getCourseN(); // gets particular course name from index
	stringstream ss(teachers); // to split string of teachers
	string token; // to read the line

	cout << "PRINTING TEACHERS ENROLLED IN " << myCourse << "..." << endl;
	while (getline(ss, token, ',')) { // uses ',' to separate each teacher
		Teacher newTeacher(token); // creates teacher object with teacher name as default argument
		teacherVector.push_back(newTeacher); // pushes teacher object (with name) into the vector
	}

	for (size_t i = 0; i < teacherVector.size(); i++) {
		cout << teacherVector[i].getDefault() << endl; // prints vector of teachers
	}
	cout << "*******************************************************************" << endl;
}

void Courses::printTAsInCourse() {
	string TAs = getTA(); // gets the TAs enrolled for particular course
	string myCourse = getCourseN(); // gets the name for particular course
	stringstream ss(TAs); // to split if multiple TAs occur
	string token; // to read the line

	cout << "PRINTING TAs ENROLLED IN " << myCourse << "..." << endl;
	while (getline(ss, token, ',')) { // uses ',' to separate each TA
		taVector.push_back(token); // pushes TA instance into vector
	}

	for (size_t i = 0; i < taVector.size(); i++)
		cout << taVector.at(i) << endl; // prints TA for a course
	cout << "*******************************************************************" << endl;
}

void Courses::printCoursesInFile(vector<Courses>& newMyClass) {
	int size = newMyClass.size(); // size of course vector created
	cout << "PRINTING COURSES FROM FILE..." << endl;
	for (int i = 0; i < size; i++)  
		cout << newMyClass[i].getCourseN() << endl; // prints just the names of courses in file
	cout << "*******************************************************************" << endl;
}

void Courses::printAllCourses(vector<Courses>& newMyClass) {
	int size = newMyClass.size();
	for (int i = 0; i < size; i++) {
		// print name of course
		cout << "Course Name: " << newMyClass[i].getCourseN() << endl;
		// print dpt name for course
		cout << "Department for Course: " << newMyClass[i].getDptN() << endl;
		// print students enrolled
		cout << "Students Enrolled: " << newMyClass[i].getStuN() << endl;
		// print teachers enrolled
		cout << "Teachers for Course: " << newMyClass[i].getTeaN() << endl;
		// print tas in course
		cout << "TAs for Course: " << newMyClass[i].getTA() << endl;
		cout << "\n";
	}
}