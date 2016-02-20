# COS1512

**********************
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

char ReplaceChar(char ch)
{
    char c = ch;
    switch (ch) 
    {
        case '0':
        {
            c = '@';
            break;
        }
        case '1':
        {
            c = '!';
            break;
        }
        case '2':
        {
            c = ')';
            break;
        }
        case '3':
        {
            c = 'E';
            break;
        }
        case '4':
        {
            c = '<';
            break;
        }
        case '5':
        {
            c = '&';
            break;
        }
        case '6':
        {
            c = '$';
            break;
        }
        case '7':
        {
            c = '>';
            break;
        }
        case '8':
        {
            c = '*';
            break;
        }
        case '9':
        {
            c = '?';
            break;
        }
        case 'e':
        {
            c = 'h';
            break;
        }
        case ' ':
        {
            c = '-';
            break;
        }
    }
    return c;
}

int main()
{
    //string iName = "";
    //cout << "Enter the input file name ";
    //cin >> iName;
    
    //string oName = "";
    //cout << "Enter the output file name ";
    //cin >> oName;
    
    // declare output file
    ofstream outFile;
    outFile.open("arrest2.dat");
    
    // declare input file and open it
    ifstream inFile;
    inFile.open("arrest.dat");
    
    cout << "*** arrest.dat ***" << endl;
    while (true) {
        if( inFile.eof()) break;
        char c;
        inFile.get(c);
        cout << c;
        if (isupper(c)) continue;
        outFile << ReplaceChar(c);
    }
    cout << "*****************" << endl;
    inFile.close();
    outFile.close();
    
    cout << "*** arrest2.dat ***" << endl;
    inFile.open("arrest2.dat");
    while (true) {
        char c;
        inFile.get(c);
        cout << c;
        if( inFile.eof()) break;
    }
    cout << endl;
    cout << "*****************" << endl;
    outFile.close();
}
**********************
