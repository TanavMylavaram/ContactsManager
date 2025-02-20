#include <iostream>
#include "menu.h"
#include "ContactMenu.h"
#include <cstdlib> //for system("cls") to clear console


int main() {
	ContactMenu menu("contacts_data.csv");

	do {
		menu.open();
	} while (menu.close());

	return 0;
}