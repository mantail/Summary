#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H


#include <string>
#include <vector>
#include "Book.h"

class AddressBook
{
	/*The main structure that adds, deletes, and calls for searches for addresses
	 in the storage.(will be) Capable of uploading a file to create the book or
	 a new one. Switching between sort/display methods is called for from here.
	Methods are usually called upon a button press in GUI.*/

	private:
		int SavedStatus; 			//tells if there are any unsaved books in the Album

		Book *CurrentOpenBook; 		//pointer to the current Book

	public:
		AddressBook();
		AddressBook(std::string filename);
		~AddressBook();

		Book *GetCurrentBook(void){return CurrentOpenBook;};
		int GetSaveStatus(void){return SavedStatus;};

		void AddSearchCriteria(SearchCriteria newCrit){searchCriteria.push_back(newCrit);};
		void SetBook(Book *book){CurrentOpenBook=book;};
		void SetSaveStatus(int newStatus){SavedStatus=newStatus;};
		void SetSort(SearchCriteria newSortCriteria);

		void AddContact(Contact contact); 	//grabs from textbox, adds to current book
		void ClenseSearch(void);		//empties searchCriteria
	  void RemoveContact(Contact contact); 	//grabs from textbox, removes from current book if exists
		void EditContact(Contact contactToEdit, std::vector<std::pair<int,std::string> > newContactInfo);
		std::vector<Contact> SearchContacts(Contact contact); //searches the Book for the address, result is placed in a text box.
		void SortContacts(void);
		void SetSortBy(SearchCriteria newCriteria);

//		void CreateBook(void); 				//makes a new blank Book, increments TotalBooks
//		void RemoveBook(Book *book);			//delete file from the system
		void CreateBook(std::string filename); 				//makes a new blank Book, increments TotalBooks
		void CreateBook(void);
		void RemoveBook(Book *book);
		void SwapOpenBook(Book *newBook);

		std::vector<Contact> LoadBook(std::string filename);

		std::vector<std::string> split(std::string line, char delimeter);
		std::vector<Contact> ImportBook(std::string filename);
		void ExportBook(void);

		void SaveBook(void);	//writes the books to a file/files
		void SaveLastBook(void);
		void LoadLastBook(void);

};
#endif
