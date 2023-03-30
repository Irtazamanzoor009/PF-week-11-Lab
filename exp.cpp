#include <iostream>
#include <fstream>
using namespace std;
main()
{
    int number = 100;
    float num2 = 12.5;
    string name = "ali";
    char c = '#';
    fstream file;
    file.open("example.txt", ios::out);
    file << "Hello world" << endl;
    file << number << endl;
    file << num2 << endl;
    file << name << endl;
    file << c <<endl;
    file << 123.5 <<endl;
    file.close();
}