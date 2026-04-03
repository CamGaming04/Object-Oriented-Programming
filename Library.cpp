#include "Library.h"

int bookID = 0;
int authorID = 0;
int userLocation = 0;
User* currentUser = nullptr;

void Library::addUser()
{
    string fname, sname, pword;
    cout << "Input Forename" << endl;
    cin >> fname;
    cout << "Input Surname" << endl;
    cin >> sname;
    cout << "Input Password" << endl;
    cin >> pword;
    userList.resize(userLocation + 1);
    userList[userLocation] = new User(fname, sname, pword, userLocation, 1);
    cout << "Account Created Successfully" << endl;
    cout << "User's account name is " << userList[userLocation]->accountName << endl;
    userLocation += 1;
}

void Library::addUserInit(string fname, string sname, string pword, int access)
{
    userList.resize(userLocation + 1);
    userList[userLocation] = new User(fname, sname, pword, userLocation, access);
    userLocation += 1;
}
void Library::setCurrentUser(User* user)
{
    currentUser = user;
}

void Library::createUser()
{
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
    userList[userLocation] = new User(tempFName, tempSName, tempPWord, userLocation, 1);
    cout << "Account Created Successfully. Please Proceed to Log In." << endl;
    userLocation += 1;
}

void Library::createLibrarian()
{

}

void Library::createAdmin()
{

}

void Library::addBook()
{
    string tempTitle, tempGenre;
    int tempAuthorID;
    cout << "Please input book Title" << endl;
    cin >> tempTitle;
    cout << "Please input book Author ID number" << endl;
    cin >> tempAuthorID;
    cout << "Please input book Genre" << endl;
    cin >> tempGenre;
    bookList.resize(bookID + 1);
    bookList[bookID] = new Book(tempTitle, tempAuthorID, tempGenre, bookID);
    for (Author* author : authorList)
    {
        if (author->authorID == tempAuthorID)
        {
            author->authorBooks.resize(author->authorBooksSize + 1);
            author->authorBooks[author->authorBooksSize] = bookList[bookID];
            author->authorBooksSize += 1;
        }
    }
    cout << "Book added successfully" << endl;
    bookID += 1;
}

void Library::addBookByAuthor(int authID)
{
    string tempTitle, tempGenre;
    cout << "Please input book Title" << endl;
    cin >> tempTitle;
    cout << "Please input book Genre" << endl;
    cin >> tempGenre;
    bookList.resize(bookID + 1);
    bookList[bookID] = new Book(tempTitle, authID, tempGenre, bookID);
    for (Author* author : authorList)
    {
        if (author->authorID == authID)
        {
            author->authorBooks.resize(author->authorBooksSize + 1);
            author->authorBooks[author->authorBooksSize] = bookList[bookID];
            author->authorBooksSize += 1;
        }
    }
    cout << "Book added successfully" << endl;
    bookID += 1;
}
void Library::addAuthor()
{
    string tempName;
    int input;
    cout << "Please input author Name" << endl;
    cin >> tempName;
    authorList.resize(authorID + 1);
    authorList[authorID] = new Author(tempName, authorID);
    cout << "Author added successfully" << endl;
    authorID += 1;
    cout << "Would you like to add any books for this Author?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> input;
    switch (input)
    {
    case 1:
        addBookByAuthor(authorID - 1);
        break;
    case 2:
        //go back to Librarian/Admin menu
        break;
    default:
        cout << "Please input 1 or 2" << endl;
    }
}

void Library::addAuthorInit(string authName)
{
    authorList.resize(authorID + 1);
    authorList[authorID] = new Author(authName, authorID);
    authorID += 1;
}

void Library::addBookInit(string tempTitle, int tempAuthorID, string tempGenre)
{
    bookList.resize(bookID + 1);
    bookList[bookID] = new Book(tempTitle, tempAuthorID, tempGenre, bookID);
    for (Author* author : authorList)
    {
        if (author->authorID == tempAuthorID)
        {
            author->authorBooks.resize(author->authorBooksSize + 1);
            author->authorBooks[author->authorBooksSize] = bookList[bookID];
            author->authorBooksSize += 1;
        }
    }
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

Author* Library::getAuthor(Book* book)
{
    for (Author* author : authorList)
    {
        if (author->authorID == book->authorID)
        {
            return author;
        }
    }
}

void Library::getUserBookList(User* user)
{
    for (int book : user->bookList)
    {
        for (Book* bookP : bookList)
        {
            if (book == bookP->id)
            {
                for (Author* author : authorList)
                {
                    if (bookP->authorID == author->authorID)
                    {
                        cout << bookP->title << endl << author->authorName << endl << bookP->genre << endl << endl;
                    }
                }
            }
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