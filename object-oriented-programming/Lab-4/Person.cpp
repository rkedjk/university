#include "Person.h"
#include <ctime>

Person::Person(const char* name)
{
	strcpy(this->fio, name ? name : "NONAME");
	yearBirth = 0;
}

/// @brief 
Person::~Person() { cout << "dtor Person" << endl; }
/// @brief 
/// @return 
const char* Person::getFIO() const { return fio; }
/// @brief 
/// @return 
int Person::getBasicPay() const { return basicPay; }
/// @brief 
/// @return 
int Person::getId() const { return numb_id; }
/// @brief 
/// @return 
int Person::getTypePerson() const { return type; }
/// @brief 
/// @return 
int Person::getYearBT() const { return yearBirth; }
/// @brief 
/// @return 
int Person::getAge() const
{
	time_t t = time(NULL);
	return (localtime(&t)->tm_year + 1900) - yearBirth;
}
/// @brief 
void Person::printAbout() const { cout << getFIO() << " " << getAge() << " year." << endl; }
/// @brief 
void Person::printAboutInterns() { return; }
/// @brief 
/// @return 
double Person::getFullPay() const { return 0; }
/// @brief 
/// @param  
void Person::addIntern(Person*) { return; }
/// @brief 
/// @param  
/// @param  
void Person::setValue(int, int) { return; }
/// @brief 
/// @param  
/// @return 
int Person::geValue(int) const { return 0; }
/// @brief 
int Person::nextId = 1;
