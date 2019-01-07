#ifndef BOOK_H
#define BOOK_H
#include <vector>
#include <string>
#include <stdio.h>
#include "Auxillary.h"
#include "Contact.h"

class Book
{
  private:
	std::vector<Contact> contacts;
	std::string FileName;

  public:
	/*CONSTRUCTORS AND DECONSTRUCTORS*/
	Book();
	Book(std::string file);
	~Book();

	/*GETTERS*/
	std::vector<Contact> GetContacts(void){return contacts;};
	Contact GetOneContact(int index){return contacts[index];};
	std::string GetFileName(void){return FileName;};

	/*SETTERS*/
	void SetContacts(std::vector<Contact> newContacts){contacts = newContacts;};
	void SetContact(Contact newContact, int index){contacts[index] = newContact;};
  void SetFileName(std::string name){FileName = name;};
  
	/*FEATURES*/
	void AddContact(Contact newContact);
	void DeleteContact(int index);
	void DeleteContact(Contact contact); //dummy overload
	void EditContact(Contact contactToEdit, std::vector<std::pair<int,std::string> > newContactInfo);

  void SortContacts();

  int ContactSearch(Contact contact); //returns position
  std::vector<Contact>FindMatches(Contact contact);
  int Binary_Search(int start, int end, Contact contact); //returns position

};
#endif /* end of include guard:  */
