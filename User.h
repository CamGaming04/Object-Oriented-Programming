#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User 
{
public:
	string forename, surname, accountName, password;
	int location, bookLimit, accessLevel, userID;
	double lateCharges;
	char first_char;
	vector<int> bookList;
	int bookLocation = 0;

	void takeOutBook(int bookID);



	//User
		//checkUserDetails
		//changePassword?

	//Librarian
	    //promoteUser
		//addBook
		//addAuthor
		//removeBook
		//removeAuthor
		//checkLateFees
		//addUser
		//removeUser
		//checkReservations/borrowedList

	//Admin
		//promoteLibrarian
		//demoteLibrarian
		//demoteUser
		//changeLibraryRules(LateFees, BorrowLimits)
	User(string fName, string sName, string pword, int loc, int access)
	{
		forename = fName;
		surname = sName;
		password = pword;
		location = loc;
		lateCharges = 0;
		string loca = to_string(loc);
		userID = location;
		bookLimit = 5;
		first_char = forename.front();
		accountName = first_char + surname + loca;
		cout << accountName << endl;
		accessLevel = access;
	}
};
