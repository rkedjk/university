#pragma once
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "HeadOfDep.h"
#include "Researcher.h"
#include <iostream>
using namespace std;

class University
{
    int facultyCount;
    int facultyCapacity = 0;
    Person** faculty = new Person * [facultyCapacity];
    void alloc(int capacity);
public:
    University();
    University(const University& other) = delete;
    University& operator=(const University& other) = delete;
    ~University();
    void addPersons(const char* fio, int yearBirth, int type);
    void removePersonID(int id);
    void removePersons();
    Person* getPersons(int i);
    Person* getPersonID(int id);
    bool checkPersonID(int id);
    int getFacultyCount();
    void printAboutPerson(int k);
};
