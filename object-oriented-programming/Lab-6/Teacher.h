#pragma once
#include "Human.h"
#include <iostream>
using namespace std;

class Teacher : public Human
{
	int subjects[MAX_SUBJECTS];

protected:
	void printSubjects() const; // print subjects
public:
	Teacher(const char *fio, unsigned short yearBirth) : Human(fio, yearBirth), subjects{}
	{
		type = H_Types::TEACH;
	}
	virtual ~Teacher();							   // destruct teacher
	void setValue(int subjectId, int subjectHour); // set value
	int getSubject(int subjectId) const;		   // getting subject
	float getFullPay() const;					   // getting salary
	void printAbout() const override;
};
