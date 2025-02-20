#include "contact.h"
#include <iostream>

ContactCompareBy Contact::compareOption = ContactCompareBy::ID;

// Sets the universal comparison setting for the contacts
void Contact::setCompareBy(ContactCompareBy field) {
    Contact::compareOption = field;
}

ContactCompareBy Contact::getCompareBy() {
    return Contact::compareOption;
}
Contact::Contact() {}

Contact::Contact(int id, string role, string companyName, string address, string city, string county, string state, string zip, string phone1, string phone, string email,
    string FirstName, string MiddleName, string LastName)
    : Person(FirstName, MiddleName, LastName),
    m_id(id), m_role(role), m_companyName(companyName), m_address(address), m_city(city), m_county(county), m_state(state), m_zip(zip), m_phone(phone1), m_phone1(phone), m_email(email)
{
}

//id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email

// Constructs a contact given a string line
Contact::Contact(string line) {
    stringstream ss(line);
    string id;
    string FirstName;
    string MiddleName;
    string LastName;
    string CompanyName;
    getline(ss, id, ',');
    m_id = stoi(id);

    getline(ss, FirstName, ',');
    getline(ss, MiddleName, ',');
    getline(ss, LastName, ',');

    this->setFirstName(FirstName);
    this->setMiddleName(MiddleName);
    this->setLastName(LastName);

    getline(ss, this->m_role, ',');



    // For the special case where company field starts with "  " and had commas inside
    char nextChar = ss.peek();
    if (nextChar == '\"') {
        ss.get();  // Skip the opening quote
        getline(ss, this->m_companyName, '\"');  // Read until the closing quote
        ss.get();  // Skip the closing quote
        if (ss.peek() == ',') {
            ss.get();  // Skip the following comma, if it exists
        }
    }
    else {
        getline(ss, this->m_companyName, ',');
    }


    getline(ss, this->m_address, ',');
    getline(ss, this->m_city, ',');
    getline(ss, this->m_county, ',');
    getline(ss, this->m_state, ',');
    getline(ss, this->m_zip, ',');
    getline(ss, this->m_phone1, ',');
    getline(ss, this->m_phone, ',');
    getline(ss, this->m_email, ',');

}


Contact::~Contact() {};

int Contact::getId() const { return m_id; }
string Contact::getRole() const { return m_role; }
string Contact::getCompanyName() const { return m_companyName; }
string Contact::getAddress() const { return m_address; }
string Contact::getCity() const { return m_city; }
string Contact::getCounty() const { return m_county; }
string Contact::getState() const { return m_state; }
string Contact::getZip() const { return m_zip; }
string Contact::getPhone1() const { return m_phone1; }
string Contact::getPhone() const { return m_phone; }
string Contact::getEmail() const { return m_email; }

void Contact::setId(int id) { m_id = id; }
void Contact::setRole(const string& role) { m_role = role; }
void Contact::setCompanyName(const string& companyName) { m_companyName = companyName; }
void Contact::setAddress(const string& address) { m_address = address; }
void Contact::setCity(const string& city) { m_city = city; }
void Contact::setCounty(const string& county) { m_county = county; }
void Contact::setState(const string& state) { m_state = state; }
void Contact::setZip(string& zip) { m_zip = zip; }
void Contact::setPhone1(const string& phone1) { m_phone = phone1; }
void Contact::setPhone(const string& phone) { m_phone1 = phone; }
void Contact::setEmail(const string& email) { m_email = email; }


bool Contact::operator==(const Contact& other) const { return m_id == other.m_id; }

// Comparison logic
bool Contact::operator<(const Contact& other) const {
    switch (compareOption) {
    case ID:
        return(this->m_id < other.getId());
    case FIRST_NAME:
        return(this->getFirstName() < other.getFirstName());
    case MIDDLE_NAME:
        return(this->getMiddleName() < other.getMiddleName());
    case LAST_NAME:
        return(this->getLastName() < other.getLastName());
    case ROLE:
        return(this->m_role < other.getRole());
    case COMPANY_NAME:
        return(this->m_companyName < other.getCompanyName());
    case ADDRESS:
        return(this->m_address < other.getAddress());
    case CITY:
        return(this->m_city < other.getCity());
    case COUNTY:
        return(this->m_county < other.getCounty());
    case STATE:
        return(this->m_state < other.getState());
    case ZIP:
        return(this->m_zip < other.getZip());
    case PHONE_1:
        return(this->m_phone1 < other.getPhone1());
    case PHONE:
        return(this->m_phone < other.getPhone());
    case EMAIL:
        return(this->m_email < other.getEmail());
    }
    return false;
};
bool Contact::operator>(const Contact& other) const {
    return !(*this < other);
};
bool Contact::operator<=(const Contact& other) const {
    return ((*this < other) || (*this == other));
};
bool Contact::operator>=(const Contact& other) const {
    return !(*this <= other);
};






ostream& operator<<(ostream& out, const Contact& contact) {
    return out << " " << contact.m_id << " " <<
        contact.m_role << " " <<
        contact.m_companyName << " " <<
        contact.m_address << " " <<
        contact.m_city << " " <<
        contact.m_county << " " <<
        contact.m_state << " " <<
        contact.m_zip << " " <<
        contact.m_phone1 << " " <<
        contact.m_phone << " " <<
        contact.m_email << " ";
}