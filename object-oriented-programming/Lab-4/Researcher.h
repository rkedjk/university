#pragma once
#include "Teacher.h"
#include <iostream>
using namespace std;

class Researcher : public Teacher
{
    Person** studs;
    int studsCount;
    int studsCapacity;

    void alloc(int capacity);
public:
    Researcher(const char* name, int year) : Teacher(name, year)
    {
        type = 4;
        studsCapacity = 0;
        studsCount = 0;
        alloc(5);
    }
    Researcher(const Researcher& other) = delete;
    Researcher& operator=(const Researcher& other) = delete;
    virtual ~Researcher();
    void addIntern(Person* newIntern);
    void printAboutInterns();
    double getFullPay() const;
    virtual void printAbout() const override;
};
