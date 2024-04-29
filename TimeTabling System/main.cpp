#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class Student
{
private:
	int rollno;
	string studentName;

public:
	Student(int r, string n)
	{
		studentName = n;
		rollno = r;
	}

	string getStudentName() { return studentName; }
	int getRNo() { return rollno; }
};

class Teacher
{
private:
	int teacherId;
	string teacherName;

public:
	Teacher(int Id, string n)
	{
		teacherName = n;
		teacherId = Id;
	}

	string getTeacherName() { return teacherName; }
	int getId() { return teacherId; }
};

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

	void addStudent(Student s)
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
};

class TimetableManager
{
private:
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Course> courses;

public:
	// Student Data
	void addStudent()
	{
		string name;
		int rollno;
		cout << "Enter Student Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Student Id: ";
		cin >> rollno;

		Student s(rollno, name);
		students.push_back(s);
		cout << "Student Added Successfully" << endl;
		system("pause");
	}

	void removeStudent(int id)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (id == students[i].getRNo())
			{
				students.erase(students.begin() + i);
				cout << "Student Removed Successfully" << endl;
				system("pause");
				return;
			}
		}
		cout << "Student Not Found" << endl;
		system("pause");
	}

	void enrollStudent(Student s, Course c)
	{
		c.addStudent(s);
		cout << "Student enrolled successfully!" << endl;
	}

	void UnEnrollStudent(int id, Course c)
	{
		c.removeStudent(id);
		cout << "Student unenrolled successfully!" << endl;
		system("pause");
	}

	void showStudents()
	{
		for (int i = 0; i < students.size(); i++)
		{
			cout << "S.No: " << i + 1 << endl;
			cout << "Name: " << students[i].getStudentName() << endl;
			cout << "Rollno: " << students[i].getRNo() << endl;
			cout << "--------------------\n\n";
		}
	}

	// Teacher Data
	void addTeacher(Teacher t)
	{
		teachers.push_back(t);
		cout << "Teacher Added Successfully" << endl;
		system("pause");
	}

	void removeTeacher(int id)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (id == teachers[i].getId())
			{
				teachers.erase(teachers.begin() + i);
				cout << "Teacher Removed Successfully" << endl;
				system("pause");
				return;
			}
		}
		cout << "Teacher Not Found" << endl;
		system("pause");
	}

	// Course Data
	void addCourse()
	{
		string name, id;
		cout << "Enter Course Name: ";
		getline(cin, name);
		cin.ignore();
		cout << "Enter Course Id: ";
		cin >> id;

		Course course(name, id);
		courses.push_back(course);
	}

	void assignTeacher(Teacher t, Course c)
	{
		c.addTeacher(t);
		cout << "Teacher assigned successfully!" << endl;
	}
};

int main()
{
	TimetableManager ttm;
	string name, courseid;
	int id;
	char choice;

	do
	{

		cout << "========== University TimeTable Manager ==========" << endl;
		cout << "1. Student\n";
		cout << "2. Teacher\n";
		cout << "3. Course\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == '1')
		{
			do
			{

				cout << "1. Add Student\n";
				cout << "2. Remove Student\n";
				cout << "3. Enroll Student\n";
				cout << "4. Un-Enroll Student\n";
				cout << "5. Show Students\n";
				cout << "6. Update Student\n";
				cout << "7. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				if (choice == '1')
				{
					ttm.addStudent();
				}
				else if (choice == '2')
				{
					cout << "Enter Student Id to be removed: ";
					cin >> id;
					ttm.removeStudent(id);
				}
				else if (choice == '3')
				{
					cout << "Enroll\n";
				}
				else if (choice == '4')
				{
					cout << "UnEnroll\n";
				}
				else if (choice == '5')
				{
					ttm.showStudents();
					system("pause");
				}
				else if (choice == '6')
				{
					cout << "Update\n";
				}
				else if (choice == '7')
				{
					cout << "You are being transferred back to Menu!\n";
					system("pause");
					break;
				}
				else
				{
					cout << "Invalid choice!\n";
				}
			} while (true);
		}
	} while (true);
	system("pause");
	return 0;
}