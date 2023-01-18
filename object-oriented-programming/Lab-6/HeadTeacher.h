#pragma once
#include "Teacher.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class HeadTeacher : public Teacher
{
    vector<Human *> zams;         // Vector STL Human
    vector<Human *>::iterator zt; // Vector STL Iterator
    int zamsCount;                // Count of zams
public:
    HeadTeacher(const char *fio, unsigned short yearBirth) : Teacher(fio, yearBirth) // Construct HT
    {
        type = H_Types::H_TEACH;
        zamsCount = 0;
    }
    HeadTeacher(const HeadTeacher &other) = delete;            // Construct copy delete
    HeadTeacher &operator=(const HeadTeacher &other) = delete; // Operator = delete
    virtual ~HeadTeacher();                                    // distruct HT
    void addMinien(Human *newMinien);                          // Addoing Minien
    void printAboutMiniens();                                  // Print info
    float getFullPay() const;                                  // Getting full salary
    virtual void printAbout() const override;                  // Print About
};
