#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Contact.h"
#include "Book.h"
#include "AddressIO.h"
using namespace std;

int main (int argc, char *argv[]){
  if(argc < 2)
  {
    cout << "What are you testing? Specify a file..." << endl;
    return 1;
  }
  Book *testbook = new Book;
  testbook->SetContacts(Import(argv[1]));

  vector<Contact> ctemp = testbook->GetContacts();
  testbook->DeleteContact(testbook->GetOneContact(0));
  cout << testbook->ContactSearch(testbook->GetOneContact(1));
  testbook->DeleteContact(testbook->GetOneContact(1));
  return 0;
}
