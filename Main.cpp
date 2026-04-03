#include "Menu.h"



int main()
{
	Menu* menu = new Menu();
	Library* library = new Library();
	menu->mMenu = menu;
	menu->mLibrary = library;
	library->lLibrary = library;
	library->addUserInit("John", "Admin", "password", 3);
	library->addUserInit("John", "Librarian", "password", 2);
	library->addUserInit("John", "User", "password", 1);
	library->addAuthorInit("George Orwell");
	library->addBookInit("1984", library->authorList[0]->authorID, "Political Fiction");
	library->addAuthorInit("J.R.R Tolkien");
	library->addBookInit("The Hobbit", library->authorList[1]->authorID, "High Fantasy");
	library->addBookInit("The Lord of the Rings", library->authorList[1]->authorID, "High Fantasy");
	library->addAuthorInit("J.K. Rowling");
	library->addBookInit("Harry Potter and the Philosopher's Stone", library->authorList[2]->authorID, "Fantasy");
	library->addBookInit("Harry Potter and the Chamber of Secrets", library->authorList[2]->authorID, "Fantasy");
	library->addBookInit("Harry Potter and the Prisoner of Azkaban", library->authorList[2]->authorID, "Fantasy");
	library->addBookInit("Harry Potter and the Goblet of Fire", library->authorList[2]->authorID, "Fantasy");
	library->addBookInit("Harry Potter and the Order of the Phoenix", library->authorList[2]->authorID, "Fantasy");
	library->addBookInit("Harry Potter and the Half-Blood Prince", library->authorList[2]->authorID, "Fantasy");
	library->addBookInit("Harry Potter and the Deathly Hallows", library->authorList[2]->authorID, "Fantasy");
	library->addAuthorInit("Suzanne Collins");
	library->addBookInit("The Hunger Games", library->authorList[3]->authorID, "Dystopian");
	library->addBookInit("Catching Fire", library->authorList[3]->authorID, "Dystopian");
	library->addBookInit("Mockingjay", library->authorList[3]->authorID, "Dystopian");
	library->addBookInit("The Ballad of Songbirds and Snakes", library->authorList[3]->authorID, "Dystopian");
	library->addBookInit("Sunrise on the Reaping", library->authorList[3]->authorID, "Dystopian");
	library->addAuthorInit("Travis Baldree");
	library->addBookInit("Legends & Lattes", library->authorList[4]->authorID, "Fantasy");
	library->addBookInit("Bookshops & Bonedust", library->authorList[4]->authorID, "Fantasy");
	library->addBookInit("Brigands & Breadknives", library->authorList[4]->authorID, "Fantasy");
	library->userList[2]->lateCharges = 5.50;
	library->userList[2]->takeOutBook(0);

	menu->logInMenu();
}
