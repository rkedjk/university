#include "Human.h"
#include <ctime>
#pragma warning(disable : 4996)

Human::Human(const char *fio) // Construct basic class
{
	strcpy(this->fio, fio ? fio : "NONAME");
	yearBirth = 0;
}

Human::~Human() { cout << "dtor Human" << endl; }	 // distruct class
const char *Human::getFIO() const { return fio; }	 // getting Last name first name
int Human::getBasicPay() const { return basicPay; }	 // getting salary
int Human::getId() const { return numb_id; }		 // getting ID
H_Types Human::getTypeHuman() const { return type; } // getting type of human
int Human::getYearBT() const { return yearBirth; }	 // getting year of birth
int Human::getAge() const							 // getting age
{
	time_t t = time(NULL);
	return (localtime(&t)->tm_year + 1900) - yearBirth;
}
void Human::printAbout() const // print info
{
	cout << getFIO() << " " << getAge() << " year." << endl;
}
void Human::printAboutMiniens() { return; }
float Human::getFullPay() const { return 0; } // getting full pay
void Human::addMinien(Human *newMinien) { return; }
void Human::setValue(int subjectId, int value) { return; } // adding human
int Human::geValue(int subjectId) const { return 0; }
int Human::nextId = 1;
