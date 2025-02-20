#include "menu.h"
#include <iostream>
Menu::Menu() {
	m_Open = true;
	page = '0';
}

void Menu::open() {
	m_Open = true;
	display();
	char option = getOption();
	executeOption(option);

}

bool Menu::close() const { return m_Open; }

char Menu::getOption() {
	char option;
	cout << "> ";
	cin >> option;
	return option;
}