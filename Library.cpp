#include "Library.h"

int bookID = 0;
User* currentUser = nullptr;

void Library::addUser(const User& userList)
{

}

void Library::setCurrentUser(User* user)
{
    currentUser = user;
}

void Library::createUser()
{
    int userLocation = 0;
    string tempFName;
    string tempSName;
    string tempPWord;
    cout << "Please input your Forename" << endl;
    cin >> tempFName;
    cout << "Please input your Surname" << endl;
    cin >> tempSName;
    cout << "Please input your Password" << endl;
    cin >> tempPWord;
    userList.resize(userLocation + 1);
    userList[userLocation] = new User(tempFName, tempSName, tempPWord, userLocation);
    cout << "Account Created Successfully. Please Proceed to Log In." << endl;
    userLocation += 1;
}

void Library::addBook()
{
    string tempTitle, tempAuthor, tempGenre;
    cout << "Please input book Title" << endl;
    cin >> tempTitle;
    cout << "Please input book Author" << endl;
    cin >> tempAuthor;
    cout << "Please input book Genre" << endl;
    cin >> tempGenre;
    bookList.resize(bookID + 1);
    bookList[bookID] = new Book(tempTitle, tempAuthor, tempGenre, bookID);
    cout << "Book Added Successfully" << endl;
    bookID += 1;
}

void Library::addBookInit(string tempTitle, string tempAuthor, string tempGenre)
{
    bookList.resize(bookID + 1);
    bookList[bookID] = new Book(tempTitle, tempAuthor, tempGenre, bookID);
    bookID += 1;
}

User* Library::findUser(string accName)
{
	for (User* user : userList)
	{
		if (accName == user->accountName)
		{
			return user;
		}
		else
		{
			cout << "Account not found" << endl;
            return placeholderUser;
		}
	}
}

Book* Library::findBookTitle(string bookTitle)
{
    for (Book* book : bookList)
    {
        if (bookTitle == book->title)
        {
            return book;
        }
        else
        {
            cout << "Book not found" << endl;
            return placeholderBook;
        }
    }
}

void Library::logIn(string inputAccountName, string inputPassword)
{
    
    for (User* user : lLibrary->userList)
    {
        if (user->accountName == inputAccountName && user->password == inputPassword)
        {
            cout << "User " << user->userID << " has been logged in successfully" << endl;
            lLibrary->currentUser = user;
            lLibrary->userReturn = 0;
        }
        else
        {
            cout << "User name or password incorrect" << endl;
        }
    }
}

void Library::logOut()
{
    lLibrary->currentUser = lLibrary->placeholderUser;
    lLibrary->userReturn = 1;
}