#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "Student.h"
using namespace std;


vector<Student> students;


void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter GPA (0.0 - 4.0): ";
    cin >> gpa;

    if (gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added successfully.\n";
}


void removeStudent() {
    int id;
    cout << "Enter Student ID to remove: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        students.erase(it);
        cout << "Student removed successfully.\n";
    }
    else {
        cout << "Student not found!\n";
    }
}


void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        it->display();
    }
    else {
        cout << "Student not found!\n";
    }
}


void displayAll() {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }
    cout << "\n--- All Students ---\n";
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}


void enrollCourse() {
    int id;
    string course;

    cout << "Enter Student ID: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it == students.end()) {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter Course Name: ";
    cin.ignore();
    getline(cin, course);

    if (it->isCourseEnrolled(course)) {
        cout << "Already enrolled in this course!\n";
    }
    else {
        it->enrollCourse(course);
        cout << "Enrolled successfully.\n";
    }
}


void showCourses() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it == students.end()) {
        cout << "Student not found!\n";
        return;
    }

    vector<string> courses = it->getCourses();
    if (courses.empty()) {
        cout << "No courses enrolled!\n";
        return;
    }

    cout << "\n--- Courses for " << it->getName() << " ---\n";
    for (int i = 0; i < courses.size(); i++) {
        cout << "- " << courses[i] << endl;
    }
}


void sortByGpa() {
    sort(students.begin(), students.end(),
        [](Student& a, Student& b) {
            return a.getGpa() > b.getGpa();
        });

    cout << "\n--- Students Sorted by GPA ---\n";
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}


int main() {
    int choice;

    do {
        cout << "\n===== Student Course Management =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Student in Course\n";
        cout << "6. Show Student Courses\n";
        cout << "7. Sort Students by GPA\n";
        cout << "8. Exit\n";
        cout << "=====================================\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent();    break;
        case 2: removeStudent(); break;
        case 3: searchStudent(); break;
        case 4: displayAll();    break;
        case 5: enrollCourse();  break;
        case 6: showCourses();   break;
        case 7: sortByGpa();     break;
        case 8: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}