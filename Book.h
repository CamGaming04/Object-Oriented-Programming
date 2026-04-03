#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Book
{
public:
	string title, genre;
	int id, reservedSize, borrowedSize;
	char firstLetter;
	bool borrowed = false;
	bool reserved = false;
	int authorID;
	vector<User*> borrowedList;
	vector<User*> reservedList;

	void addReservedList(User* activeUser);

	void addBorrowedList(User* activeUser);

	Book() = default;

	Book(string bTitle, int bAuthorID, string bGenre, int bId)
	{
		title = bTitle;
		authorID = bAuthorID;
		genre = bGenre;
		id = bId;
		reservedSize = 0;
		borrowedSize = 0;
		firstLetter = title.front();
	}
};