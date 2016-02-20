#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int HighestMark(int a1, int a2, int a3)
{
    int highest = 0;
    if (a1 > a2 && a1 > a3) highest = a1;
    if (a2 > highest && a2 > a3) highest = a2;
    if (a3 > highest) highest = a3;
    return highest;
}

int main()
{
    ofstream outFile;
    outFile.open("yearmark.dat");
    
    // open marks.dat in read mode
    ifstream file;
    file.open("marks.dat");
    
    int items[4];
    size_t pos = 0;
    string delimiter = " ";
    string token;
    string s;
    cout << "***marks.dat***" << endl;
    while (getline(file, s))
    {
        int i = 0;
        cout << s << endl;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
            items[i] = atoi(token.c_str());
            i++;
        }
        items[i] = atoi(s.c_str());
        for (int i = 0; i < sizeof(items)/sizeof(*items); i++)
        {
            cout << items[i] << endl;
        }
        
        int sn = items[0];
        int a1 = items[1];
        int a2 = items[2];
        int a3 = items[3];
        
        double avg = (a1 + a2 + a3) / 3;
        double ym = avg * 0.4 + (HighestMark(a1, a2, a3) * 0.6);
        outFile << sn << " ";
        //outFile << sn << " " << std::setprecision(5) << avg << " " << ym << endl;
        outFile << avg << " " << ym << endl;
    }
    outFile.close();
    file.close();
    
    file.open("yearmark.dat");
    cout << "***yearmark.dat***" << endl;
    while (getline(file, s))
    {
        cout << s << endl;
    }
    cout << "***END OF PROGRAM***" << endl;
}
