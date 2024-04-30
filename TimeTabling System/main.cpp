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
	vector<string> enrolledCourses;

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

	void enrollCourse(string courseId)
	{
		enrolledCourses.push_back(courseId);
	}

	void unenrollCourse(string courseId)
	{
		for (int i = 0; i < enrolledCourses.size(); i++)
		{
			if (enrolledCourses[i] == courseId)
			{
				enrolledCourses.erase(enrolledCourses.begin() + i);
				return;
			}
		}
	}

	void showEnrolledCourses()
	{
		cout << "Enrolled Courses:\n";
		for (const string &courseId : enrolledCourses)
		{
			cout << courseId << endl;
		}
	}
};

class Teacher
{
private:
	int teacherId;
	string teacherName;
	vector<string> assignedCourses;

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

	void assignCourse(string courseId)
	{
		assignedCourses.push_back(courseId);
	}

	void unassignCourse(string courseId)
	{
		for (int i = 0; i < assignedCourses.size(); i++)
		{
			if (assignedCourses[i] == courseId)
			{
				assignedCourses.erase(assignedCourses.begin() + i);
				return;
			}
		}
	}

	void showAssignedCourses()
	{
		cout << "Assigned Courses:\n";
		for (const string &courseId : assignedCourses)
		{
			cout << courseId << endl;
		}
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

	void showStudents()
	{
		for (int i = 0; i < students.size(); i++)
		{
			cout << "S.No: " << i + 1 << endl;
			cout << "Name: " << students[i].getStudentName() << endl;
			cout << "Rollno: " << students[i].getRNo() << endl;
			students[i].showEnrolledCourses();
			cout << "--------------------\n\n";
		}
		system("pause");
	}

	void updateStudent(int id)
	{
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
			teachers[i].showAssignedCourses();
			cout << "--------------------\n\n";
		}
		system("pause");
	}

	void updateTeacher(int id)
	{
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

	void updateCourse(string id)
	{
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

	// ------------------- Assigning and Enrolling ---------------------
	void enrollStudentToCourse()
	{
		int studentId;
		string courseId;

		cout << "Enter Student Id: ";
		cin >> studentId;
		cout << "Enter Course Id: ";
		cin >> courseId;

		Student *student = findStudentById(studentId);
		Course *course = findCourseById(courseId);

		if (student && course)
		{
			enrollStudent(*student, *course);
		}
		else
		{
			cout << "Student or Course not found!" << endl;
		}

		student->enrollCourse(courseId);
	}

	void unenrollStudentFromCourse()
	{
		int studentId;
		string courseId;

		cout << "Enter Student Id: ";
		cin >> studentId;
		cout << "Enter Course Id: ";
		cin >> courseId;

		Student *student = findStudentById(studentId);
		Course *course = findCourseById(courseId);

		if (student && course)
		{
			unenrollStudent(studentId, *course);
		}
		else
		{
			cout << "Student or Course not found!" << endl;
		}

		student->unenrollCourse(courseId);
	}

	void assignTeacherToCourse()
	{
		int teacherId;
		string courseId;

		cout << "Enter Teacher Id: ";
		cin >> teacherId;
		cout << "Enter Course Id: ";
		cin >> courseId;

		Teacher *teacher = findTeacherById(teacherId);
		Course *course = findCourseById(courseId);

		if (teacher && course)
		{
			assignTeacher(*teacher, *course);
		}
		else
		{
			cout << "Teacher or Course not found!" << endl;
		}

		teacher->assignCourse(courseId);
	}

	void unassignTeacherFromCourse()
	{
		int teacherId;
		string courseId;

		cout << "Enter Teacher Id: ";
		cin >> teacherId;
		cout << "Enter Course Id: ";
		cin >> courseId;

		Teacher *teacher = findTeacherById(teacherId);
		Course *course = findCourseById(courseId);

		if (teacher && course)
		{
			unassignTeacher(teacherId, *course);
		}
		else
		{
			cout << "Teacher or Course not found!" << endl;
		}

		teacher->unassignCourse(courseId);
	}

	// Helper functions to find student, teacher, and course
	Student *findStudentById(int id)
	{
		for (auto &student : students)
		{
			if (student.getRNo() == id)
			{
				return &student;
			}
		}
		return nullptr;
	}

	Teacher *findTeacherById(int id)
	{
		for (auto &teacher : teachers)
		{
			if (teacher.getId() == id)
			{
				return &teacher;
			}
		}
		return nullptr;
	}

	Course *findCourseById(const string &id)
	{
		for (auto &course : courses)
		{
			if (course.getCourseId() == id)
			{
				return &course;
			}
		}
		return nullptr;
	}

	void enrollStudent(Student &student, Course &course)
	{
		course.addStudent(student);
		cout << "Student enrolled successfully!" << endl;
		system("pause");
	}

	void unenrollStudent(int studentId, Course &course)
	{
		course.removeStudent(studentId);
		cout << "Student unenrolled successfully!" << endl;
		system("pause");
	}

	void assignTeacher(Teacher &teacher, Course &course)
	{
		course.addTeacher(teacher);
		cout << "Teacher assigned to course successfully!" << endl;
		system("pause");
	}

	void unassignTeacher(int teacherId, Course &course)
	{
		course.removeTeacher(teacherId);
		cout << "Teacher unassigned from course successfully!" << endl;
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
		system("cls");
		cout << "========== UNIVERSITY MANAGEMENT SYSTEM ==========\n"
			 << endl;
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
				system("cls");
				cout << "========== STUDENT PORTAL ==========\n";
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
					system("cls");
					cout << "========== ADD STUDENT ==========\n";
					ttm.addStudent();
				}
				else if (choice == '2')
				{
					system("cls");
					cout << "========== REMOVE STUDENT ==========\n";
					cout << "Enter Student Id to be removed: ";
					cin >> id;
					ttm.removeStudent(id);
				}
				else if (choice == '3')
				{
					system("cls");
					cout << "========== ENROLL STUDENT ==========\n";
					ttm.enrollStudentToCourse();
				}
				else if (choice == '4')
				{
					system("cls");
					cout << "========== UNENROLL STUDENT ==========\n";
					ttm.unenrollStudentFromCourse();
				}
				else if (choice == '5')
				{
					system("cls");
					cout << "========== DISPLAY STUDENT DATA ==========\n";
					ttm.showStudents();
					system("pause");
				}
				else if (choice == '6')
				{
					cout << "========== UPDATE STUDENT ==========\n";
					cout << "Enter student id to update: ";
					cin >> id;
					ttm.updateStudent(id);
				}
				else if (choice == '7')
				{
					cout << "\nYou will be transferred back to Main Menu!\n";
					Sleep(800);
					break;
				}
				else
				{
					cout << "\nInvalid choice!\n";
					Sleep(600);
				}
			} while (true);
		}
		else if (choice == '2')
		{
			do
			{
				system("cls");
				cout << "========== TEACHER PORTAL ==========\n";
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
					system("cls");
					cout << "========== ADD TEACHER ==========\n";
					ttm.addTeacher();
				}
				else if (choice == '2')
				{
					system("cls");
					cout << "========== REMOVE TEACHER ==========\n";
					cout << "Enter Teacher Id to be removed: ";
					cin >> id;
					ttm.removeTeacher(id);
				}
				else if (choice == '3')
				{
					system("cls");
					cout << "========== ASSIGN TEACHER ==========\n";
					ttm.assignTeacherToCourse();
				}
				else if (choice == '4')
				{
					system("cls");
					cout << "========== UNASSIGN TEACHER ==========\n";
					ttm.unassignTeacherFromCourse();
				}
				else if (choice == '5')
				{
					system("cls");
					cout << "========== DISPLAY TEACHER DATA ==========\n";
					ttm.showTeachers();
				}
				else if (choice == '6')
				{
					system("cls");
					cout << "========== UPDATE TEACHER ==========\n";
					cout << "Enter Teacher id to update: ";
					cin >> id;
					ttm.updateTeacher(id);
				}
				else if (choice == '7')
				{
					cout << "\nYou are being transferred to Main Menu!\n";
					Sleep(800);
					break;
				}
				else
				{
					cout << "\nInvalid choice!\n";
					Sleep(600);
				}
			} while (true);
		}
		else if (choice == '3')
		{
			do
			{
				system("cls");
				cout << "========== COURSE PORTAL ==========\n";
				cout << "1. Add Course\n";
				cout << "2. Remove Course\n";
				cout << "3. Show Courses\n";
				cout << "4. Update Course\n";
				cout << "5. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				if (choice == '1')
				{
					system("cls");
					cout << "========== ADD COURSE ==========\n";
					ttm.addCourse();
				}
				else if (choice == '2')
				{
					system("cls");
					cout << "========== REMOVE COURSE ==========\n";
					cout << "Enter Course Id to be removed: ";
					cin >> courseId;
					ttm.removeCourse(courseId);
				}
				else if (choice == '3')
				{
					system("cls");
					cout << "========== SHOW COURSES ==========\n";
					ttm.showCourses();
				}
				else if (choice == '4')
				{
					system("cls");
					cout << "========== UPDATE COURSE ==========\n";
					cout << "Enter id of course to update: ";
					cin >> courseId;
					ttm.updateCourse(courseId);
				}
				else if (choice == '5')
				{
					cout << "\nYou are being transferred to Main Menu!\n";
					Sleep(800);
					break;
				}
				else
				{
					cout << "\nInvalid choice!\n";
					Sleep(600);
				}

			} while (true);
		}
		else if (choice == '4')
		{
			cout << "Good Bye\n";
			exit(1);
		}
		else
		{
			cout << "Invalid Choice!\n";
			Sleep(600);
		}
	} while (true);

	system("pause");
	return 0;
}