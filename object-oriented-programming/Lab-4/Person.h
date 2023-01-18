#pragma once
#include "Object.h"
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

#define MAX_SUBJECTS 10
#define MAX_STR 256
#define VALID_SUBJ(subjectID) (subjectID >= 0 && subjectID <= MAX_SUBJECTS - 1)
#define VALID_GRADE(grade) (grade >= 0 && grade <= 5)

class Student; class Teacher;

class Person : public Object
{
    char fio[MAX_STR];
    int yearBirth;
    int basicPay = 5000;
    static int nextId;
    int numb_id;
protected:
    int type;
public:
    Person(const char* name, int year) : yearBirth(year)
    {
        numb_id = nextId++;
        strcpy(this->fio, name);
    }
    Person(const char* name);
    ~Person();
    const char* getFIO() const;
    int getBasicPay() const;
    int getId() const;
    int getTypePerson() const;
    int getYearBT() const;
    int getAge() const;
    /*virtual*/ void printAbout() const override;
    virtual void printAboutInterns();
    virtual double getFullPay() const;
    virtual void addIntern(Person* newIntern);
    virtual void setValue(int subjectId, int value);
    virtual int geValue(int subjectId) const;
};
