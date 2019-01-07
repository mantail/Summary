#include "Book.h"
#include <iostream>
#include <stdio.h>
//int sortCriteria = LAST_NAME;
using namespace std;
int main()
{
	Book *testBook = new Book;
	Contact *toPush;
	char num[5];
	int i;
	const char *lastNames[5] = {"Aaaa", "Loyd", "Zord" ,"Beta", ""};
	string first("Daniel");
	string ad1("asdf");
	string ad2("fdsa");
	string city("eugene");
	string state("oregon");
	string zip("98765");
	for(i = 0; i < 5; i++)		//set up 5 contacts with different last names and phone numbers
	{
		sprintf(num, "%d%d%d%d%d", i,i,i,i,i);
		string phone(num);	
		string last(lastNames[i]);
		toPush = new Contact(first, last, phone, ad1, ad2, city, state, zip);
		testBook->AddContact(toPush);
	}
	testBook->SortContacts();
	vector<Contact>::const_iterator it;
	for(it = testBook->GetContacts().begin(); it < testBook->GetContacts().end(); it++)
	//const_iterator iterates through the contacts, contacts.begin() gets first element, .end() gets the last, increments like a normal loop
	{
	//print each contact, looks disgusting
		cerr << "First: " << (*it).getFirstName() << "  Last: " << (*it).getLastName() << "  Phone: " << (*it).getPhoneNumber() << "  Ad1: " << (*it).getAddress1() << "  Ad2: " << (*it).getAddress2() << "  City: " << (*it).getCity() << "  State: "<< (*it).getState() << "  Zip: " << (*it).getZipcode() << endl;
	}	
	cerr << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	testBook->SetSort(ZIP);
	testBook->SortContacts();
	for(it = testBook->GetContacts().begin(); it < testBook->GetContacts().end(); it++)
	//const_iterator iterates through the contacts, contacts.begin() gets first element, .end() gets the last, increments like a normal loop
	{
		if(it == testBook->GetContacts().begin())
		{
			vector<int> temp;
			temp.push_back(FIRST_NAME);
			vector<string> temp2;
			temp2.push_back("Charles");
			testBook->EditContact(&testBook->GetContacts().at(1), temp, temp2);
		}
	//print each contact, looks disgusting
		cerr << "First: " << (*it).getFirstName() << "  Last: " << (*it).getLastName() << "  Phone: " << (*it).getPhoneNumber() << "  Ad1: " << (*it).getAddress1() << "  Ad2: " << (*it).getAddress2() << "  City: " << (*it).getCity() << "  State: "<< (*it).getState() << "  Zip: " << (*it).getZipcode() << endl;
	}	
}

