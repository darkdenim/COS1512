#include <iostream>
#include <assert.h>

using namespace std;

int CalculatePoints(int mark)
{
    if (mark >= 80) return 6;
    if (mark >= 70) return 5;
    if (mark >= 60) return 4;
    if (mark >= 50) return 3;
    return 0;
}

int main()
{
    int aps = 0;
    string subjects[6] = {"English", "Mathematics", "Physical Science", "Subject 4", "Subject 5", "Subject 6"};
    int scores[6];
    int arraySize = sizeof(scores)/sizeof(*scores);    
    for (int i = 0; i < 3; i++)
    {
        cout << "Please enter the mark for " << subjects[i] << endl;
        cin >> scores[i];
        assert(scores[i] >= 0 && scores[i] <=100);
        scores[i] = CalculatePoints(scores[i]);
        assert(scores[i] >= 4 && "Invalid mark for compulsory subject!");
        aps += scores[i];
    }    
    cout << "All compulsory subjects passed!" << endl;
    
    for (int i = 3; i < arraySize; i++)
    {
        cout << "i: " << i << endl;
        cout << "Please enter the mark for " << subjects[i] << endl;
        cin >> scores[i];
        assert(scores[i] >= 0 && scores[i] <=100 && "Mark should be between 0 and 100!");
        scores[i] = CalculatePoints(scores[i]);
        assert(scores[i] > 0);
        aps += scores[i];
    }
    
    cout << "APS Score: " << aps << endl;
    if (aps >= 28) cout << "Student admitted!" << endl;
    else cout << "Student NOT admitted!" << endl;
    
    return 0;
}