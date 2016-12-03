/**************************************************************************************************************
 *  Author:  Ashley Suh & Adrian Borrego																      *
 *  Course:  Object oriented Design																		      *
 *  Project: Due 11-27-2016																				      *
 *  File:    Main.cpp -- to test University Admin System													  *
 *																											  *
 *  Each function call has a specific purpose with comments detailing the implementation. The bulk of the     *
 *  work is done in every individual .cpp file. Text files are read and objects are created by pushing them   *
 *  back into a vector, with respect to that class. An object can be created by assigning it to a specific    *
 *  index from the vector, like in line 53 or 58. Student and Teacher are derived from Person. Each student,  *
 *  teacher, and course have a Department. A Department has students, teachers, and courses. Students can be  *
 *  undergradutes or graduates (TA or RA). Teachers can be adjuncts, lecturers, or professors. To save space, *
 *  we have only printed the names of each object from the vector of that class. We have commented out the    *
 *  function call to print all information found from the text file. If needed, uncomment the lines	          *
 *  36, 40, 44, and 48 to view complete information.						                                  *
 **************************************************************************************************************/
#include <iostream> 
#include <vector>   
#include "Student.h"
#include "Teacher.h"
#include "Person.h"
#include "Courses.h"
#include "Department.h"

using namespace std;

int main (void) {
	vector <Student> students, students1, students2; // Creates vectors of Students 
	vector <Teacher> teachers, teachers1, teachers2; // Creates vectors of Teachers
	vector <Department> departments; // Creates a vector of Departments
	vector <Courses> courses, courses1; // Creates vectors of Courses

	Student::createStudent(students); // Creates student objects from Students.txt and pushes into students vector
	Student::printStudentsInFile(students); // Prints the vector of student objects by name only
	/* Student::printAllStudents(students);  PRINTS ALL INFORMATION FROM FILE, REMOVE IF NEEDED TO DISPLAY */
	
	Teacher::createTeacher(teachers); // Creates teacher objects from Teachers.txt and pushes into teachers vector
	Teacher::printTeachersInFile(teachers); // Prints the vector of teacher objects by name only
	/* Teacher::printAllTeachers(teachers);  PRINTS ALL INFORMATION FROM FILE, REMOVE IF NEEDED TO DISPLAY */

	Department::createDepartment(departments); // Creates department objects from Departments.txt and pushes into departments vector
	Department::printDepartmentsInFile(departments); // Prints the vector of department objects by name only
	/* Department::printAllDepartments(departments);  PRINTS ALL INFORMATION FROM FILE, REMOVE IF NEEDED TO DISPLAY */

	Courses::createCourses(courses); // Creates course objects from Courses.txt and pushes into courses vector
	Courses::printCoursesInFile(courses); // Prints the vector of course objects by name only 
	/* Courses::printAllCourses(courses);  PRINTS ALL INFORMATION FROM FILE, REMOVE IF NEEDED TO DISPLAY */
	
	// Specific information about students:
	students[0].printGrades(); // prints the grades for student at index 0
	students[4].degreeType(); // prints the degree type for student at index 4
	Person studentTest = students[1]; // Creates a Student from Person using the information at index 1
	studentTest.printPerson(); // Prints information of Student object through a Person object

	// Specific information about teachers:
	teachers[4].jobType(); // prints the job type for teacher at index 4
	Person teacherTest = teachers[1]; // Creates a Teacher from Person using the information at index 1
	teacherTest.printPerson(); // Prints information of Teacher object through a Person object

	// Specific information about departments:
	departments[2].printStudentsInDPT(students1); // prints the students in department index 2
	departments[1].printTeachersInDPT(teachers1); // prints the teachers in department index 2
	departments[0].printCoursesInDPT(courses1); // prints the courses in department index 2
	
	// Specific information about courses:
	courses[2].printStudentsInCourse(students2); // prints the students enrolled in course index 2
	courses[2].printTeachersInCourse(teachers2); // prints the teachers enrolled in course index 2
	courses[2].printTAsInCourse(); // prints the TAs enrolled in course index 2
	
	std::system("PAUSE");
	return 0;
}