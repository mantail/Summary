#include <stdio.h>
#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;

int main(int argc, char **argv) {
        //start with initializing everything to NULL
        Contact *newContact = new Contact();

        //check initialization of first name
        if(newContact -> GetFirstName().compare("") != 0) {
                fprintf(stderr, "First name initialization error\n");
        }

        //Set first and last name to different value
        string fname = "Joe";
        string lname = "Sventek";
        string phone = "11122333";
        string address1 = "111 1st st";
        string address2 = "222 2nd st";
        string city = "Eugene";
        string state = "OR";
        string zip = "97401";

        newContact -> SetFirstName(fname);
        newContact -> SetLastName(lname);

        //check first name reinitialization
        if(newContact -> GetFirstName().compare("Joe") != 0) {
                fprintf(stderr, "Set First name error\n");
        }
        //check last name reinitialization
        if(newContact -> GetLastName().compare("Sventek") != 0) {
                fprintf(stderr, "Set Last name error\n");
        }

        //check phone number reinitialization
        newContact -> SetPhoneNumber(phone);
        if(newContact -> GetPhoneNumber().compare("11122333") != 0) {
                fprintf(stderr, "Set Phone number error\n");
        }

        //check address 1 reinitialization
        newContact -> SetAddress1(address1);
        if(newContact -> GetAddress1().compare("111 1st st") != 0) {
                fprintf(stderr, "Set Address 1 error\n");
        }

        //check address 2 reinitialization
        newContact -> SetAddress2(address2);
        if(newContact -> GetAddress2().compare("222 2nd st") != 0) {
                fprintf(stderr, "Set Address 2 error\n");
        }

        //check city reinitialization
        newContact -> SetCity(city);
        if(newContact -> GetCity().compare("Eugene") != 0) {
                fprintf(stderr, "Set City error\n");
        }

        //check state reinitialization
        newContact -> SetState(state);
        if(newContact -> GetState().compare("OR") != 0) {
                fprintf(stderr, "Set State error\n");
        }

        //check zipcode reinitialization
        newContact -> SetZipcode(zip);
        if(newContact -> GetZipcode().compare("97401") != 0) {
                fprintf(stderr, "Set Zipcode error\n");
        }

        delete newContact;
}
