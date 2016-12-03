/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Courses.h                                                         *
 *  Header for Courses class						       *
 *******************************************************************************/

#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Courses {
	public:
		Courses(string); // constructor
		Courses(string, string, string, string, string); // overloaded constructor to create course objects
		~Courses(); // deconstructor
		string getTA(); // returns the TA for a course
		string getCourseN(); // returns the course name
		string getDptN(); // returns department name
		string getStuN(); // returns students enrolled
		string getTeaN(); // returns teachers enrolled
		string getDefault();
		void printStudentsInCourse(vector<Student>&); // pushes students enrolled into a vector to print
		void printTeachersInCourse(vector<Teacher>&); // pushes teachers enrolled into a vector to print
		void printTAsInCourse(); // pushes ta's enrolled into a vector to print
		static void createCourses(vector<Courses>&); // creates course objects and pushes into a vector of courses
		static void printAllCourses(vector<Courses>&); // prints the name of course objects from file
		static void printCoursesInFile(vector<Courses>&); // prints all information of course vector
		static int getLines(istream&); // counts the lines to create appropriate course objects

	private:
		string TA; // TA name
		string courseName; // course name 
		string defaultCourse;
		string dptName; // department name
		string studentsEnr; // students enrolled
		string teachersEnr; // teachers enrolled
		vector<Student> studentVector;
		vector<Teacher> teacherVector;
		vector<string> taVector; // vector of TAs enrolled
};
#endif
