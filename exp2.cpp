#include <iostream>
#include <fstream>
using namespace std;
main()
{
    string word;
    fstream file;
    int count = 0;
    file.open("example.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        //cout << "The word is: " << word << endl;
        count++;
    }
     file>>word;
    file.close();
    cout << count;
}