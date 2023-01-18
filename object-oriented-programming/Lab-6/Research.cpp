#include "Research.h"

Research::~Research() // distruct Research
{
    cout << "dtor Research" << endl;
    studs.clear();
}

void Research::addMinien(Human *newMinien) // Adding Minien
{
    if (newMinien->getTypeHuman() == H_Types::STUD)
    {
        studs.push_back(newMinien);
    }
    else
    {
        cout << newMinien->getFIO() << " - Not a student!" << endl;
        throw Exception("Invalid entity type.");
    }
}

void Research::printAboutMiniens() // print about Miniens
{
    if (studs.empty())
        throw Exception("There are no interns.");
    st = studs.begin();
    cout << "Student interns " << studs.size() << " pieces:" << endl;
    for (st = studs.begin(); st != studs.end(); ++st)
        cout << "Student: " << (*st)->getFIO() << endl;
    cout << endl;
}

float Research::getFullPay() const // Get full Pay
{
    return Teacher::getFullPay() * 0.05;
}

void Research::printAbout() const // Print about
{
    cout << "Information about a researcher: ";
    Human::printAbout();
    cout << "Cash to be paid: " << getFullPay() << endl;
    Teacher::printSubjects();
    cout << endl;
}
