#include "HeadTeacher.h"

HeadTeacher::~HeadTeacher() // distruct HT
{
    cout << "dtor HeadTeacher" << endl;
    zams.clear();
}

void HeadTeacher::addMinien(Human *newMinien) // Addoing Minien
{
    if (newMinien->getTypeHuman() == H_Types::TEACH)
    {
        zams.push_back(newMinien);
    }
    else
    {
        cout << newMinien->getFIO() << " - Not a teacher!" << endl;
        throw Exception("Invalid entity type.");
    }
}

void HeadTeacher::printAboutMiniens() // Print info
{
    if (zams.empty())
        throw Exception("There are no deputies.");
    zt = zams.begin();
    cout << "Deputies " << zams.size() << " pieces:" << endl;
    for (zt = zams.begin(); zt != zams.end(); ++zt)
        cout << "Teacher: " << (*zt)->getFIO() << endl;
    cout << endl;
}

float HeadTeacher::getFullPay() const // Getting full salary
{
    return Teacher::getFullPay() * 1.6;
}

void HeadTeacher::printAbout() const // Print About
{
    cout << "Information about the manager: ";
    Human::printAbout();
    cout << "Paid funds: " << getFullPay() << endl;
    Teacher::printSubjects();
    cout << endl;
}
