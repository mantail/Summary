#include <string>
#include <iostream>
#include <fstream>
#include "Book.h"
#include "Contact.h"

using namespace std;

/*for this little test, I try to use a txt file which is tab separated;
read each line of the file and add them to the book, then sort it.
the purpose for this is to check the sort functions correctly and the time 
spent is not over the limit 500ms*/

int main (int argc, char *argv[]){
    ifstream file(argv[1]);
    new Book book1;
    string str;
    while (getline(file, str, '\t')){
        Contact temp;
        temp.setFirstName(str[0]);
        temp.setLastName(str[1]);
        temp.setAddress1(str[2]);
        temp.setAddress2(str[3]);
        temp.setCity(str[4]);
        temp.setState(str[5]);
        temp.setZipcode(str[6]);
        temp.setPhoneNumber(str[7]);

        
        book1.AddContact(Contact temp);
    }

    book1.SortContacts();
    
}