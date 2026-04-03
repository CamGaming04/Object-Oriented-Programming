#pragma once
#include "Author.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library
{
public:
	Library* lLibrary;
	int userReturn = 0;
	double lateCharges;
	User* currentUser;
	User* placeholderUser;
	vector<User*> userList;
	Book* placeholderBook;
	vector<Book*> bookList;
	vector<Author*> authorList;
	void addUser();
	void addUserInit(string fname, string sname, string pword, int access);
	void setCurrentUser(User* user);
	User* findUser(string accName);
	Author* getAuthor(Book* book);
	void getUserBookList(User* user);
	Book* findBookTitle(string bookTitle);
	void createUser();
	void createLibrarian();
	void createAdmin();
	void addBook();
	void addBookByAuthor(int authID);
	void addAuthor();
	void addAuthorInit(string authName);
	void addBookInit(string tempTitle, int tempAuthorID, string tempGenre);
	void logIn(string inputAccountName, string inputPassword);
	void logOut();
	void addBookToAuthor();

	Library()
	{
		currentUser = nullptr;
		placeholderBook = nullptr;
		placeholderUser = nullptr;
		lLibrary = nullptr;
		lateCharges = 0.50;
	}
};





