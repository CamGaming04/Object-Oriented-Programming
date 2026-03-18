#include "Menu.h"



int main()
{
	Menu* menu = new Menu();
	Library* library = new Library();
	menu->mMenu = menu;
	menu->mLibrary = library;
	library->lLibrary = library;
	library->addBookInit("1984", "George Orwell", "Political Fiction");
	library->addBookInit("The Hobbit", "J.R.R Tolkien", "High Fantasy");
	library->addBookInit("The Lord of the Rings", "J.R.R Tolkien", "High Fantasy");
	library->addBookInit("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy");
	library->addBookInit("Harry Potter and the Chamber of Secrets", "J.K. Rowling", "Fantasy");
	library->addBookInit("Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", "Fantasy");
	library->addBookInit("Harry Potter and the Goblet of Fire", "J.K. Rowling", "Fantasy");
	library->addBookInit("Harry Potter and the Order of the Phoenix", "J.K. Rowling", "Fantasy");
	library->addBookInit("Harry Potter and the Half-Blood Prince", "J.K. Rowling", "Fantasy");
	library->addBookInit("Harry Potter and the Deathly Hallows", "J.K. Rowling", "Fantasy");
	library->addBookInit("The Hunger Games", "Suzanne Collins", "Dystopian");
	library->addBookInit("Catching Fire", "Suzanne Collins", "Dystopian");
	library->addBookInit("Mockingjay", "Suzanne Collins", "Dystopian");
	library->addBookInit("The Ballad of Songbirds and Snakes", "Suzanne Collins", "Dystopian");
	library->addBookInit("Sunrise on the Reaping", "Suzanne Collins", "Dystopian");
	library->addBookInit("Legends & Lattes", "Travis Baldree", "Fantasy");
	library->addBookInit("Bookshops & Bonedust", "Travis Baldree", "Fantasy");
	library->addBookInit("Brigands & Breadknives", "Travis Baldree", "Fantasy");

	menu->logInMenu();
}
