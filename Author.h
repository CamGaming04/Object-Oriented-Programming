#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class Author : public Book
{
public:
	string authorName;
	int authorID;
	int authorBooksSize;
    vector<Book*> authorBooks;

	Author(string authName, int authID)
	{
		authorName = authName;
		authorID = authID;
		authorBooksSize = 0;
	}
};