#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Student.h"
#include "Teacher.h"
using namespace std;

class Course
{
private:
	string courseName, courseId;
	vector<Student> students;
	vector<Teacher> teachers;

public:
	Course(string Id, string n)
	{
		courseName = n;
		courseId = Id;
	}

	string getCourseId() { return courseId; }
	string getCourseName() { return courseName; }

	void addStudent(Student& s)
	{
		students.push_back(s);
	}

	void removeStudent(int id)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i].getRNo() == id)
			{
				students.erase(students.begin() + i);
				return;
			}
		}
		cout << "Student Not found!" << endl;
	}

	void addTeacher(Teacher t)
	{
		teachers.push_back(t);
	}

	void removeTeacher(int id)
	{
		for (int i = 0; i < teachers.size(); i++)
		{
			if (teachers[i].getId() == id)
			{
				teachers.erase(teachers.begin() + i);
				return;
			}
		}
		cout << "Teacher Not found!" << endl;
	}

	void change_name(string n)
	{
		courseName = n;
	}
};