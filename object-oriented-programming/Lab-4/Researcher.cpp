#include "Researcher.h"

void Researcher::alloc(int capacity)
{
    if (capacity <= studsCapacity) return;
    Person** studsExtend = new Person * [capacity];
    for (int i = 0; i < studsCount; ++i) studsExtend[i] = studs[i];
    if (studsCount) delete[] studs;
    studs = studsExtend;
    studsCapacity = capacity;
}

Researcher::~Researcher()
{
    cout << "dtor Researcher" << endl;
    if (studsCapacity) delete[] studs;
}

void Researcher::addIntern(Person* newIntern)
{
    if (newIntern->getTypePerson() == 1)
    {
        if (studsCount == studsCapacity)
            alloc(studsCapacity * 2);
        studs[studsCount++] = newIntern;
    }
    else { cout << newIntern->getFIO() << " - Not a student!" << endl; }
}

void Researcher::printAboutInterns()
{
    cout << "Student trainees " << studsCount << " pieces:" << endl;
    for (int i = 0; i < studsCount; ++i) cout << "Student: " << studs[i]->getFIO() << endl;
}

double Researcher::getFullPay() const
{
    return Teacher::getFullPay() * 0.05;
}

void Researcher::printAbout() const
{
    cout << "Information about a Researcherer: ";
    Person::printAbout();
    cout << "Cash to be paid: " << getFullPay() << endl;
    Teacher::printSubjects(); cout << endl;
}
