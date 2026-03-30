#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Book
{
public:
	string title, author, genre;
	int id, reservedSize, borrowedSize;
	char firstLetter;
	bool borrowed = false;
	bool reserved = false;
	vector<User*> borrowedList;
	vector<User*> reservedList;

	void addReservedList(User* activeUser);

	void addBorrowedList(User* activeUser);

	Book(string bTitle, string bAuthor, string bGenre, int bId)
	{
		title = bTitle;
		author = bAuthor;
		genre = bGenre;
		id = bId;
		reservedSize = 0;
		borrowedSize = 0;
		firstLetter = title.front();
	}
};