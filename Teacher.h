/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Teacher.h                                                         *
 *  Header for Teacher class										           *
 *******************************************************************************/

#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include "Person.h"
using namespace std;

class Teacher : public Person {
	public:
		Teacher(string); // teacher constructor
		Teacher(string, string, string, string, string, string, string); // overloaded constructor to create teacher objects
		~Teacher(); // deconstructor
		string getDefault(); // returns the defaultName from default constructor
		void jobType(); // prints whether teacher is an adjunct, lecturer, or professor
		static void createTeacher(vector<Teacher>&); // creates teacher objects from file and pushes them into a vector
		static void printTeachersInFile(vector<Teacher>&); // prints the names of teachers from the vector
		static void printAllTeachers(vector<Teacher>&); // prints all information of vector from file
		static int getLines(istream&); // counts lines to determine how many teacher objects to create
	private:
		string defaultName;
};
#endif