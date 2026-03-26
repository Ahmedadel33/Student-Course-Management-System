#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Student : public Person {
private:
  /*  int id;
    double gpa;*/
    pair<int, double>p;
    vector<string> courses;

public:
    Student();
    Student(int i, string n, double g);

    int getId() const;
    double getGpa() const;
    vector<string> getCourses() const;

    void enrollCourse(string course);
    bool isCourseEnrolled(string course);
    void display();
};

#endif