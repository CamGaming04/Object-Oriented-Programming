#include "Menu.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Menu::logInMenu()
{
	int input;
	string tempAName;
	string tempPWord;
	User* user = nullptr;
	mLibrary->currentUser = mLibrary->placeholderUser;
	cout << "Welcome to the Library System" << endl << "1. Log In" << endl << "2. Create Account" << endl;
	std::cin >> input;
	switch(input)
	{
	case 1:
		cout << "Please input your account name" << endl;
		std::cin >> tempAName;
		cout << "Please input your password" << endl;
		std::cin >> tempPWord;
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
	int idInput;
	int borrowedInp;
	int reservedInp;
	cout << "Please input the ID of the book you are interested in" << endl;
	cin >> idInput;
	for (Book* book : mLibrary->bookList)
	{
		if (book->id == idInput)
		{
			if (book->borrowed == true)
			{
				cout << "Book is currently borrowed. Would you like to be added to the waiting list?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> borrowedInp;
				switch (borrowedInp)
				{
				case 1:
					book->addBorrowedList(mLibrary->currentUser);
					break;
				case 2:
					break;
				default:
					cout << "Please input 1 or 2" << endl;
				}
			}
			else
			{
				cout << "Book is not currently borrowed. Would you like to take it out or reserve it?" << endl;
				cout << "1. Take Out Book" << endl;
				cout << "2. Reserve Book" << endl;
				cout << "3. Go Back" << endl;
				cin >> reservedInp;
				switch (reservedInp)
				{
				case 1:
					mLibrary->currentUser->takeOutBook(book->id);
					cout << "Book taken out successfully" << endl;
					book->borrowed = true;
					continueBrowsingMenu();
					break;
				case 2:
					book->addReservedList(mLibrary->currentUser);
					cout << mLibrary->currentUser->accountName << " added successfully to reservation list" << endl;
					book->reserved = true;
					continueBrowsingMenu();
					break;
				case 3:
					loggedInMenu();
					break;
				default:
					cout << "Please input 1, 2 or 3" << endl;
				}
			}
		}
	}
}

void Menu::browseMenu()
{
	int input = 0;
	int input1 = 0;
	int authNum = 0;
	int authInp;
	string genInp;
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
	std::cin >> input;
	switch (input)
	{
	case 1:
		//show all books (in ID order)
		for (Book* book : mLibrary->bookList)
		{
			cout << book->title << endl << mLibrary->getAuthor(book)->authorName << endl << book->genre << endl << book->id << endl << endl;
		}
		takeOutBookMenu();
		break;
	case 2:
		//show all authors, show books by chosen author
		for (Author* author : mLibrary->authorList)
		{
			cout << author->authorName << endl << author->authorID << endl << endl;
		}
		cout << "Please input the ID of the Author you are looking for" << endl;
		cin >> authInp;
		for (Author* author : mLibrary->authorList)
		{
			if (author->authorID == authInp)
			{
				for (Book* book : author->authorBooks)
				{
					cout << book->title << endl << author->authorName << endl << book->genre << endl << book->id << endl << endl;
				}
			}
		}
		takeOutBookMenu();
		break;
	case 3:
		//ask for keyword, show all books including keyword
		break;
	case 4:
		// show all genres, show books in chosen genre
		for (Book* book : mLibrary->bookList)
		{
			auth.resize(authNum + 1);
			auth[authNum] = book->genre;
			authNum += 1;
		}
		sort(auth.begin(), auth.end());
		ip = unique(auth.begin(), auth.end());
		auth.resize(distance(auth.begin(), ip));
		for (string str : auth)
		{
			cout << str << endl;
		}
		cout << "Please enter the Genre you are looking for" << endl;
		cin >> genInp;
		for (Book* book1 : mLibrary->bookList)
		{
			if (genInp == book1->genre)
			{
				for (Author* author : mLibrary->authorList)
				{
					if (book1->authorID == author->authorID)
					{
						cout << book1->title << endl << author->authorName << endl << book1->genre << endl << book1->id << endl << endl;
					}
				}
				takeOutBookMenu();
			}
		}
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
				if (mLibrary->currentUser->bookLimit != mLibrary->currentUser->bookLocation)
				{
					mLibrary->currentUser->takeOutBook(book->id);
					cout << "Book taken out successfully" << endl;
					continueBrowsingMenu();
				}
				else
				{
					cout << "Maximum amount of books taken out, please return one before taking another out" << endl;
					continueBrowsingMenu();
				}
				break;
			case 2:
				book->addReservedList(mLibrary->currentUser);
				cout << mLibrary->currentUser->accountName << " added successfully to reservation list" << endl;
				continueBrowsingMenu();
				break;
			case 3:
				loggedInMenu();
				break;
			default:
				cout << "Please input 1, 2 or 3" << endl;
			}
		}
		break;
	default:
		cout << "Please input 1, 2, 3, 4, 5 or 6" << endl;
	}
}

void Menu::continueBrowsingMenu()
{
	int browseInp = 0;
	cout << "Would you like to keep browsing?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> browseInp;
	switch (browseInp)
	{
	case 1:
		browseMenu();
		break;
	case 2:
		loggedInMenu();
		break;
	default:
		cout << "Please input 1 or 2" << endl;
	}
}

void Menu::librarianMenu()
{
	int input;
	int idinput;
	int authinput;
	int bookinput;
	int prominput;
	int feeinput;
	int resinput;
	string accname;
	string pass;
	cout << "What would you like to do?" << endl;
	cout << "1. Add User" << endl << "2. Add Author" << endl << "3. Add Book" << endl << "4. Remove Account" << endl << "5. Remove Author" << endl << "6. Remove Book" << endl << "7. Promote Account" << endl <<"8. Check Late Fees" << endl << "9. Check Reservations" << endl << "10. Go Back" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		//add user
		mLibrary->addUser();
		break;
	case 2:
		//add author
		mLibrary->addAuthor();
		break;
	case 3:
		//add book
		mLibrary->addBook();
		break;
	case 4:
		//remove user
		if (mLibrary->currentUser->accessLevel == 2)
		{
			for (User* user : mLibrary->userList)
			{
				cout << user->accountName << endl << user->userID << endl << user->accessLevel << endl << endl;
			}
			cout << "Please input the ID of the account you are removing" << endl;
			cin >> idinput;
			if (mLibrary->userList[idinput]->accessLevel == 1)
			{
				cout << "Please input your account name and password" << endl;
				cin >> accname;
				cin >> pass;
				if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
				{
					delete mLibrary->userList[idinput];
				}
				else
				{
					cout << "Account details input incorrectly, account has not been removed" << endl;
				}
				cout << "Account removed successfully" << endl;
			}
			else
			{
				cout << "This account has access higher than a User, please contact an Admin to remove this account" << endl;
			}
		}
		else
		{
			for (User * user : mLibrary->userList)
			{
				cout << user->accountName << endl << user->userID << endl << endl;
			}
			cout << "Please input the ID of the account you are removing" << endl;
			cin >> idinput;
			cout << "Please input your account name and password" << endl;
			cin >> accname;
			cin >> pass;
			if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
			{
				delete mLibrary->userList[idinput];
			}
			else
			{
				cout << "Account details input incorrectly, account has not been removed" << endl;
			}
			cout << "Account removed successfully" << endl;
		}
		break;
	case 5:
		//remove author
		for (Author* author : mLibrary->authorList)
		{
			cout << author->authorName << endl << author->authorID << endl << endl;
		}
		cout << "Please input the ID of the author you would like to remove" << endl;
		cin >> authinput;
		cout << "Please input your account name and password" << endl;
		cin >> accname;
		cin >> pass;
		if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
		{
			delete mLibrary->authorList[authinput];
			cout << "Author removed successfully" << endl;
		}
		else
		{
			cout << "Account details input incorrectly, account has not been removed" << endl;
		}
		break;
	case 6:
		//remove book
		for (Book* book : mLibrary->bookList)
		{
			cout << book->title << endl << mLibrary->getAuthor(book)->authorName << endl << book->genre << endl << book->id << endl << endl;
		}
		cout << "Please input the ID of the book you would like to remove" << endl;
		cin >> bookinput;
		cout << "Please input your account name and password" << endl;
		cin >> accname;
		cin >> pass;
		if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
		{
			delete mLibrary->bookList[bookinput];
			cout << "Book removed successfully" << endl;
		}
		else
		{
			cout << "Account details input incorrectly, account has not been removed" << endl;
		}
		break;
	case 7:
		//promote user
		if (mLibrary->currentUser->accessLevel == 2)
		{
			for (User* user : mLibrary->userList)
			{
				cout << user->accountName << endl << user->userID << endl << user->accessLevel << endl << endl;
			}
			cout << "Please input the ID of the user you would like to promote" << endl;
			cin >> prominput;
			if (mLibrary->userList[prominput]->accessLevel == 1)
			{
				cout << "Please input your account name and password" << endl;
				cin >> accname;
				cin >> pass;
				if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
				{
					mLibrary->userList[prominput]->accessLevel == 2;
					cout << "Account promoted successfully" << endl;
				}
				else
				{
					cout << "Account details input incorrectly, account has not been promoted" << endl;
				}
			}
			else
			{
				cout << "This account has access higher than a User, please contact an Admin to promote this account" << endl;
			}
		}
		else
		{
			for (User* user : mLibrary->userList)
			{
				cout << user->accountName << endl << user->userID << endl << user->accessLevel << endl << endl;
			}
			cout << "Please input the ID of the user you would like to promote" << endl;
			cin >> prominput;
			if (mLibrary->userList[prominput]->accessLevel == 1)
			{
				cout << "Please input your account name and password" << endl;
				cin >> accname;
				cin >> pass;
				if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
				{
					mLibrary->userList[prominput]->accessLevel = 2;
					cout << "Account promoted successfully" << endl;
				}
				else
				{
					cout << "Account details input incorrectly, account has not been promoted" << endl;
				}
			}
		}
		break;
	case 8:
		//check late fees
		for (User* user : mLibrary->userList)
		{
			cout << user->accountName << endl << user->userID << endl << user->accessLevel << endl << endl;
		}
		cout << "Please input the ID of the user you would like to check late fees for" << endl;
		cin >> feeinput;
		cout << mLibrary->userList[feeinput]->lateCharges << endl;
		break;
	case 9:
		//check reservations
		for (Book* book : mLibrary->bookList)
		{
			cout << book->title << endl << mLibrary->authorList[book->authorID]->authorName << endl << book->genre << endl << book->id << endl << endl;
		}
		cout << "Please input the ID of the book you would like to check reservations for" << endl;
		cin >> resinput;
		for (User* user : mLibrary->bookList[resinput]->reservedList)
		{
			cout << user->accountName << endl << user->userID << endl << endl;
		}
		break;
	case 10:
		loggedInMenu();
		break;
	default:
		cout << "Please input 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10" << endl;
	}
}

void Menu::adminMenu()
{
	int input;
	int deminput;
	int feeinput;
	double fee;
	int borrinput;
	int borrow;
	string accname;
	string pass;
	cout << "What would you like to do?" << endl;
	cout << "1. Demote User" << endl << "2. Change Late Fees" << endl << "3. Change Borrow Limits" << endl << "5. Go Back" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		//demote user
		for (User* user : mLibrary->userList)
		{
			cout << user->accountName << endl << user->userID << endl << user->accessLevel << endl << endl;
		}
		cout << "Please input the ID of the user you would like to promote" << endl;
		cin >> deminput;
		if (mLibrary->userList[deminput]->accessLevel == 2)
		{
			cout << "Please input your account name and password" << endl;
			cin >> accname;
			cin >> pass;
			if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
			{
				mLibrary->userList[deminput]->accessLevel = 1;
				cout << "Account promoted successfully" << endl;
			}
			else
			{
				cout << "Account details input incorrectly, account has not been promoted" << endl;
			}
		}
		else if (mLibrary->userList[deminput]->accessLevel == 3)
		{
			cout << "Please input your account name and password" << endl;
			cin >> accname;
			cin >> pass;
			if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
			{
				mLibrary->userList[deminput]->accessLevel = 2;
				cout << "Account promoted successfully" << endl;
			}
			else
			{
				cout << "Account details input incorrectly, account has not been promoted" << endl;
			}
		}
		else
		{
			cout << "Account access level is already the lowest it can be" << endl;
		}
		break;
	case 2:
		//change late fees
		for (Book* book : mLibrary->bookList)
		{
			cout << book->title << endl << mLibrary->authorList[book->authorID]->authorName << endl << book->genre << endl << book->id << endl << endl;
		}
		cout << "Please input the ID of the book you would like to change the late fees for" << endl;
		cin >> feeinput;
		cout << "Please input your account name and password" << endl;
		cin >> accname;
		cin >> pass;
		if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
		{
			cout << "Please input the new late fee amount" << endl;
			cin >> fee;
			cout << "New late fees for " << mLibrary->bookList[feeinput]->title << " by " << mLibrary->authorList[mLibrary->bookList[feeinput]->authorID]->authorName << " is £" << fee << endl;
		}
		else
		{
			cout << "Account details input incorrectly, late fees have not been changed" << endl;
		}
		break;
	case 3:
		//change borrow limits
		for (User* user : mLibrary->userList)
		{
			cout << user->accountName << endl << user->userID << endl;
		}
		cout << "Please input the ID of the user you would like to change the borrow limit for" << endl;
		cin >> borrinput;
		cout << "Please input your account name and password" << endl;
		cin >> accname;
		cin >> pass;
		if (mLibrary->currentUser->accountName == accname && mLibrary->currentUser->password == pass)
		{
			cout << "Please input the new borrow limit" << endl;
			cin >> borrow;
			cout << "New borrow limit for " << mLibrary->userList[borrinput]->accountName << " is " << borrow << endl;
		}
		else
		{
			cout << "Account details input incorrectly, borrow limit has not been changed" << endl;
		}
		break;
	case 4:

		loggedInMenu();
		break;
	default:
		cout << "Please input 1, 2, 3, 4 or 5" << endl;
	}
}

void Menu::returnBookMenu()
{
	int input;
	for (int book : mLibrary->currentUser->bookList)
	{
		cout << mLibrary->bookList[book]->title << endl << mLibrary->authorList[mLibrary->bookList[book]->authorID]->authorName << endl << mLibrary->bookList[book]->genre << endl << mLibrary->bookList[book]->id << endl << endl;
	}	
	cout << "Please input the ID of the book you would like to return" << endl;
	cin >> input;
	for (int book : mLibrary->currentUser->bookList)
	{
		if (mLibrary->currentUser->bookList[book] == input)
		{
			mLibrary->bookList[book]->borrowed = false;
			// mLibrary->bookList[book]->bookReturned();
			mLibrary->currentUser->bookList[book] = -1;
		}
	}
	loggedInMenu();
}

void Menu::loggedInMenu()
{
	int input;
	switch (mLibrary->currentUser->accessLevel)
	{
	case 1:
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
		break;
	case 2:
		cout << "What would you like to do today?" << endl;
		cout << "1. Take Out A Book" << endl << "2. Browse Library" << endl << "3. Return Book" << endl << "4. Librarian Options" << endl << "5. Log Out" << endl;
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
			librarianMenu();
			break;
		case 5:
			mLibrary->logOut();
			if (mLibrary->userReturn == 1)
			{
				logInMenu();
			}
			break;
		default:
			cout << "Please input 1, 2, 3 or 4" << endl;
		}
		break;
	case 3:
		cout << "What would you like to do today?" << endl;
		cout << "1. Take Out A Book" << endl << "2. Browse Library" << endl << "3. Return Book" << endl << "4. Librarian Options" << endl << "5. Admin Options" << endl << "6. Log Out" << endl;
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
			librarianMenu();
			break;
		case 5:
			adminMenu();
			break;
		case 6:
			mLibrary->logOut();
			if (mLibrary->userReturn == 1)
			{
				logInMenu();
			}
			break;
		default:
			cout << "Please input 1, 2, 3 or 4" << endl;
		}
		break;
	}
	
}


