/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Student.cpp                                                       *
 *                                                                             *
 *  Reads from the text file Student.txt. Assigns personal information         *
 *  to students including courses enrolled, graduate level, etc                *
 *******************************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include "Person.h"
using namespace std;

class Student : public Person {	

	public:
		Student(string); // student constructor
		Student(string, string, string, string, string, string, string, string); // overloaded constructor
		~Student(); // deconstructor
		string getGrade(); // returns grades of student
		string getDefault(); // returns default name for composition
		void degreeType(); // prints the level of a student: undergrad, grad: TA or RA
		void printGrades(); // prints grades for a student in each course enrolled
		static void createStudent(vector<Student>&); // creates a student object from file and pushes into a vector of student objects
		static void printStudentsInFile(vector<Student>&); // prints the names of students from vector
		static void printAllStudents(vector<Student>&);  // prints all information of vector from file
		static int getLines(istream&); // counts lines to determine how many student objects to create

	private:
		string grade; // student grade from file
		string defaultName; // default student name
		vector <string> courseVector; // vector of courses student is enrolled in
		vector <string> gradeVector; // vector of grades student has
};
#endif