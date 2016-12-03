/*******************************************************************************
 *  Author:  Adrian Borrego, Ashley Suh                                        *
 *  Course:  Object oriented Design                                            *
 *  Project: Due 11-23-2016                                                    *
 *  File:    Person.cpp                                                        *
 *  Assigns personal information to students and teachers.                     *
 *******************************************************************************/

#include <iostream>
#include <string>  // for using strings
#include "Person.h"

using namespace std;

Person::Person() { 
} 

Person::Person (string fname, string date, string g, string univID, string classif, string dptN, string courses) {
	uID = univID;
	name = fname;
	dOB = date;
	gender = g;
	type = classif;
	department = dptN;
	courseName = courses;
} // Overloaded constructor

Person::~Person() {
}

void Person::setUID (string id) {
    uID = id;
}

void Person::setName (string first) {
	name = first;
}

void Person::setDOB(string dateOfBirth){
	dOB = dateOfBirth;
}

void Person::setGender (string g) {
    gender = g; 
}

void Person::setType(string job) {
	type = job;
}

void Person::setDepartment(string dep){
	department = dep;
}

void Person::setCourseName(string name){
	courseName = name;
}

string Person::getName() {
	return name;
}

string Person::getGender() {
	return gender;
}

string Person::getUID() {
	return uID;
}

string Person::getCourseName() {
	return courseName;
}

string Person::getDOB() {
	return dOB;
}

string Person::getType() {
	return type;
}

string Person::getDepartment() {
	return department;
}

void Person::printPerson() { // used to print information of a student or teacher object
	cout << "PRINTING OBJECT THROUGH PERSON CLASS..." << endl;
	cout << "Name: " << name << "\n";
	cout << "DOB: " << dOB << "\n";
	cout << "Gender: " << gender << "\n";
	cout << "uID: " << uID << "\n";
	cout << "Type: " << type << "\n";
	cout << "Department: " << department << "\n";
	cout << "Courses Enrolled: " << courseName << "\n";
	cout << "*******************************************************************" << endl;
}
