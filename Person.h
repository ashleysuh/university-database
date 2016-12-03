/*******************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego                                       *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-27-2016                                                    *
 *  File:    Person.h                                                          *
 *  Header for Person class											           *
 *******************************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <istream>

using namespace std;

class Person {	

	public:
		Person(); // regular constructor
		Person(string, string, string, string, string, string, string); // overloaded constructor
		~Person(); // deconstructor
		void setUID(string); // sets the uid for a teacher or student
		void setName(string); // sets the name for a person
		void setDOB(string); // sets the date of birth 
		void setGender(string); // sets the gender for a person
		void setType(string); // sets a student: undergrad or grad --  OR teacher: adject, professor, or lecturer
		void setDepartment(string); // sets the department for a person
		void setCourseName(string); // sets the courses enrolled for a person
		void printPerson(); // print function to print a student or teacher object
		string getName();
		string getGender();
		string getUID();
		string getCourseName();
		string getDOB();
		string getType();
		string getDepartment();

	private:
		string uID; // person's ID
		string name; // person's name
		string dOB; // person's date of birth
		string gender; // person's gender
		string type; // person's classification (job or degree)
		string department; // person's department
		string courseName; // person's courses		
};
#endif