#pragma once
#include <cstring>
#include <iostream>
#include <string>

class Object
{

public:
    static int activeObjects;
    static int overallObjects;

    int operationsCount;
    char **operations;

    Object();
	Object(const Object& obj);
	Object& operator=(const Object& obj);
	~Object();


    void addOp(const char *Operation);

    void clearOp();

    void printOp();

    void printTotalInfo();

    static void objectsCountInc()
    {
        activeObjects++;
        overallObjects++;
    };

    static void objectsCountDec()
    {
        activeObjects--;
    }

    static int getActiveCount(){return activeObjects;};

    static int getOverallCount(){return overallObjects;};
};