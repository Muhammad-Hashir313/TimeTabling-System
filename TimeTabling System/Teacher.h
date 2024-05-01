#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Course.h"
using namespace std;

class Teacher
{
private:
	int teacherId;
	string teacherName;
	vector<Course> assignedCourses;

public:
	Teacher(int Id, string n)
	{
		teacherName = n;
		teacherId = Id;
	}

	string getTeacherName() { return teacherName; }
	int getId() { return teacherId; }

	void change_name(string n)
	{
		teacherName = n;
	}

	void assignCourse(Course& course)
	{
		assignedCourses.push_back(course);
	}

	void unassignCourse(string courseId)
	{
		for (int i = 0; i < assignedCourses.size(); i++)
		{
			if (assignedCourses[i].getCourseId() == courseId)
			{
				assignedCourses.erase(assignedCourses.begin() + i);
				return;
			}
		}
	}

	void showAssignedCourses()
	{
		cout << "Assigned Courses:\n";
		for (int i = 0; i < assignedCourses.size(); i++)
		{
			if (i == assignedCourses.size() - 1)
			{
				cout << assignedCourses[i].getCourseName() << endl;
			}
			else
			{
				cout << assignedCourses[i].getCourseName() << ", ";
			}
		}
	}
};