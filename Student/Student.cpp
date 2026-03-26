#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : Person() {
    p.first = 0;
    p.second = 0;
}

Student::Student(int i, string n, double g) : Person(n) {
    p.first = i;
    p.second = g;
}

int Student::getId() const {
    return  p.first;
}

double Student::getGpa() const {
    return p.second;
}

vector<string> Student::getCourses() const {
    return courses;
}

void Student::enrollCourse(string course) {
    courses.push_back(course);
}

bool Student::isCourseEnrolled(string course) {
    for (string c : courses) {
        if (c == course)
            return true;
    }
    return false;
}

void Student::display() {
    cout << "ID: " << p.first
        << " | Name: " << getName()
        << " | GPA: " << p.second << endl;
}