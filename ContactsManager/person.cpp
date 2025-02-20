#include "person.h"

Person::Person() {}

Person::Person(string FirstName, string MiddleName, string LastName) : m_FirstName(FirstName), m_MiddleName(MiddleName), m_LastName(LastName) {}

Person::~Person() {};

string Person::getFirstName() const { return m_FirstName; }
string Person::getMiddleName() const { return m_MiddleName; }
string Person::getLastName() const { return m_LastName; }

void Person::setFirstName(const string& FirstName) { m_FirstName = FirstName; }
void Person::setMiddleName(const string& MiddleName) { m_MiddleName = MiddleName; }
void Person::setLastName(const string& LastName) { m_LastName = LastName; }


