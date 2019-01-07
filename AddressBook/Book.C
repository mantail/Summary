#include <algorithm>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include "Book.h"

using namespace std;

	/*CONSTRUCTORS AND DECONSTRUCTORS*/
Book::Book()
{/*New book created, defaults to unsaved,
	 sorting by last name, and an empty file name.*/
	 this->FileName = "Untitled_Book";
}
Book::Book(string filename)
{/*New book created, defaults to unsaved, sorting by last name, and an empty file name.*/

	this->FileName = filename;

}
Book::~Book(){}

	/*FEATURES*/
void Book::AddContact(Contact newContact)
{
	contacts.push_back(newContact);
	//Do we need to run sort after each AddContact call?~~~~~~
	this->SortContacts();

}
void Book::DeleteContact(Contact contact)
{
	int position;
	position = this->ContactSearch(contact);
	if(position != -1)
	{
		this->DeleteContact(position);
	}
	else
	{
		/*Output message to gui or handle?*/
		cerr << "Contact for \"Last Name: " << contact.GetLastName() << ", First Name: "
    << contact.GetFirstName() << " \"" << "Was not found in contact book." << endl;
	}
}
void Book::DeleteContact(int position)
{
	this->contacts.erase(this->contacts.begin() + position);
	this->SortContacts();
}
void Book::EditContact(Contact contactToEdit, vector<pair<int,std::string> > newInfo)
{
	/*
	newInfo represented the field to be edited
	newInfo correspond to newInfo and contain the new information to be edited
	*/
	for(int index = 0; index < newInfo.size(); index++)
	{
		switch(newInfo[index].first)
		{
			case FIRST_NAME:
				contactToEdit.SetFirstName(newInfo[index].second);
				break;
			case LAST_NAME:
				contactToEdit.SetLastName(newInfo[index].second);
				break;
			case PHONE:
				contactToEdit.SetPhoneNumber(newInfo[index].second);
				break;
			case ADDRESS1:
				contactToEdit.SetAddress1(newInfo[index].second);
				break;
			case ADDRESS2:
				contactToEdit.SetAddress2(newInfo[index].second);
				break;
			case CITY:
				contactToEdit.SetCity(newInfo[index].second);
				break;
			case STATE:
				contactToEdit.SetState(newInfo[index].second);
				break;
			case ZIP:
				contactToEdit.SetZipcode(newInfo[index].second);
				break;
			default:
				fprintf(stderr, "Editing error\n");
		}
	}
}
void Book::SortContacts()
{
	/*
	force a sort on the objects in the vector by overloading std::sort based on what choice is selected.
	*/
	sort(contacts.begin(), contacts.end());
}

int Book::ContactSearch(Contact contact)
{
	/*returns -1 if contact is not found*/
	int position;
	/*Switch critera to LAST_NAME for search, store, then reset*/
	SearchCriteria temp = sortCriteria;
	sortCriteria = LAST_NAME;
	position = this->Binary_Search(0,this->contacts.size()-1, contact);
	sortCriteria = temp;
	return position;
}
vector<Contact> Book::FindMatches(Contact contact)
{
	vector<Contact> temp;
	int i = 0;
	while(i != this->contacts.size())
	{
		if(this->contacts[i] == contact)
		{
			temp.push_back(this->contacts[i]);
		}
		i++;
	}
	return temp;
}
int Book::Binary_Search(int start, int end, Contact contact)
{
	/*returns -1 if contact is not found*/
	if(end >= start)
	{
		int mid = start + (end-start)/2;
		if(this->contacts[mid] == contact)
		{
			return mid;
		}
		if(this->contacts[mid] < contact)
		{
			return Binary_Search(mid+1, end, contact);
		}
		else
		{
			return Binary_Search(start, mid-1, contact);
		}
	}
	return -1;
}
