#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include "Auxillary.h"


class Contact
{
	private:
		std::string first_name, last_name, phone_number,
		address1, address2,
		city, state, zipcode;

	public:
	/*CONSTRUCTORS AND DECONSTRUCTORS*/
	Contact();
	Contact(std::string first_name, std::string last_name, std::string phone_number,
		std::string address1, std::string address2,
		 std::string city, std::string state, std::string zipcode);

	/*GETTERS*/
	std::string GetFirstName(void) const {return first_name;};
	std::string GetLastName(void) const {return last_name;};
	std::string GetPhoneNumber(void) const{return phone_number;};
	std::string GetAddress1(void) const{return address1;};
	std::string GetAddress2(void) const{return address2;};
	std::string GetCity(void) const{return city;};
	std::string GetState(void) const{return state;};
	std::string GetZipcode(void)const{return zipcode;};
	std::string GetAll(void) const{return first_name+'\t'+last_name+'\t'+phone_number
	+'\t'+address1+'\t'+address2+'\t'+city+'\t'+state+'\t'+zipcode;};
	//Returns a string of concatenated Contact variables

	//Get Char*
	const char* GetCharFirstName(void) const {return first_name.c_str();};
	const char* GetCharLastName(void) const {return last_name.c_str();};
	const char* GetCharPhoneNumber(void) const{return phone_number.c_str();};
	const char* GetCharAddress1(void) const{return address1.c_str();};
	const char* GetCharAddress2(void) const{return address2.c_str();};
	const char* GetCharCity(void) const{return city.c_str();};
	const char* GetCharState(void) const{return state.c_str();};
	const char* GetCharZipcode(void)const{return zipcode.c_str();};

	/*SETTERS*/
	void SetFirstName(std::string s);
	void SetLastName(std::string s);
	void SetPhoneNumber(std::string s);
	void SetAddress1(std::string s);
	void SetAddress2(std::string s);
	void SetCity(std::string s);
	void SetState(std::string s);
	void SetZipcode(std::string s);

	/*Other Functions*/
	bool operator<(const Contact&other) const;
	bool operator==(const Contact &other) const; //Added for search feature
};
#endif /* end of include guard:  */
