#pragma once
#include "Book.h"
#include "User.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library
{
public:
	Library* lLibrary;
	int userReturn = 0;
	User* currentUser;
	User* placeholderUser;
	vector<User*> userList;
	Book* placeholderBook;
	vector<Book*> bookList;
	void addUser(const User& userList);
	void setCurrentUser(User* user);
	User* findUser(string accName);
	void getUserBookList(User* user);
	Book* findBookTitle(string bookTitle);
	void createUser();
	void addBook();
	void addBookInit(string tempTitle, string tempAuthor, string tempGenre);
	void logIn(string inputAccountName, string inputPassword);
	void logOut();

	Library()
	{
		currentUser = nullptr;
		placeholderBook = nullptr;
		placeholderUser = nullptr;
		lLibrary = nullptr;
	}
};





