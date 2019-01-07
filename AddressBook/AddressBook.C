#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "AddressBook.h"

using namespace std;
const string PATH = "~/AddressBook/";

AddressBook::AddressBook() //Default constructor
{
	this->LoadLastBook();
	this->CurrentOpenBook = new Book;
	this->SavedStatus = SAVED;
}
AddressBook::AddressBook(string filename)
{
	ImportBook(filename);
	this->SavedStatus = SAVED;
}
AddressBook::~AddressBook() //Destructor
{
	this->SaveLastBook();
	/*quit program gracefully. Whatever created the AddressBook.C object (GUI?)
	calls delete() to reach here. May just get called when program terminates?
	Prompt save on unsaved books here~~I assume the yes/no button has called
	AddressBook.SaveAll() by now, if they chose yes.*/
	delete(CurrentOpenBook);
	this->CurrentOpenBook = NULL;
}

/* Methods */
//Contacts Methods
void AddressBook::ClenseSearch()
{
	searchCriteria.empty();
}
void AddressBook::AddContact(Contact contact)
{
	/*Calls the current Book's AddContact method, which will add the Contact
	object. Mark Album as unsaved and add book to unsaved list. Currently there
	is no check to see if that contact already exists in the Book.*/
	this->CurrentOpenBook->AddContact(contact);
	this->SavedStatus = UNSAVED;
	//output/disply "added" or "already exists"?
}
void AddressBook::RemoveContact(Contact contact)
{
	/*Calls the current Book's DeleteContact method, which calls that Contact's
	destructor. Also removes that entry from the data structure.
	Marked Album as unsaved and add book to unsaved list.*/
	this->CurrentOpenBook->DeleteContact(contact);
	this->SavedStatus = UNSAVED;
}
void AddressBook::EditContact(Contact contactToEdit, vector<pair<int,string> > newContactInfo)
{
	this->CurrentOpenBook->EditContact(contactToEdit, newContactInfo);
	this->SavedStatus = UNSAVED;
}
vector<Contact> AddressBook::SearchContacts(Contact contact)
{
	return this->CurrentOpenBook->FindMatches(contact);
	ClenseSearch();
}
void AddressBook::SortContacts(void)
{
	this->CurrentOpenBook->SortContacts();
}
void AddressBook::SetSortBy(SearchCriteria newSortCriteria)
{
	sortCriteria = newSortCriteria;
}

//Book Methods
void AddressBook::CreateBook(void)
{
	/*Makes a new book and then points to it, brining it to the front of the GUI.
	Saved state of new book assigned in its constructor.
	Adds book to unsaved list.*/
	if(this->CurrentOpenBook != NULL){this->ExportBook();}
	Book *newbook = new Book;
	this->CurrentOpenBook = newbook;
	this->SavedStatus = SAVED;
}
void AddressBook::CreateBook(string filename)
{
	/*Makes a new book and then points to it, brining it to the front of the GUI.
	Saved state of new book assigned in its constructor.
	Adds book to unsaved list.*/
	if(this->CurrentOpenBook != NULL){this->ExportBook();}
	Book *newbook = new Book(filename);
	this->CurrentOpenBook = newbook;
	this->SavedStatus = SAVED;
}
void AddressBook::RemoveBook(Book *book)
{
	/*Deletes the current book from the Album. Marks Album as unsaved.*/
	if(CurrentOpenBook != NULL)
	{
		if(remove(string(PATH+CurrentOpenBook->GetFileName()).c_str()) != 0){cerr << "File deletion encountered an error" << endl;}
		delete CurrentOpenBook;
	}

}
void AddressBook::SwapOpenBook(Book *newBook)
{
	/*Displays the book that has been selected.
	Save CurrentOpenBook*/
	this->ExportBook();
	if(CurrentOpenBook != NULL){delete CurrentOpenBook;}
	this->CurrentOpenBook = newBook;
}

void AddressBook::SaveLastBook(void)
{
	// string filename = this->CurrentOpenBook->GetFileName();
	//
	// ofstream BookLastOpen(PATH+filename,"w");//writing to a file
	// if (BookLastOpen.is_open())
	// {
	//
	// 	if(filename.compare("NULL")==0){filename="Untitled_Book";}
	// 	fprintf(BookLastOpen,"Book to open:\n%s", filename);
	// 	Export(filename, this->CurrentOpenBook->GetContacts());
	// }
	// else
	// {
	// 	cerr << "Unable to save program state." << endl;
	// }
	// BookLastOpen.close();
}
void AddressBook::LoadLastBook(void)
{
	// ifstream BookToOpen(PATH+".addressBook","r");//reading a file
	// if(BookToOpen.is_open())
	// {
	// 	string filename;
	// 	fscanf(BookToOpen, "Book to open:\n%s", filename);
	// 	if(filename.compare("NULL")==0)
	// 	{
	// 		filename="Untitled_Book";
	// 		this->CurrentOpenBook->CreateBook();
	// 	}
	// 	this->CurrentOpenBook->GetContacts() = Import(filename,this->CurrentOpenBook->GetContacts());
	// }
	// else
	// {
	// 	cerr << "Unable to recover program state." << endl;
	// }
	// BookToOpen.close();

}

vector<string> AddressBook::split(string line, char delimeter)
{
    stringstream ss(line);
    string word;
    vector<std::string> splitStr;
    while (getline(ss, word, delimeter))
    {
       splitStr.push_back(word);
    }
    return splitStr;
}
vector<Contact> AddressBook::ImportBook(string filename)
{
	vector<Contact> newCntcts;
	vector<Contact> toMergeCntcts;
	vector<Contact> currentCntcts;
	toMergeCntcts = LoadBook(filename);
	currentCntcts = this->CurrentOpenBook->GetContacts();
	newCntcts.reserve(currentCntcts.size() + toMergeCntcts.size());
	newCntcts.insert(newCntcts.end(), currentCntcts.begin(), currentCntcts.end());
	newCntcts.insert(newCntcts.end(), toMergeCntcts.begin(), toMergeCntcts.end());

	return newCntcts;
}
vector<Contact> AddressBook::LoadBook(string filename)
{
	/*opens a file and reads every line into a
	vector<string>. returns that vector.*/
	ifstream importFile;
	string line;
	vector<Contact> contacts;

	importFile.open(filename.c_str(), ios::in);

	while(getline(importFile,line,'\n'))
	{
		vector<string> parsedLine = split(line,'\t');
		Contact temp = Contact();

		temp.SetFirstName(parsedLine[0]);
		temp.SetLastName(parsedLine[1]);
		temp.SetPhoneNumber(parsedLine[2]);
		temp.SetAddress1(parsedLine[3]);
		temp.SetAddress2(parsedLine[4]);
		temp.SetCity(parsedLine[5]);
		temp.SetState(parsedLine[6]);
		temp.SetZipcode(parsedLine[7]);

		contacts.push_back(temp);
	}
	this->CurrentOpenBook->SetContacts(contacts);
	return contacts;
}
void AddressBook::ExportBook(void)
{/*Called when the user wishes to save the file. A filename MUST be prompted
	or saved previously and then passed to this function. writes the contacts to
	 a file where each line is a list of tab seperated values*/
	Contact c;
	string filename = this->CurrentOpenBook->GetFileName();
	vector<Contact> contacts = this->CurrentOpenBook->GetContacts();
	ofstream exportFile;
	exportFile.open(filename.c_str(), ios::out);

	int size = contacts.size();

	for (int i = 0; i < size; i++)
	{/*for the case where there is no address2 value, a placeholder/empty string is used.*/
		c = contacts[i];
		/*fprintf(FILE output, format, inputs for format); \t = TAB*/
		exportFile <<c.GetAll()<<endl;

	}
	exportFile.close();
}
