#include "ContactMenu.h"


ContactMenu::ContactMenu(string filename) {
    pList = new ContactList(filename);
}



// Handles all the menu pages
void ContactMenu::display() {
    // cout << "\nCurrent Page: " << page << endl;

    // Shows the user's current page
    switch (page) {

        // Main menu page
    case CONTACT_MENU_ROOT:
        cout << "***** Contact Menu *****" << endl
            << "1) List of Contacts" << endl
            << "2) View a Contact" << endl
            << "3) Add New Contact" << endl
            << "4) Edit Contact" << endl
            << "5) Delete Contact" << endl
            << "x) Exit" << endl;
        break;

        // List of Contacts page
    case CONTACT_MENU_LIST:

        pList->printHeader();
        pList->doList();
        cout << "***** List of Contacts *****" << endl;
        if (pList->ascending) {
            cout << "1) Show Descending " << endl;
        }
        else {
            cout << "1) Show Ascending " << endl;
        }
        cout << "2) By fieldname" << endl
            << "x) Return" << endl;
        break;

        // View contacts page
    case CONTACT_MENU_VIEW:
        cout << "**** View a Contact ****" << endl
            << "1) View Contact " << endl
            << "x) Return" << endl;

        break;

        // Add contacts page
    case CONTACT_MENU_ADD:
        cout << "*** Add New Contact ****" << endl
            << "1) Add Contact" << endl
            << "x) Return" << endl;
        break;

        // Edit contacts page
    case CONTACT_MENU_EDIT:
        cout << "*** Edit Contact ****" << endl
            << "1) Edit Contact " << endl
            << "x) Return" << endl;
        break;

        // Delete contacts page
    case CONTACT_MENU_DELETE:

        cout << "*** Delete Contact ****" << endl
            << "1) Delete Contact: " << endl
            << "2) View List" << endl
            << "x) Return " << endl;
        break;

        // Exit program
    case CONTACT_MENU_EXIT:
        break;

        // If the user enters an invalid page.. however doesn't work
    default:
        cout << endl << "Erorr: Please select from the choices above" << endl;
        break;


    }

}

// Handles all user inputs
void ContactMenu::executeOption(char option) {

    // Logic for each page
    switch (page) {

        // Options for the main menu
    case CONTACT_MENU_ROOT:
        switch (option) {
        case CONTACT_MENU_LIST:
            system("cls"); // Clears console
            page = option;

            break;
        case CONTACT_MENU_VIEW:
            system("cls"); // Clears console
            page = option;

            break;
        case CONTACT_MENU_ADD:
            system("cls"); // Clears console
            page = option;

            break;
        case CONTACT_MENU_EDIT:
            system("cls"); // Clears console
            page = option;

            break;
        case CONTACT_MENU_DELETE:
            system("cls"); // Clears console
            page = option;

            break;
        case CONTACT_MENU_EXIT:
            system("cls"); // Clears console
            m_Open = false;
            Contact::setCompareBy(ID);
            pList->ascending = false;
            pList->selectionSort();

            pList->doExit();
            break;
        }
        break;

        // Options for the contacts list page
    case CONTACT_MENU_LIST:
        switch (option) {
        case '1':
            //pList->doList();

            system("cls");
            if (pList->ascending) {
                pList->ascending = false;
            }
            else {
                pList->ascending = true;
            }
            pList->selectionSort();
            break;
        case '2':

            pList->doSortBy();
            break;
        case 'x':
            system("cls");
            Contact::setCompareBy(ID);
            pList->ascending = false;
            pList->selectionSort();
            page = CONTACT_MENU_ROOT;
        }
        break;

        // Options for the view contacts page
    case CONTACT_MENU_VIEW:
        switch (option) {
        case '1':
            pList->doView();
            cout << "=========================" << endl;
            break;
        case 'x':
            system("cls");
            page = CONTACT_MENU_ROOT;
            break;
        }
        break;

        // Options for the add contacts page
    case CONTACT_MENU_ADD:
        switch (option) {
        case '1':
            pList->doAdd();

            break;
        case 'x':
            system("cls");
            page = CONTACT_MENU_ROOT;
        }
        break;

        // Options for the edit contacts page
    case CONTACT_MENU_EDIT:
        switch (option) {
        case '1':
            system("cls");
            pList->printHeader();
            pList->doList();
            pList->doEdit();
            break;
        case 'x':
            system("cls");
            page = CONTACT_MENU_ROOT;
        }
        break;

        // Options for the delete contact page
    case CONTACT_MENU_DELETE:
        switch (option) {
        case '1':

            pList->doDelete();
            break;
        case '2':
            system("cls");
            pList->printHeader();
            pList->doList();
            break;
        case 'x':
            system("cls");
            page = CONTACT_MENU_ROOT;
            break;
        }
        break;

    }
    //main index

}