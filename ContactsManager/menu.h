#pragma once
#include <iostream>
#include <vector>
#include "ContactList.h"	

using namespace std;

class Menu {

public:
	void open();

	bool close() const;
	Menu();
private:

	char getOption();

protected:
	virtual void display() = 0;
	virtual void executeOption(char option) = 0;

	void exit();
	bool m_Open;
	// char getOption();
	// For the sub menu pages
	char page;
};