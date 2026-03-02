#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User
{
public:
    string forename;
    string surname;
    string accountName;
    string password;
    int location;
    string userID;

    void takeOutBook(int bookID, string inputAccountName)
    {
        //check if user is allowed to take out books
        // check if book is available - if not, offer to request book
        // if yes, go to book request process
    }

    void returnBook()
    {
        int bookReturn;
        for (string bookName : booksOut)
        {
            cout << bookName << endl;
        }
        cout << "Which book would you like to return?" << endl;
        cin >> bookReturn;
        if (bookReturn == 1)
        {
            booksOut[0] = "N/A";
            //Book at booksOut[0]'s isAvailable is set to true
        }
        //check if book is overdue
        //if it is, charge overdue fees and flag user (flagging user alerts librarian
        //if not, take book back
        //if book is requested/reserved, alert next user on list
    }

    void reserveBook(int bookID)
    {
        //get book for bookID
        //if (taken out == true)
        {
            //add user to reservation list
            //reservationList[] += accountName
        }
    }

    string getAccountName()
    {
        return accountName;
    }

    User(string a, string b, string c, int d)
    {
        forename = a;
        surname = b;
        password = c;
        location = d;
        char first_char = forename.front();
        userID = location;
        accountName = first_char + surname + userID;
    }

    void logIn(string inputAccountName, string inputPassword, string tempID)
    {
        if (inputAccountName == accountName && inputPassword == password)
        {
            cout << "User " << tempID << " has been logged in successfully";
        }
        else
        {
            cout << "Account Name or Password input incorrectly." << endl;
        }
    }
private:
    
    string booksOut[5];
    int bookLimit = 5;
    int accountAge = 0;
    int timesFlagged = 0;
    double overdueCharge = 0;

    

    void logOut()
    {
        //log-out
    }

protected:
    int accessLevel = 0;
};

class Librarian : public User
{
public:
private:
    virtual void promoteUser(string inputUserID, string inputAccountName, string inputPassword)
    {
        if (inputUserID == userID && inputAccountName == accountName && inputPassword == password && /*User*/accessLevel == 0)
        {
            //Make User a Librarian class by creating a new Librarian class, transferring User information across, and deconstructing the original object
            //Librarian /*User.AccountName*/
            //Librarian.accountName = User.accountName;
            //Librarian.name = User.name;
            //...
            /*User*/accessLevel = 1;
        }
        else
        {
            //inform user is invalid or a higher level than allowed
            //alert admin
        }
        
    }
};

class Admin : public Librarian
{
public:
private:

    void promoteUser(string inputUserID, string inputAccountName, string inputPassword) override
    {
        if (/*User*/accessLevel == 0)
        {
            //Make User a Librarian class by creating a new Librarian class, transferring User information across, and deconstructing the original object
            //Librarian /*User.AccountName*/
            //Librarian.accountName = User.accountName;
            //Librarian.name = User.name;
            //...
            /*User*/accessLevel = 1;
        }
        else if (/*User*/accessLevel == 1)
        {
            //Make User an Admin class by creating a new Admin class, transferring User information across, and deconstructing the original object. 
            // If User wasn't a Librarian, some additional information might need to be inputted
            //Admin /*User.AccountName*/
            //Admin.accountName = User.accountName;
            //Admin.name = User.name;
            //...
            /*User*/accessLevel = 2;
        }
        else
        {
            cout << "Make sure that the User being promoted can be promoted." << endl;
        }
    }
};
class Book
{
public:
private:
    string bookName;
    int bookID;
    int bookCopies;
    int daysTakenOut;
    int takeOutLimit;
    double overdueCharge;
    bool isAvailable;
    int reservationList[];

    void overdueCharges()
    {
        if (daysTakenOut > takeOutLimit)
        {
            //.overdueCharge = (daysTakenOut - takeOutLimit) * overdueCharge;
        }
    }
};

User* users[100];
vector<User*> userList;

void createUser()
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
    users[userLocation] = new User(tempFName, tempSName, tempPWord, userLocation);
    cout << "Account Created Successfully. Please Proceed to Log In." << endl;
    users[userLocation]->logIn(users[userLocation]->accountName, tempPWord, users[userLocation]->userID);
    userLocation += 1;
    
}

void init()
{
    int input;
    string accName;
    string pWord;
    cout << "Welcome to the Library System" << endl << "Please Input what you would like to do today" << endl << endl;
    cout << "1. Log In" << endl << "2. Create Account" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "Please Input your Account Name" << endl;
        cin >> accName;
        cout << "Please input your Password" << endl;
        cin >> pWord;
        for (User* user : userList) 
        {
            if (user->accountName == accName)
            {
                user->logIn(accName, pWord, user->userID);
            }
            else
            {
                cout << "User not found, please try creating an account first" << endl;
            }
        }     
    }
    else if (input == 2)
    {
        createUser();
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
    }
}

int main()
{
    init();
    
}
