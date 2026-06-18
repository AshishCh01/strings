#include <iostream>
using namespace std;
bool isPalindrome(string &str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }
    return true;
}
string longestPalindrome(string s) {
    string ans = "";
    for (int i=0; i< s.size(); i++) {
        for (int j=i; j<s.size(); j++) {
            // Generate substring from i to j
            string temp = s.substr(i, j - i + 1);
            // Check if it is a palindrome
            if (isPalindrome(temp) && temp.length() > ans.length()) {
                ans = temp;
            }
        }
    }
    return ans;
}
int main()
{
    string s = "babad";
    cout << longestPalindrome(s);
    return 0;
}

// or
// bool isPalindrome(string &s, int left, int right) {
//     while (left < right) {
//         if(s[left] != s[right]) return false;
//         left++;
//         right--;
//     }
//     return true;
// }

// string longestPalindrome(string s) {
//     string ans = "";
//     for (int i=0; i<s.length(); i++) {
//         for (int j=i; j < s.length(); j++) {
//             if (isPalindrome(s, i, j) == true) {
//                 if(j-i+1 > ans.length()) {
//                     ans = s.substr(i, j+1);
//                 }
//             }
//         }
//     }
//     return ans;
// }