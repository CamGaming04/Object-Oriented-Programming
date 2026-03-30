#include "Book.h"

void Book::addReservedList(User* activeUser)
{
	reservedList.resize(reservedSize + 1);
	reservedList[reservedSize] = activeUser;
	reservedSize += 1;
}

void Book::addBorrowedList(User* activeUser)
{
	borrowedList.resize(borrowedSize + 1);
	borrowedList[borrowedSize] = activeUser;
	borrowedSize += 1;
}
