#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class Teacher : public Person
{
	int subjects[MAX_SUBJECTS];
protected:
	void printSubjects() const;
public:
	Teacher(const char* name, int year) : Person(name, year), subjects{}
	{
		type = 2;
	}
	virtual ~Teacher();
	void setValue(int subjectId, int subjectHour);
	int getSubject(int subjectId) const;
	double getFullPay() const;
	void printAbout() const override;
};
