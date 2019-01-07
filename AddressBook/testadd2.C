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
    AddressBook testaddr; ///create a address book for testing
    
    testaddr.ImportBook ("test1000.txt") ///testing import function
    if (testaddr.getSaveStatus() == UNSAVED){
        cout << "import book success" << endl;
    }
    else{
        cout << "import book failed" << endl;
        return 0;
    }

    testaddr.CreateBook("testtemp.txt") ///testing create function
    vector temptestOne = testaddr.getAlbum();
    if (temptestOne.size() == 2){
        cout << "create new book success" << endl;
    }
    else{
        cout << "create new book failed" << endl;
        return 0;
    }

    ifstream filename("test100.txt");//use a local file to text the add contact
    while(getline(filename,line,'\n')){
        vector<string> parsedLine = split2(line,'\t');
        Contact temp;

        temp.setFirstName(parsedLine[0]);
        temp.setLastName(parsedLine[1]);
        temp.setPhoneNumber(parsedLine[2]);
        temp.setAddress1(parsedLine[3]);
        temp.setAddress2(parsedLine[4]);
        temp.setCity(parsedLine[5]);
        temp.setState(parsedLine[6]);
        temp.setZipcode(parsedLine[7]);

        testaddr.AddContact(&temp);
    }
    for(int i = 0; i<testaddr.getCurrentBook()->GetContacts().size(); i++){
        cout << testaddr.getCurrentBook()->GetContacts()[i].getFirstName() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getLastName() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getPhoneNumber() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getAddress1() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getAddress2() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getCity() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getState() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getZipcode() << "\t\n";
    }
    ///because the file size is 100, so there should be exactly 100 contacts 
    ///in the current book
    if (testaddr.getCurrentBook()->GetContacts().size() == 100){
        cout << "add contact success" << endl;
    }    
    else{
        cout << "add contact failed" << endl;
        return 0;
    }

    vector removeones = testaddr.SearchContacts(testaddr.getCurrentBook()->GetContacts()[2]);
    if (removeones.size() > 0){
        cout << "search contact success" << endl;
    }
    else{
        cout << "search contact failed" << endl;
        return 0;
    }

    for (int i = 0; i < removeones.size(); i++){
        testaddr.RemoveCurrentBook(removeones[i]);
    }

    if (testaddr.getCurrentBook()->GetContacts().size() < 100){
        cout << "remove contact success" << endl;
    }
    else{
        cout << "remove contact failed" << endl;
        return 0;
    }

    testaddr.CreateBook();

    vector temptestOne = testaddr.getAlbum();
    if (temptestOne.size() == 3){
        cout << "create new book void success" << endl;
    }
    else{
        cout << "create new book void failed" << endl;
        return 0;
    }

    ifstream filename2("test10.txt");//use a local file to text the add contact
    while(getline(filename2,line,'\n')){
        vector<string> parsedLine = split2(line,'\t');
        Contact temp;

        temp.setFirstName(parsedLine[0]);
        temp.setLastName(parsedLine[1]);
        temp.setPhoneNumber(parsedLine[2]);
        temp.setAddress1(parsedLine[3]);
        temp.setAddress2(parsedLine[4]);
        temp.setCity(parsedLine[5]);
        temp.setState(parsedLine[6]);
        temp.setZipcode(parsedLine[7]);

        testaddr.AddContact(&temp);
    }
    for(int i = 0; i<testaddr.getCurrentBook()->GetContacts().size(); i++){
        cout << testaddr.getCurrentBook()->GetContacts()[i].getFirstName() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getLastName() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getPhoneNumber() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getAddress1() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getAddress2() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getCity() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getState() << "\t";
        cout << testaddr.getCurrentBook()->GetContacts()[i].getZipcode() << "\t\n";
    }
    ///because the file size is 100, so there should be exactly 100 contacts 
    ///in the current book
    if (testaddr.getCurrentBook()->GetContacts().size() == 10){
        cout << "add contact case 2 success" << endl;
    }    
    else{
        cout << "add contact case 2 failed" << endl;
        return 0;
    }

    testaddr.SaveBook();
    if (getSaveStatus() == SAVED){
        cout << "save one book success" << endl;
    }
    else{
        cout << "save one book failed" << endl;
    }

    testaddr.RemoveBook(testaddr.getCurrentBook());
    vector temptestOne = testaddr.getAlbum();
    if (temptestOne.size() == 2){
        cout << "remove one book success" << endl;
    }
    else{
        cout << "remove one book failed" << endl;
    }



}

vector<string> split2(string line, char delimeter)
{
    stringstream ss(line);
    string word;
    vector<string> splitStr;
    while (std::getline(ss, word, delimeter))
    {
       splitStr.push_back(word);
    }
    return splitStr;
}
