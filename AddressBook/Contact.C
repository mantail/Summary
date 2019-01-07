#include <iostream>
#include <string>
#include <sstream>
#include "Contact.h"
#include "Auxillary.h"

using namespace std;

Contact::Contact()
{/*Default constructor. Sets all variables to an empty string.*/
	this->first_name = "*";
	this->last_name = "*";
	this->phone_number = "*";
	this->address1 = "*";
	this->address2 = "*";
	this->city = "*";
	this->state = "*";
	this->zipcode = "*";
}
Contact::Contact(std::string first_name, std::string last_name, std::string phone_number,
		std::string address1, std::string address2,
		std::string city, std::string state, std::string zipcode)
{/*Constructor that sets all of the object variables on object creation.*/
	this->first_name = first_name;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->address1 = address1;
	this->address2 = address2;
	this->city = city;
	this->state = state;
	this->zipcode = zipcode;
}
	/*Setters*/
void Contact::SetFirstName(std::string s){this -> first_name = s;}
void Contact::SetLastName(std::string s){this -> last_name = s;}
void Contact::SetAddress1(std::string s){this -> address1 = s;}
void Contact::SetAddress2(std::string s){this -> address2 = s;}
void Contact::SetCity(std::string s){this -> city = s;}
void Contact::SetState(std::string s){this -> state = s;}
void Contact::SetZipcode(std::string s){this -> zipcode = (s);}
void Contact::SetPhoneNumber(std::string s){this -> phone_number = (s);}

bool Contact::operator<(const Contact &other) const
{
	int compared;
	switch(sortCriteria)
	{
		case LAST_NAME:
			compared = this->last_name.compare(other.GetLastName());
			break;
		case ZIP:
			compared = this->zipcode.compare(other.GetZipcode());
			break;
		case ADDRESS1:
			compared = this->address1.compare(other.GetAddress1());
			break;
		default:
			/*throw unrecognized sort error thats caught up the chain*/
			break;
	}
	if(compared > 0)
	{
		return false;
	}
	else if(compared < 0)
	{
		return true;
	}
	else
	{
		int tieBreaker = this->first_name.compare(other.GetFirstName());  //tie breaker is dependent on first name, so return first name cmp'd value
		if(tieBreaker > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false; //should never reach this line, but it could prevent weird errors
}

bool Contact::operator==(const Contact &other) const
{
	//compares string of concatenated variables (easier than doing it for each one)
	int compared;
	for(vector<SearchCriteria>::const_iterator searchIt= searchCriteria.begin(); searchIt < searchCriteria.end(); searchIt++)
	{
		switch(*searchIt)
		{
			case LAST_NAME:
				compared = this->last_name.compare(other.GetLastName());
				break;
			case FIRST_NAME:
				compared = this->first_name.compare(other.GetFirstName());
				break;
			case ZIP:
				compared = this->zipcode.compare(other.GetZipcode());
				break;
			case ADDRESS1:
				compared = this->address1.compare(other.GetAddress1());
				break;
			case ADDRESS2:
				compared = this->address2.compare(other.GetAddress2());
				break;
			case CITY:
				compared = this->city.compare(other.GetCity());
				break;
			case STATE:
				compared = this->state.compare(other.GetState());
				break;
			case PHONE:
				compared = this->phone_number.compare(other.GetPhoneNumber());
				break;
			default:
				/*throw unrecognized sort error thats caught up the chain*/
				break;
		}
		if(compared != 0)
		{
			return false;
		}
	}
	return true;
}
