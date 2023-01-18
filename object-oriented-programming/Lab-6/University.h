#pragma once
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "HeadTeacher.h"
#include "Research.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class University
{
private:
	vector<Human *> fac;		  // vector STL Human
	vector<Human *>::iterator it; // iterator STL
	int facultyCount;			  // Count of faculty
	float sumMoney = 0;			  // sum money

	int maxArrayIndex(int length, int *arr); // Max Array index
	int minArrayIndex(int length, int *arr); // Min array index
	int random(int min, int max);			 // Random generation
	void PeremeshivanieMassiva(int m[], int size);

public:
	University(); // Construct copy
	University(const University &other) = delete;
	University &operator=(const University &other) = delete;
	~University();												  // Distructy University
	void addHumans(const char *fio, int yearBirth, H_Types type); // adding humans
	void addHumans(const char *fio, int yearBirth, int type);	  // adding humans
	void addRandomHumans(int N);
	void removeHumanID(int id); // remove humanID
	void removeHumans();		// remuve humans
	Human *getHumans(int i);	// getting humans
	Human *getHumanID(int id);	// get ID
	bool checkHumanID(int id);	// check id
	int getFacultyCount();
	float allMoney();
	void avgMoney();
	void CompAge();
	void printAboutHuman(int k);
};