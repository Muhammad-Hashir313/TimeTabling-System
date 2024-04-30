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

	void change_name(string n) {
		studentName = n;
	}
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

	void change_name(string n) {
		teacherName = n;
	}
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

	string getCourseId() { return courseId; }
	string getCourseName() { return courseName; }

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

	void change_name(string n) {
		courseName = n;
	}
};

class TimetableManager
{
private:
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Course> courses;

public:
	// --------------------- Student Data ---------------------
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

	void updateStudent(int id) {
		for (int i = 0; i < students.size(); i++)
		{
			if (id == students[i].getRNo())
			{
				string name;
				cout << "Enter name of teacher: ";
				cin.ignore();
				getline(cin, name);

				students[i].change_name(name);
				cout << "Name updated successfully";
				system("pause");
				return;
			}
		}
		cout << "Student not found!\n";
		system("pause");
	}

	// --------------------- Teacher Data ---------------------
	void addTeacher()
	{
		string name;
		int id;

		cout << "Enter Teacher Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Teacher Id: ";
		cin >> id;

		Teacher t(id, name);

		teachers.push_back(t);
		cout << "Teacher Added Successfully" << endl;
		system("pause");
	}

	void removeTeacher(int id)
	{
		for (int i = 0; i < teachers.size(); i++)
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

	void showTeachers()
	{
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << "S.No: " << i + 1 << endl;
			cout << "Name: " << teachers[i].getTeacherName() << endl;
			cout << "Id: " << teachers[i].getId() << endl;
			cout << "--------------------\n\n";
		}
	}

	void updateTeacher(int id) {
		for (int i = 0; i < teachers.size(); i++)
		{
			if (id == teachers[i].getId())
			{
				string name;
				cout << "Enter name of teacher: ";
				cin.ignore();
				getline(cin, name);

				teachers[i].change_name(name);
				cout << "Name updated successfully";
				system("pause");
				return;
			}
		}
		cout << "Teacher not found!\n";
		system("pause");
	}

	void assignTeacher(Teacher t, Course c)
	{
		c.addTeacher(t);
		cout << "Teacher assigned successfully!" << endl;
	}

	// --------------------- Course Data ---------------------
	void addCourse()
	{
		string name, id;
		cout << "Enter Course Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Course Id: ";
		cin >> id;

		Course course(id, name);
		courses.push_back(course);
		cout << "Course Added Successfully" << endl;
		system("pause");
	}

	void removeCourse(string id)
	{
		for (int i = 0; i < courses.size(); i++)
		{
			if (id == courses[i].getCourseId())
			{
				courses.erase(courses.begin() + i);
				cout << "Course Removed Successfully" << endl;
				system("pause");
				return;
			}
		}
		cout << "Course Not Found" << endl;
		system("pause");
	}

	void showCourses()
	{
		for (int i = 0; i < courses.size(); i++)
		{
			cout << "S.No: " << i + 1 << endl;
			cout << "Name: " << courses[i].getCourseName() << endl;
			cout << "Id: " << courses[i].getCourseId() << endl;
			cout << "--------------------\n\n";
		}
		system("pause");
	}

	void updateCourse(string id) {
		for (int i = 0; i < courses.size(); i++)
		{
			if (id == courses[i].getCourseId())
			{
				string name;
				cout << "Enter name of course: ";
				cin.ignore();
				getline(cin, name);

				courses[i].change_name(name);
				cout << "Name updated successfully";
				system("pause");
				return;
			}
		}
		cout << "Course not found!\n";
		system("pause");
	}
};

int main()
{
	TimetableManager ttm;
	string name, courseId;
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
					cout << "Enter student id to update: ";
					cin >> id;
					ttm.updateStudent(id);
				}
				else if (choice == '7')
				{
					cout << "You will be transferred back to Main Menu!\n";
					system("pause");
					break;
				}
				else
				{
					cout << "Invalid choice!\n";
				}
			} while (true);
		}
		else if (choice == '2')
		{
			do
			{
				cout << "1. Add Teacher\n";
				cout << "2. Remove Teacher\n";
				cout << "3. Assign Teacher\n";
				cout << "4. UnAssign Teacher\n";
				cout << "5. Show Teachers\n";
				cout << "6. Update Teacher\n";
				cout << "7. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				if (choice == '1')
				{
					ttm.addTeacher();
				}
				else if (choice == '2')
				{
					cout << "Enter Teacher Id to be removed: ";
					cin >> id;
					ttm.removeTeacher(id);
				}
				else if (choice == '3')
				{
					// Do nothing for case '3'
				}
				else if (choice == '4')
				{
					// Do nothing for case '4'
				}
				else if (choice == '5')
				{
					ttm.showTeachers();
				}
				else if (choice == '6')
				{
					cout << "Enter Teacher id to update: ";
					cin >> id;
					ttm.updateTeacher(id);
				}
				else if (choice == '7')
				{
					cout << "You are being transferred to Main Menu!\n";
					system("pause");
					break;
				}
				else
				{
					cout << "Invalid choice!\n";
				}
			} while (true);
		}
		else if (choice == '3')
		{
			do
			{
				cout << "1. Add Course\n";
				cout << "2. Remove Course\n";
				cout << "3. Show Courses\n";
				cout << "4. Update Course\n";
				cout << "5. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				if (choice == '1')
				{
					ttm.addCourse();
				}
				else if (choice == '2')
				{
					cout << "Enter Course Id to be removed: ";
					cin >> courseId;
					ttm.removeCourse(courseId);
				}
				else if (choice == '3')
				{
					ttm.showCourses();
				}
				else if (choice == '4')
				{
					cout << "Enter id of course to update: ";
					cin >> courseId;
					ttm.updateCourse(courseId);
				}
				else if (choice == '5')
				{
					cout << "You are being transferred to Main Menu!\n";
					system("pause");
					break;
				}
				else
				{
					cout << "Invalid choice!\n";
					Sleep(800);
				}

			} while (true);
		}
	} while (true);

	system("pause");
	return 0;
}