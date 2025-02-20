#pragma once
#include <stdlib.h>
#include <ostream>
#include "person.h"
#include "sstream"

// Universal comparison setting for the contacts. Avoids long complicated code within the sorting algorithms
enum ContactCompareBy {
	ID,
	FIRST_NAME,
	MIDDLE_NAME,
	LAST_NAME,
	ROLE,
	COMPANY_NAME,
	ADDRESS,
	CITY,
	COUNTY,
	STATE,
	ZIP,
	PHONE_1,
	PHONE,
	EMAIL
};

class Contact : public Person {
public:


	Contact();
	Contact(int id, string role, string companyName, string address, string city, string county, string state, string zip, string phone1, string phone, string email,
		string FirstName, string MiddleName, string LastName);
	Contact(string line);
	~Contact();



	int getId() const;
	string getRole() const;
	string getCompanyName() const;
	string getAddress() const;
	string getCity() const;
	string getCounty() const;
	string getState() const;
	string getZip() const;
	string getPhone1() const;
	string getPhone() const;
	string getEmail() const;

	void setId(int id);
	void setRole(const string& role);
	void setCompanyName(const string& companyName);
	void setAddress(const string& address);
	void setCity(const string& city);
	void setCounty(const string& county);
	void setState(const string& state);
	void setZip(string& zip);
	void setPhone1(const string& phone1);
	void setPhone(const string& phone);
	void setEmail(const string& email);

	bool operator==(const Contact& other) const;
	bool operator<(const Contact& other) const;
	bool operator>(const Contact& other) const;
	bool operator<=(const Contact& other) const;
	bool operator>=(const Contact& other) const;


	friend ostream& operator<<(ostream& out, const Contact&);
	static void setCompareBy(ContactCompareBy field);
	static ContactCompareBy getCompareBy();


	//id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email
private:

	static ContactCompareBy compareOption;

	int m_id;
	string m_role;
	string m_companyName;
	string m_address;
	string m_city;
	string m_county;
	string m_state;
	string m_zip;
	string m_phone1;
	string m_phone;
	string m_email;


};