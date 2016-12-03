/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Department.h                                                      *
 *  Header for Department class											       *
 *******************************************************************************/

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include "Courses.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Department {
	public:
		Department();
		Department(string, string, string, string);
		~Department();
		string getDPT(); 
		string getCoursesDPT();
		string getStudentsDPT();
		string getTeachersDPT();
		void printCoursesInDPT(vector<Courses>&); // prints courses offered for a particular department
		void printStudentsInDPT(vector<Student>&); // prints students belonging to a particular department
		void printTeachersInDPT(vector<Teacher>&); // prints teachers working for a particular department
		static void createDepartment(vector<Department>&); // creates a vector of department objects
		static void printDepartmentsInFile(vector<Department>&); // prints the name of department objects
		static void printAllDepartments(vector<Department>&); // prints entire vector of department objects
		static int getLines(istream&); // counts how many department objects to create from file

	private:
		string dptName; // department name
		string crseDPT; // course name
		string stdsDPT; // students in dept
		string teachDPT; // teachers in dept
		vector<Student> studentVector; // vector of students in a department
		vector<Courses> courseList; // vector of courses in a department
		vector<Teacher> teacherVector; // vector of teachers in a department
};
#endif