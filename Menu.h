#pragma once
#include "Library.h"
#include "Librarian.h"
#include "Admin.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Menu
{
public:
	Menu* mMenu;
	Library* mLibrary;
	void logInMenu();

	void takeOutBookMenu();

	void browseMenu();

	void returnBookMenu();

	void loggedInMenu();

	Menu()
	{
		mMenu = nullptr;
		mLibrary = nullptr;
	}
};
