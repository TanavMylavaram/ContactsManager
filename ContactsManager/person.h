#pragma once
#include <string>

using namespace std;

class Person {
public:
	Person();
	Person(string FirstName, string MiddleName, string LastName);
	~Person();

	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;

	void setFirstName(const string& FirstName);
	void setMiddleName(const string& MiddleName);
	void setLastName(const string& LastName);


	//bool operator<<(const Person& other) const;

private:
	string m_FirstName;
	string m_MiddleName;
	string m_LastName;
};