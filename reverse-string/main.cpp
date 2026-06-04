#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "Hello world";
    int n = str.length();
    int st=0; int end =n-1;
    while (st < end) {
        swap(str[st], str[end]);
        st++;
        end--;
    }
    for (int i=0; i<n; i++) {
        cout << str[i];
    } 
    
    // or   again reversed
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}