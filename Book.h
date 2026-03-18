#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
public:
	string title, author, genre;
	int id;
	char firstLetter;
	bool borrowed = false;
	bool reserved = false;

	Book(string bTitle, string bAuthor, string bGenre, int bId)
	{
		title = bTitle;
		author = bAuthor;
		genre = bGenre;
		id = bId;
		firstLetter = title.front();
	}
};