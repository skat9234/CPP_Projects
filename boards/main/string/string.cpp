#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    string txt = "Challenge each student.";
    cout << " Input a sentence:: ";
    getline(cin, txt);
    cout << " The string: " << txt << endl;
    cout << " The length of the string:: " << txt.length() << endl;
    cout << " The char at index 1 of the string::"<< txt.at(1) << endl;
    cout << " The char at index 1 of the string [using array] ::"<< txt[1] << endl;
    cout << " Is the string empty:: " << txt.empty() << endl;
    cout <<" Retrieve the sub-string from 3rd position for 4 characters:: "<< txt.substr(3,4) << endl;
    cout << " The sub-string replace by 'went' ::"<< txt.replace(3, 4, " went ") << endl;
    cout <<" Append a string ' end' at last of the string:: "<< txt.append(" end") << endl;
    cout <<" Append a string ' end' at last of the string using operator:: "<< txt + " end" << endl;
    cout <<" The string ' insert ' inserting at 3rd position of the string:: "<< txt.insert(3, "insert ") << endl;
}