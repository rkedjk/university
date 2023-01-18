#include "Student.h"

void Student::printGrades() const
{
    for (int i = 0; i < MAX_SUBJECTS; ++i)
    {
        cout << "Subject No" << i + 1 << ": ";
        if (grades[i])
            cout << " mark " << grades[i];
        else
            cout << " not mark";
        cout << endl;
    }
}
Student::~Student() { cout << "dtor Student" << endl; }
void Student::setValue(int subjectId, int value)
{
    if (!VALID_SUBJ(subjectId) || !VALID_GRADE(value))
        throw Exception("One or both values are not highlighted.");
    grades[subjectId] = value;
}
float Student::getFullPay() const
{
    float k;
    int countMarks[] = {0, 0, 0, 0, 0};
    for (int i = 0; i < MAX_SUBJECTS; ++i)
    {
        switch (grades[i])
        {
        case 1:
        {
            countMarks[0] += 1;
            break;
        }
        case 2:
        {
            countMarks[1] += 1;
            break;
        }
        case 3:
        {
            countMarks[2] += 1;
            break;
        }
        case 4:
        {
            countMarks[3] += 1;
            break;
        }
        case 5:
        {
            countMarks[4] += 1;
            break;
        }
        }
    }
    if (countMarks[1] > 0)
    {
        k = 0.0;
    }
    else if (countMarks[2] > 0)
    {
        k = 0.5;
    }
    else if (countMarks[3] > 0)
    {
        k = 1;
    }
    else if (countMarks[4] > 0)
    {
        k = 1.5;
    }
    return getBasicPay() * k;
}
void Student::printAbout() const
{
    cout << "Information about the student: ";
    Human::printAbout();
    cout << "Paid funds: " << getFullPay() << endl;
    printGrades();
    cout << endl;
}