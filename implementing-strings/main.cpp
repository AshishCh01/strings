
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    // strings are dynamic in nature and stored in contigous manner
    string str = "ashish choudhary";
    // cout << str << endl;
    str = "hello";
    cout << str << endl;    // vlue of str is changed from asshish choudhary to hello
    cout << str.length() << endl;
    
    char arr[] = "AK";
    // arr =    - error we can't change the value of character array
    
    string str1 = "IPS ";
    string str2 = "Academy";
    string str3 = str1 + str2; // concatenation
    cout << str3 << endl;   
    
    string str4 = "IPS";
    string str5 = "IPS";
    cout << (str4 == str5) << endl; // returns 1 - true
    
    // Input output in strings
    string str6;
    cout << "enter string: ";
    // cin >> str6 - wrong method - so use get inline
    getline(cin, str6, '$');    // delimitator($) is optional if we use we have to type this to stop taking input in terminal
    cout << "output: " << str6 << endl;
    
    string str7 = "Ashish choudhary";
    for (int i=0; i<str7.length(); i++) {
        cout << str7[i] << " ";
    }
    return 0;
}