#include "User.h"

void User::takeOutBook(int bookID)
{
	bookList.resize(bookLocation + 1);
	bookList[bookLocation] = bookID;
	bookLocation += 1;
}








