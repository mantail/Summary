#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Auxillary.h"
#include "AddressIO.h"
#include "AddressBook.h"
#include "Contact.h"
#include "Book.h"

using namespace std;

int main (int argc, char *argv[]){
  if(argc < 2)
  {
    cout << "What are you testing? Specify a file..." << endl;
    return 1;
  }
  AddressBook testAddBook;
  testAddBook.LoadBook(argv[1]);
  vector<Contact> cvector;
  cvector = testAddBook.GetCurrentBook()->GetContacts();
  cout << "Pre Sort" << endl << endl;
  for(int i=0;i<cvector.size();i++)
  {
    cout << cvector[i].GetAll() << endl;
  }
  string filename="testout.txt";
  testAddBook.SortContacts();
  testAddBook.GetCurrentBook()->SetFileName(filename);
  cvector = testAddBook.GetCurrentBook()->GetContacts();
  cout << "Post Sort" << endl << endl;
  for(int i=0;i<cvector.size();i++)
  {
    cout << cvector[i].GetAll() << endl;
  }
  testAddBook.ExportBook();
  return 0;
}
