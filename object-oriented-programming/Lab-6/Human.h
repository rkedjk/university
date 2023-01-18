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

enum class H_Types
{
    STUD,
    TEACH,
    H_TEACH,
    RESEARCH
};

class Student;
class Teacher;

class Human : public Object
{
    char fio[MAX_STR];   // Last name first name
    int yearBirth;       // Year of birth
    int basicPay = 5000; // Basic salary
    static int nextId;   // Static id
    int numb_id;         // Number of id
protected:
    H_Types type; // Type of Entities
public:
    Human(const char *fio, int yearBirth) : yearBirth(yearBirth) // Construct basic class
    {
        numb_id = nextId++;
        strcpy(this->fio, fio);
    }
    Human(const char *fio);       // Construct bas class
    ~Human();                     // distruct class
    const char *getFIO() const;   // getting Last name first name
    int getBasicPay() const;      // getting salary
    int getId() const;            // getting ID
    H_Types getTypeHuman() const; // getting type of human
    int getYearBT() const;        // getting year of birth
    int getAge() const;
    void printAbout() const override; // print info
    virtual void printAboutMiniens();
    virtual float getFullPay() const;         // getting full pay
    virtual void addMinien(Human *newMinien); // adding human
    virtual void setValue(int subjectId, int value);
    virtual int geValue(int subjectId) const;
};
