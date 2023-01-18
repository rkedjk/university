#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class Student : public Person
{
    int grades[MAX_SUBJECTS];
    void printGrades() const;
public:
    Student(const char* name, int year) : Person(name, year)
    {
        type = 1;
        memset(&grades, 0, MAX_SUBJECTS * sizeof(int));
    }
    ~Student();
    void setValue(int subjectId, int value);
    double getFullPay() const;
    void printAbout() const override;
};
