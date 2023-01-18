#pragma once
#include "Teacher.h"
#include <iostream>
#include <vector>
using namespace std;

class Research : public Teacher
{
    vector<Human *> studs;        // Vector STL studs
    vector<Human *>::iterator st; // STL iterator
    int studsCount;               // Count sudents
public:
    Research(const char *fio, unsigned short yearBirth) : Teacher(fio, yearBirth) // Construct Research
    {
        type = H_Types::RESEARCH;
        studsCount = 0;
    }
    Research(const Research &other) = delete;            // delete constr copy
    Research &operator=(const Research &other) = delete; // delete operator =
    virtual ~Research();                                 // distruct research
    void addMinien(Human *newMinien) override;           // Adding Minien
    void printAboutMiniens();                            // Print about miniens
    float getFullPay() const override;                   // getting full pay
    virtual void printAbout() const override;            // print about
};
