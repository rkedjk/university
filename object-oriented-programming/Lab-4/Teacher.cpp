#include "Teacher.h"

void Teacher::printSubjects() const
{
    cout << "Leads subjects:" << endl;
    for (int i = 0; i < MAX_SUBJECTS; ++i)
    {
        cout << "Subject No " << i + 1 << ": ";
        if (subjects[i])
            cout << "Hours: " << subjects[i];
        else
            cout << "Does not lead.";
        cout << endl;
    }
}
Teacher::~Teacher() { cout << "dtor Teacher" << endl; }
void Teacher::setValue(int subjectId, int subjectHour)
{
    if (!VALID_SUBJ(subjectId)) return;
    subjects[subjectId] = subjectHour;
}
int Teacher::getSubject(int subjectId) const
{
    if (!VALID_SUBJ(subjectId)) return 0;
    return subjects[subjectId];
}
double Teacher::getFullPay() const
{
    int sumHour = 0;
    for (int i = 0; i < MAX_SUBJECTS; ++i)
    {
        if (subjects[i]) { sumHour += subjects[i]; }
    }
    return getBasicPay() * sumHour / 60;
}

void Teacher::printAbout() const
{
    cout << "Information about the teacher: ";
    Person::printAbout(); cout << "Paid funds: " << getFullPay() << endl;
    printSubjects(); cout << endl;
}
