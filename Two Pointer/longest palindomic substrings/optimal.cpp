#include <bits/stdc++.h>
using namespace std;
int expand(string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right-left-1;
}
string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i=0; i<s.length(); i++) {
        int odd = expand(s, i, i);
        int even = expand(s, i, i+1);
        int len = max(odd, even);
        
        if(len > (end-start+1)) {
            start = i - (len-1) / 2;
            end = i + len/2;
        }
    }
    return s.substr(start, end-start+1);
}
int main()
{
    string s = "babad";
    cout << longestPalindrome(s);

    return 0;
}

//OR
// int start = 0;
// int maxLen = 0;

// void expandFromCenter(string &s, int left, int right) {

//     while (left >= 0 && right < s.length() &&
//           s[left] == s[right]) {

//         int currLen = right - left + 1;

//         if (currLen > maxLen) {
//             maxLen = currLen;
//             start = left;
//         }

//         left--;
//         right++;
//     }
// }

// string longestPalindrome(string s) {

//     for (int i = 0; i < s.length(); i++) {

//         // Odd length palindrome
//         expandFromCenter(s, i, i);

//         // Even length palindrome
//         expandFromCenter(s, i, i + 1);
//     }

//     return s.substr(start, maxLen);
// }