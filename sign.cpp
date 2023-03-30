#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

// Menu
char menu();

// sign in Functions
void signin(string username, string password);

// sign up Functions
void signup(string username, string password);
bool isValidUsername(string username);
bool checkuser(string username, string password);

// users
void viewusers();

// File
void storeInFile(string username, string password);
void readdatafromfile();

const int size = 10;
string usernames[size];
string passwords[size];
int usercount = 0;
char option;

main()
{
    system("cls");
    char choice;
    string username, password;
    readdatafromfile();
    while (choice != '0')
    {
        choice = menu();
        if (choice == '1')
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            bool result = isValidUsername(username);
            if (result == true)
            {
                signup(username, password);
                storeInFile(username, password);
                cout << "Signed up succesfully" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
            }
            else
            {
                cout << "User already exist" << endl;
                cout << "Press any key to continue..." << endl;
                getch();
            }
        }
        if (choice == '2')
        {
            system("cls");
            
            signin(username, password);
            cout << "Press any key to continue..." << endl;
            getch();
        }
        if (choice == '3')
        {
            system("cls");
            
            viewusers();
            cout << "Press any key to continue..." << endl;
            getch();
        }
    }
    
}

char menu()
{
    cout << "    Main Menu  " << endl;
    cout << " 1.  Sign Up" << endl;
    cout << " 2.  Sign In" << endl;
    cout << " 3.  View Users" << endl;
    cout << " 0.  Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Enter option: ";
    cin >> option;
    return option;
}

void signup(string username, string password)
{
    // system("cls");

    usernames[usercount] = username;
    passwords[usercount] = password;
    usercount++;
}

void storeInFile(string username, string password)
{
    fstream file;
    file.open("Users.txt", ios::app);
    file << username << endl;
    file << password << endl;
    file.close();
}

void viewusers()
{
    cout << "Usernames"
         << "\t\t"
         << "passwords"
         << "\t\t" << endl
         << endl;
    for (int i = 0; i < usercount; i++)
    {
        cout << usernames[i] << "\t\t" << passwords[i] << endl;
    }
}

void signin(string username, string password)
{
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool check = checkuser(username, password);
    if (check == true)
    {
        cout << "Signed In succesfully" << endl;
    }
    else
    {
        cout << "Invalid entity" << endl;
    }
}

bool isValidUsername(string username)
{
    bool flag = true;
    for (int i = 0; i < usercount; i++)
    {
        if (username == usernames[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool checkuser(string username, string password)
{
    for (int i = 0; i < usercount; i++)
    {
        if (username == usernames[i] && password == passwords[i])
        {
            return true;
            break;
        }
    }
    return false;
}

void readdatafromfile()
{
    string username, password;
    fstream file;
    file.open("users.txt", ios::in);
    while (getline(file, username) && getline(file, password))
    {

        usernames[usercount] = username;
        passwords[usercount] = password;
        usercount++;
    }
    file.close();
}