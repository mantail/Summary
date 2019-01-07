#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Contact.h"
#include "AddressIO.h"



using namespace std;

int main (int argc, char *argv[]){

  if(argc < 2)
  {
    cout << "What are you testing? Specify a file..." << endl;
  }
  vector<Contact> cvector;
  cvector = Import(argv[1]);

  cout << "Test Get(Var)" << endl;
  for(int i = 0; i<cvector.size(); i++)
  {
    cout << cvector[i].GetFirstName() << "\t";
    cout << cvector[i].GetLastName() << "\t";
    cout << cvector[i].GetPhoneNumber() << "\t";
    cout << cvector[i].GetAddress1() << "\t";
    cout << cvector[i].GetAddress2() << "\t";
    cout << cvector[i].GetCity() << "\t";
    cout << cvector[i].GetState() << "\t";
    cout << cvector[i].GetZipcode() << "\t\n";

  }
  cout << "Test GetChar(Var)" << endl;
  for(int i = 0; i<cvector.size(); i++)
  {
    cout << cvector[i].GetCharFirstName() << "\t";
    cout << cvector[i].GetCharLastName() << "\t";
    cout << cvector[i].GetCharPhoneNumber() << "\t";
    cout << cvector[i].GetCharAddress1() << "\t";
    cout << cvector[i].GetCharAddress2() << "\t";
    cout << cvector[i].GetCharCity() << "\t";
    cout << cvector[i].GetCharState() << "\t";
    cout << cvector[i].GetCharZipcode() << "\n";
  }
  cout << "Test iterator" << endl;
  for (std::vector<Contact>::iterator it = cvector.begin() ; it != cvector.end(); ++it)
    std::cout << (*it).GetAll() << std::endl;
  cout << "Test GetAll()" << endl;
  for(int i = 0; i<cvector.size(); i++)
  {
      cout << cvector[i].GetAll() << endl;
  }
  if(argc == 3)
  {
    cout << "Test Export(default to cout)" << endl;
    Export(cvector);
    cout << "Test Export to specified output: "<< argv[2] << endl;
    Export(cvector,argv[2]);
  }
  if(cvector[0]==cvector[0])
  {
    cout << cvector[0].GetFirstName() << " is the same contact as "
    << cvector[0].GetFirstName() << endl;
  }
  else
  {
    cout << cvector[0].GetFirstName() << " is the *NOT* same contact as "
    << cvector[1].GetFirstName() << endl;
  }
  return 0;
}
