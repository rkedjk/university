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
    if (!VALID_SUBJ(subjectId))
        throw Exception("The value is not valid.");
    if (subjectHour < 0)
        throw Exception("The value is not valid.");
    subjects[subjectId] = subjectHour;
}
int Teacher::getSubject(int subjectId) const
{
    if (!VALID_SUBJ(subjectId))
        return 0;
    return subjects[subjectId];
}
float Teacher::getFullPay() const
{
    int sumHour = 0;
    for (int i = 0; i < MAX_SUBJECTS; ++i)
    {
        if (subjects[i])
        {
            sumHour += subjects[i];
        }
    }
    return getBasicPay() * sumHour / 60;
}

void Teacher::printAbout() const
{
    cout << "Information about the teacher: ";
    Human::printAbout();
    cout << "Paid funds: " << getFullPay() << endl;
    printSubjects();
    cout << endl;
}
