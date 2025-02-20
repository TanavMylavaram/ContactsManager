#include "ContactList.h"
#include "contact.h"
#include "person.h"
#include "menu.h"
#include "ArrayList.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>


// ContactList::ContactList() : ArrayList<Contact>() {}

ContactList::ContactList(int capacity) : ArrayList<Contact>(capacity) {}

ContactList::~ContactList() {}

int ContactList::arraySize() {
    return m_Contacts->size();
}

// Constructs contact list from given file
ContactList::ContactList(string filename) {
    m_Contacts = new ContactList;
    ascending = false;
    updateContacts(filename);

}

// Get up-to-date data from given file
bool ContactList::updateContacts(string filename) {

    clear();
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return false;
    }

    string line;

    getline(file, line);

    while (getline(file, line)) {
        Contact contact(line);
        addElement(contact);
    }

    file.close();
    return true;
}

// Displays the data
void ContactList::doList() {
    for (int i = 0; i < size(); i++) {

        display(i);
        cout << endl;
    }
}

// Prints out the header for the data
void ContactList::printHeader() {

    cout << left << setw(5) << "id"
        << setw(15) << "first_name"
        << setw(15) << "middle_name"
        << setw(15) << "last_name"
        << setw(10) << "role"
        << setw(20) << "company_name"
        << setw(30) << "address"
        << setw(15) << "city"
        << setw(15) << "county"
        << setw(5) << "state"
        << setw(10) << "zip"
        << setw(15) << "phone1"
        << setw(15) << "phone"
        << "email" << endl;
    cout << "================================================================================";
    cout << "================================================================================";
    cout << "==============================================";
    cout << endl;
}

// Prints out the contact's info for the table
void ContactList::display(int index) const {
    cout << setw(5) << m_Elements[index].getId()
        << setw(15) << m_Elements[index].getFirstName()
        << setw(15) << m_Elements[index].getMiddleName()
        << setw(15) << m_Elements[index].getLastName()
        << setw(10) << m_Elements[index].getRole()
        << setw(20) << m_Elements[index].getCompanyName()
        << setw(30) << m_Elements[index].getAddress()
        << setw(15) << m_Elements[index].getCity()
        << setw(15) << m_Elements[index].getCounty()
        << setw(5) << m_Elements[index].getState()
        << setw(10) << m_Elements[index].getZip()
        << setw(15) << m_Elements[index].getPhone1()
        << setw(15) << m_Elements[index].getPhone()
        << m_Elements[index].getEmail();

}

//id,first_name,middle_name,last_name,role,company_name,address,city,county,state,zip,phone1,phone,email

// Allows user to search the database with given parameters
void ContactList::doSortBy() {
    // Selection sort
    string field;
    cout << "\nValid Fields: \nid, first_name, middle_name" <<
        "\nlast_name, role, company_name" <<
        "\naddress, city, county," <<
        "\nstatezip, phone1, phone, email";
    cout << "\n\nPlease enter a field\n(x) to cancel: " << endl;
    cout << ">";
    cin >> field;
    if (field == "x") {
        return;
    }
    else {
        // Universal Contact comparing flag
        ContactCompareBy option;
        if (field == "id") {
            option = ID;
        }
        else if (field == "first_name") {
            option = FIRST_NAME;
        }
        else if (field == "middle_name") {
            option = MIDDLE_NAME;
        }
        else if (field == "last_name") {
            option = LAST_NAME;
        }
        else if (field == "role") {
            option = ROLE;
        }
        else if (field == "company_name") {
            option = COMPANY_NAME;
        }
        else if (field == "address") {
            option = ADDRESS;
        }
        else if (field == "city") {
            option = CITY;
        }
        else if (field == "county") {
            option = COUNTY;
        }
        else if (field == "state") {
            option = STATE;
        }
        else if (field == "zip") {
            option = ZIP;
        }
        else if (field == "phone_1") {
            option = PHONE_1;
        }
        else if (field == "phone") {
            option = PHONE;
        }
        else if (field == "email") {
            option = EMAIL;
        }

        // Sets the universal contact comparison set to whatever the user chose
        Contact::setCompareBy(option);

        // Sort based off that comparison value
        selectionSort();


    }


}


// Overrides the selection sort from ArrayList to factor in ascending vs descending
void ContactList::selectionSort() {

    for (int i = 0; i < size() - 1; i++) {
        // Assume the smallest value is located at the current 'i' position
        int minIndex = i;
        // Check the rest of the array to see if there's a smaller element
        for (int j = i + 1; j < size(); j++) {
            if (ascending) {
                if (m_Elements[j] > m_Elements[minIndex]) {
                    minIndex = j; // Update the minIndex with the index of the new smallest value
                }
            }
            else {
                if (m_Elements[j] < m_Elements[minIndex]) {
                    minIndex = j; // Update the minIndex with the index of the new smallest value
                }
            }

        }

        // If the minimum isn't in the position, swap it with the current 'i'
        // value
        if (minIndex != i) {
            swap(m_Elements[i], m_Elements[minIndex]);
        }
    }
}

// Adds a contact to the data
void ContactList::addContact() {
    Contact newContact;
    int newID = getMaxID() + 1;
    newContact.setId(newID);
    gatherInput(newContact);
    addElement(newContact);
    cout << endl << "Contact #" << newContact.getId() << " Successfully added!" << endl;
}

// Add to contact list
void ContactList::doAdd() {
    addContact();
}

// Edit contact data
void ContactList::editContact(int id) {

    for (int i = 0; i < size(); i++) {
        if (m_Elements[i].getId() == id) {
            //cout << "Enter new details for the contact: \n";
            gatherInput(m_Elements[i]);
            return;
        }
    }

    cout << "Contact with ID " << id << " not found." << endl;
}

// Upon exit, save contacts to file
void ContactList::doExit() {

    saveContactsToFile();
}

// Edit contact
void ContactList::doEdit() {

    cout << endl << "Please enter the contact ID to edit: " << endl;
    int id = 0;
    cin >> id;

    if (id >= m_Elements[0].getId() && id <= m_Elements[size() - 1].getId()) {
        editContact(id);
        cout << endl << "Contact ID #" << id << " Successfully edited!" << endl;
    }
    else {
        cout << "HERE: " << size();
        cout << "Invalid id." << endl;
    }


    //    
}

// Deletes a contact from the database given the id. 
void ContactList::deleteContact(int id) {
    for (int i = 0; i < size(); i++) {
        if (m_Elements[i].getId() == id) {
            removeElement(m_Elements[i]);
            cout << "Contact with ID " << id << " has been deleted."
                << endl;
            return;
        }
    }
    cout << "Contact with ID " << id << " not found." << endl;
}

// Delete contact
void ContactList::doDelete() {
    int id;
    cout << "Enter the ID of the contact to delete: ";
    cin >> id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << endl << "Invalid ID" << endl;
    }
    deleteContact(id);

}


void ContactList::displayList() {
    for (int i = 0; i < m_Contacts->size(); i++) {
        cout << setw(3) << (*m_Contacts)[i] << endl;
    }
}

// View a specific contact

int ContactList::viewContact() {
    int id;
    cout << "Enter the ID of the contact to view: ";
    cin >> id;
    if (cin.fail()) {

        cin.clear();
        cin.ignore();
        return -1;
    }
    for (int i = 0; i < size(); i++) {

        if (m_Elements[i].getId() == id) {
            return i;
        }
    }

    cout << "\nContact with ID " << id << " not found." << endl;
    return -1;
}


// Select a contact from list and show the contact details
void ContactList::doView() {
    int index = viewContact();
    if (index >= 0 && index < size()) {
        displayContactDetails(m_Elements[index]);
    }
    else {
        cout << "\nInvalid index." << endl;
    }
}


// Create a new contact
void ContactList::gatherInput(Contact& contact) {
    string first_name;
    cin.ignore();
    cout << "Enter First Name: ";
    getline(cin, first_name);
    contact.setFirstName(first_name);

    string middle_name;
    cout << "Enter Middle Name: ";
    getline(cin, middle_name);
    contact.setMiddleName(middle_name);

    string last_name;
    cout << "Enter Last Name: ";
    getline(cin, last_name);
    contact.setLastName(last_name);

    string role;
    cout << "Enter Role: ";
    getline(cin, role);
    contact.setRole(role);

    string company;
    cout << "Enter Company: ";
    getline(cin, company);
    contact.setCompanyName(company);

    string address;
    cout << "Enter Address ";
    getline(cin, address);
    contact.setAddress(address);

    string city;
    cout << "Enter City: ";
    getline(cin, city);
    contact.setCity(city);

    string county;
    cout << "Enter County: ";
    getline(cin, county);
    contact.setCounty(county);

    string state;
    cout << "Enter State: ";
    getline(cin, state);
    contact.setState(state);

    string zip;
    cout << "Enter Zip Code: ";
    getline(cin, zip);
    contact.setZip(zip);

    string phone1;
    cout << "Enter Primary Phone Number: ";
    getline(cin, phone1);
    contact.setPhone1(phone1);

    string phone;
    cout << "Enter Secondary Phone Number: ";
    getline(cin, phone);
    contact.setPhone(phone);

    string email;
    cout << "Enter Email: ";
    getline(cin, email);
    contact.setEmail(email);
}

// Gets the current max id from the contact list
int ContactList::getMaxID() {
    int maxID = 0;
    for (int i = 0; i < size(); i++) {
        int currentID =
            (m_Elements[i].getId());
        if (currentID > maxID) {
            maxID = currentID;
        }
    }
    return maxID;
}

// Saves all the data to the csv file
void ContactList::saveContactsToFile() {

    ofstream file("contacts_data.csv",
        ios::trunc); // Open the file in truncation mode to
    // overwrite the existing content

    if (!file.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    // Write a header to the file
    file << "ID,First Name,Middle Name,Last "
        "Name,Role,Company,Address,City,County,State,ZIP,Phone1,Phone,Email"
        << endl;
    // Write each contact's details to the file
    for (int i = 0; i < size(); i++) {
        Contact contact = m_Elements[i];
        file << contact.getId() << "," << contact.getFirstName() << ","
            << contact.getMiddleName() << "," << contact.getLastName() << ","
            << contact.getRole() << "," << contact.getCompanyName() << ","
            << contact.getAddress() << "," << contact.getCity() << "," << contact.getCounty()
            << "," << contact.getState() << "," << contact.getZip() << "," << contact.getPhone()
            << "," << contact.getPhone1() << "," << contact.getEmail() << endl;
    }
    file.close();
}





void ContactList::displayContactDetails(Contact& contact) {

    cout << "ID: " << contact.getId() << endl;
    cout << "First Name: " << contact.getFirstName() << endl;
    cout << "Middle Name: " << contact.getMiddleName() << endl;
    cout << "Last Name: " << contact.getLastName() << endl;
    cout << "Role: " << contact.getRole() << endl;
    cout << "Company Name: " << contact.getCompanyName() << endl;
    cout << "Address: " << contact.getAddress() << endl;
    cout << "City: " << contact.getCity() << endl;
    cout << "County: " << contact.getCounty() << endl;
    cout << "State: " << contact.getState() << endl;
    cout << "ZIP: " << contact.getZip() << endl;
    cout << "Phone 1: " << contact.getPhone() << endl;
    cout << "Phone: " << contact.getPhone1() << endl;
    cout << "Email: " << contact.getEmail() << endl;

}

