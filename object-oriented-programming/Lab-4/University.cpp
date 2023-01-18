#include "University.h"

void University::alloc(int capacity)
{
    if (capacity <= facultyCapacity) return;
    Person** facultyExtend = new Person * [capacity];
    for (int i = 0; i < facultyCount; ++i) facultyExtend[i] = faculty[i];
    delete[] faculty;
    faculty = facultyExtend;
    facultyCapacity = capacity;
}
University::University()
{
    facultyCount = 0;
    alloc(30);
}


University::~University()
{
    if (facultyCapacity) delete[] faculty;
}

void University::addPersons(const char* fio, int yearBirth, int type)
{
    if (facultyCount == facultyCapacity)
        alloc(facultyCapacity * 2);
    if (type == 1) faculty[facultyCount] = new Student(fio, yearBirth);
    if (type == 2) faculty[facultyCount] = new Teacher(fio, yearBirth);
    if (type == 3) faculty[facultyCount] = new HeadOfDep(fio, yearBirth);
    if (type == 4) faculty[facultyCount] = new Researcher(fio, yearBirth);
    facultyCount += 1;
}
void University::removePersonID(int id)
{
    for (int i = 0; i < facultyCount; ++i)
    {
        if (id == faculty[i]->getId())
        {
            delete faculty[i];
            for (int j = i + 1; j < facultyCount; ++j) faculty[j - 1] = faculty[j];
            --facultyCount;
            return;
        }
    }
    cout << "Couldn't delete find an entity with this ID..." << endl;
}
void University::removePersons()
{
    for (int i = 0; i < facultyCount; ++i)
    {
        delete faculty[i];
        for (int j = i + 1; j < facultyCount; ++j) faculty[j - 1] = faculty[j];
        --facultyCount;
        return;
    }
}


Person* University::getPersonID(int id)
{
    for (int i = 0; i < facultyCount; ++i)
    {
        if (id == faculty[i]->getId()) { return faculty[i]; }
    }
    cout << "Couldn't delete find an entity with this ID..." << endl;
    return(NULL);
}



bool University::checkPersonID(int id)
{
    for (int i = 0; i < facultyCount; ++i)
    {
        if (id == faculty[i]->getId()) return true;
        return false;
    }
    return(NULL);
}


    Person* University::getPersons(int i) { return faculty[i]; }
    int University::getFacultyCount() { return facultyCount; }
    void University::printAboutPerson(int k)
    {
        string tName;
        cout << "The university consists of " << facultyCount << " personalities:" << endl;
        for (int i = 0; i < facultyCount; ++i)
        {
            if (faculty[i]->getTypePerson() == 1) tName = " Student.";
            else if (faculty[i]->getTypePerson() == 2) tName = " Teacher.";
            else if (faculty[i]->getTypePerson() == 3) tName = " Head.";
            else if (faculty[i]->getTypePerson() == 4) tName = " Researcherer.";
            cout << faculty[i]->getId() << ") " << faculty[i]->getFIO() << " " << faculty[i]->getAge() << " years." << tName << endl;
            if (k == 1)
            {
                faculty[i]->printAbout();
                faculty[i]->printAboutInterns();
            }
        }
        cout << endl;
    }
