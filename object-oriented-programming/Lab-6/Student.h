#pragma once
#include "Human.h"
#include <iostream>
using namespace std;

class Student : public Human
{
    int grades[MAX_SUBJECTS];
    void printGrades() const; // print grades
public:
    Student(const char *fio, int yearBirth) : Human(fio, yearBirth) // student construct
    {
        type = H_Types::STUD;
        memset(&grades, 0, MAX_SUBJECTS * sizeof(int));
    }
    ~Student(); // student destruct
    void setValue(int subjectId, int value);
    float getFullPay() const;
    void printAbout() const override;
};
