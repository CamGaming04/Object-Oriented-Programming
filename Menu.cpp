#include "Menu.h"


void Menu::logInMenu()
{
	int input;
	string tempAName;
	string tempPWord;
	User* user = nullptr;
	mLibrary->currentUser = mLibrary->placeholderUser;
	cout << "Welcome to the Library System" << endl << "1. Log In" << endl << "2. Create Account" << endl;
	cin >> input;
	switch(input)
	{
	case 1:
		cout << "Please input your account name" << endl;
		cin >> tempAName;
		cout << "Please input your password" << endl;
		cin >> tempPWord;
		user = mLibrary->findUser(tempAName);
		if (user == nullptr)
		{
			//account not found logic done in the findUser function, won't actually get returned with this
		}
		else
		{
			mLibrary->logIn(tempAName, tempPWord);
			if (mLibrary->userReturn == 0)
			{
				loggedInMenu();
			}
		}
		break;
	case 2:
		mLibrary->createUser();
		logInMenu();
		break;
	default:
		cout << "Please input either 1 or 2" << endl;
	}
}

void Menu::takeOutBookMenu()
{

}

void Menu::browseMenu()
{
	int input = 0;
	int input1 = 0;
	int authNum = 0;
	string authInp;
	string titleInput;
	Book* book = nullptr;
	vector<string> auth;
	vector<string>::iterator ip;
	cout << "Browse Library" << endl;
	cout << "How would you like to search?" << endl;
	cout << "1. Browse all books" << endl;
	cout << "2. By Author" << endl;
	cout << "3. By Keyword" << endl;
	cout << "4. By Genre" << endl;
	cout << "5. By Letter" << endl;
	cout << "6. By Title" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		//show all books (in ID order)
		for (Book* book : mLibrary->bookList)
		{
			cout << book->title << endl << book->author << endl << book->genre << endl << endl;
		}
		break;
	case 2:
		//show all authors, show books by chosen author
		for (Book* book : mLibrary->bookList)
		{
			auth[authNum] = book->author;
			authNum += 1;
		}
		sort(auth.begin(), auth.end());
		ip = unique(auth.begin(), auth.end());
		auth.resize(distance(auth.begin(), ip));
		for (string str : auth)
		{
			cout << str << endl;
		}
		cout << "Please input the Author you are looking for" << endl;
		cin >> authInp;
		for (Book* book : mLibrary->bookList)
		{
			if (authInp == book->author)
			{
				cout << book->title << endl << book->author << endl << book->genre << endl << endl;
			}
		}
		break;
	case 3:
		//ask for keyword, show all books including keyword
		break;
	case 4:
		// show all genres, show books in chosen genre
		break;
	case 5:
		//ask for starting letter, show all books under that letter
		break;
	case 6:
		cout << "Please input the Title of the Book you are looking for" << endl;
		cin >> titleInput;
		book = mLibrary->findBookTitle(titleInput);
		if (book == nullptr)
		{
			//done in findBookTitle
		}
		else
		{
			cout << "Book found" << endl << "What would you like to do?" << endl;
			cout << "1. Take out Book" << endl;
			cout << "2. Reserve Book" << endl;
			cout << "3. Go Back" << endl;
			switch (input1)
			{
			case 1:
				mLibrary->currentUser->takeOutBook(book->title);
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				cout << "Please input 1, 2 or 3" << endl;
			}
		}
		break;
	default:
		cout << "Please input 1, 2, 3, 4 or 5" << endl;
	}
}

void Menu::returnBookMenu()
{

}

void Menu::loggedInMenu()
{
	int input;
	cout << "What would you like to do today?" << endl;
	cout << "1. Take Out A Book" << endl << "2. Browse Library" << endl << "3. Return Book" << endl << "4. Log Out" << endl;
	cin >> input;
	switch (input)
	{
		case 1:
			takeOutBookMenu();
			break;
		case 2:
			browseMenu();
			break;
		case 3:
			returnBookMenu();
			break;
		case 4:
			mLibrary->logOut();
			if (mLibrary->userReturn == 1)
			{
				logInMenu();
			}
			break;
		default:
			cout << "Please input 1, 2, 3 or 4" << endl;
	}
}


