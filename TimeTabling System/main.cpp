#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student{
private:
	int rollno;
	string studentName;

public:
	Student(int r, string n) {
		studentName = n;
		rollno = r;
	}

	string getStudentName() { return studentName; }
	int getRNo() { return rollno; }
};

class Teacher{
private:
	int teacherId;
	string teacherName;

public:
	Teacher(int Id, string n) {
		teacherName = n;
		teacherId = Id;
	}
};

class Course {
private:
	string courseName, courseId;
	vector<Student> students;
	vector<Teacher> teachers;

public:
	Course(string n, string Id) {
		courseName = n;
		courseId = Id;
	}

	void addStudent(Student s) {
		students.push_back(s);
	}

	void addTeacher(Teacher t) {
		teachers.push_back(t);
	}
};

class TimetableManager {
private:
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Course> courses;

public:
	void addCourse() {
		string name, id;
		cout << "Enter Course Name: ";
		getline(cin, name);
		cin.ignore();
		cout << "Enter Course Id: ";
		cin >> id;

		Course course(name, id);
		courses.push_back(course);
	}
};

int main() {


	system("pause");
	return 0;
}