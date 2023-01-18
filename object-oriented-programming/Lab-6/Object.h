#pragma once
#include <iostream>
using namespace std;

class Exception
{
	const char *info;

public:
	Exception(const char *info) : info(info) {}
	const char *getInfo() { return info; }
};

class Object
{
public:
	virtual ~Object() { cout << "dtor Object" << endl; } // virtual dstrcr
	virtual void printAbout() const = 0;				 // Print about object
};