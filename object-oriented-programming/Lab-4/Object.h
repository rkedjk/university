#pragma once
#include <iostream>
using namespace std;

class Object
{
public:
	virtual ~Object() { cout << "dtor Object" << endl; }	//virtual dstrcr
	virtual void printAbout() const = 0;					//Print about object
};
