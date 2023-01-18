#include "HeadOfDep.h"

void HeadOfDep::alloc(int capacity)
{
    if (capacity <= zamsCapacity) return;
    Person** zamsExtend = new Person * [capacity];
    for (int i = 0; i < zamsCount; ++i) zamsExtend[i] = zams[i];
    if (zamsCount) delete[] zams;
    zams = zamsExtend;
    zamsCapacity = capacity;
}

HeadOfDep::~HeadOfDep()
{
    cout << "dtor HeadOfDep" << endl;
    if (zamsCapacity) delete[] zams;
}

void HeadOfDep::addIntern(Person* newIntern)
{
    if (newIntern->getTypePerson() == 2)
    {
        if (zamsCount == zamsCapacity)
            alloc(zamsCapacity * 2);
        zams[zamsCount++] = newIntern;
    }
    else { cout << newIntern->getFIO() << " - Not a teacher!" << endl; }
}

void HeadOfDep::printAboutInterns()
{
    cout << "Deputies " << zamsCount << " Pieces:" << endl;
    for (int i = 0; i < zamsCount; ++i)
        cout << "Teacher: " << zams[i]->getFIO() << endl;
    cout << endl;
}
double HeadOfDep::getFullPay() const
{
    return Teacher::getFullPay() * 1.6;
}

void HeadOfDep::printAbout() const
{
    cout << "Information about the manager: ";
    Person::printAbout(); cout << "Paid funds: " << getFullPay() << endl;
    Teacher::printSubjects(); cout << endl;
}
