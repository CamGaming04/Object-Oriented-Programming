#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class User 
{
public:
	string forename, surname, accountName, password, userID;
	int location, bookLimit;
	char first_char;

	void takeOutBook(string bookTitle);

	void returnBook();

	void reserveBook();

	User(string fName, string sName, string pword, int loc)
	{
		forename = fName;
		surname = sName;
		password = pword;
		location = loc;
		string loca = to_string(loc);
		userID = location;
		bookLimit = 5;
		first_char = forename.front();
		accountName = first_char + surname + loca;
		cout << accountName << endl;
	}
};
