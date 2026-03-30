#include "User.h"

void User::takeOutBook(int bookID)
{
	bookList.resize(bookLocation + 1);
	bookList[bookLocation] = bookID;
	bookLocation += 1;
}

void User::returnBook()
{

}

void User::reserveBook()
{

}






