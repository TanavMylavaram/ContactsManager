#include "menu.h"
#include "contact.h"
#include "ContactList.h"
#include <vector>

// Each page in menu
enum CONTACT_MENU_OPTION {
	CONTACT_MENU_ROOT = '0',
	CONTACT_MENU_LIST = '1',
	CONTACT_MENU_VIEW = '2',
	CONTACT_MENU_ADD = '3',
	CONTACT_MENU_EDIT = '4',
	CONTACT_MENU_DELETE = '5',
	CONTACT_MENU_EXIT = 'x'
};


class ContactMenu : public Menu {
public:
	ContactMenu(string filename);
	void display();
	void executeOption(char option);

private:
	ContactList* pList;
};

