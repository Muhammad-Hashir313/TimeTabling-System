#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Course.h"
using namespace std;

class Student
{
private:
	int rollno;
	string studentName;
	vector<Course> enrolledCourses;

public:
	Student(int r, string n)
	{
		studentName = n;
		rollno = r;
	}

	string getStudentName() { return studentName; }
	int getRNo() { return rollno; }

	void change_name(string n)
	{
		studentName = n;
	}

	void enrollCourse(Course& course)
	{
		enrolledCourses.push_back(course);
	}

	void unenrollCourse(string courseId)
	{
		for (int i = 0; i < enrolledCourses.size(); i++)
		{
			if (enrolledCourses[i].getCourseId() == courseId)
			{
				enrolledCourses.erase(enrolledCourses.begin() + i);
				return;
			}
		}
	}

	void showEnrolledCourses()
	{
		cout << "Enrolled Courses:\n";
		for (int i = 0; i < enrolledCourses.size(); i++)
		{
			if (i == enrolledCourses.size() - 1)
			{
				cout << enrolledCourses[i].getCourseName() << endl;
			}
			else
			{
				cout << enrolledCourses[i].getCourseName() << ", ";
			}
		}
	}
};