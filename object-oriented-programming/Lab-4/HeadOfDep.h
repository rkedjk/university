#pragma once
#include "Teacher.h"
#include <iostream>
using namespace std;

class HeadOfDep : public Teacher
{
    Person** zams;
    int zamsCount;
    int zamsCapacity;

    void alloc(int capacity);
public:
    HeadOfDep(const char* name, int year) : Teacher(name, year)
    {
        type = 3;
        zamsCapacity = 0;
        zamsCount = 0;
        alloc(5);
    }
    HeadOfDep(const HeadOfDep& other) = delete;
    HeadOfDep& operator=(const HeadOfDep& other) = delete;
    virtual ~HeadOfDep();
    void addIntern(Person* newIntern);
    void printAboutInterns();
    double getFullPay() const;
    virtual void printAbout() const override;
};
