#pragma once

#include "ArrayList.h"
#include "contact.h"
#include "person.h"


class ContactList : public ArrayList<Contact> {
public:
	ContactList() {
		m_Contacts = new ArrayList<Contact>;
		//updateContacts();
	}
	~ContactList();
	void printHeader();
	ContactList(int capacity);
	ContactList(string filename);
	int arraySize();
	void doList();
	void display(int index) const;
	void doSortBy();

	//bool compareContacts(const Contact& a, const Contact& b, const string& field);

	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doExit();
	void selectionSort();

	bool ascending;

private:

	void displayList();
	int viewContact();
	void addContact();
	void gatherInput(Contact& contact);
	int getMaxID();
	void editContact(int id);
	void deleteContact(int id);
	void saveContactsToFile();
	bool updateContacts(string filename);
	void displayContactDetails(Contact& contact);



	ArrayList<Contact>* m_Contacts;
};