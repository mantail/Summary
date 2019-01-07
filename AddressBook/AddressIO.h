#ifndef ADDRESSIO_H
#define ADDRESSIO_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Contact.h"

std::vector<std::string> split(std::string line, char delimeter)
{
    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> splitStr;
    while (getline(ss, word, delimeter))
    {
       splitStr.push_back(word);
    }
    return splitStr;
}
std::vector<Contact> Import(std::string filename)
{
	/*opens a file and reads every line into a
	vector<string>. returns that vector.*/
	std::ifstream importFile;
	std::string line;
	std::vector<Contact> contacts;

	importFile.open(filename.c_str(), std::ios::in);

	while(getline(importFile,line,'\n'))
  {
    std::vector<std::string> parsedLine = split(line,'\t');
    Contact temp = Contact();

    temp.SetFirstName(parsedLine[0]);
    temp.SetLastName(parsedLine[1]);
    temp.SetPhoneNumber(parsedLine[2]);
    temp.SetAddress1(parsedLine[3]);
    temp.SetAddress2(parsedLine[4]);
    temp.SetCity(parsedLine[5]);
    temp.SetState(parsedLine[6]);
    temp.SetZipcode(parsedLine[7]);

    contacts.push_back(temp);
  }
	return contacts;
}
void Export(std::vector<Contact> contacts, std::string filename="cout")
{/*Called when the user wishes to save the file. A filename MUST be prompted
	or saved previously and then passed to this function. writes the contacts to
	 a file where each line is a list of tab seperated values*/
	Contact *c;
	if(filename.compare("cout")==0)
	{
		int size = contacts.size();

		for (int i = 0; i < size; i++)
		{/*for the case where there is no address2 value, a placeholder/empty string is used.*/
			c = &contacts[i];
			/*fprintf(FILE output, format, inputs for format); \t = TAB*/
			std::cout <<c->GetAll()<<std::endl;

		}
	}
	std::ofstream exportFile;
	exportFile.open(filename.c_str(), std::ios::out);

	int size = contacts.size();

	for (int i = 0; i < size; i++)
	{/*for the case where there is no address2 value, a placeholder/empty string is used.*/
		c = &contacts[i];
		/*fprintf(FILE output, format, inputs for format); \t = TAB*/
		exportFile <<c->GetAll()<<std::endl;

	}
	exportFile.close();
}
#endif
