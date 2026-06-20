#include <iostream>
using namespace std;
int expand(string& s, int left, int right) {
   int count = 0;
   while (left >= 0 && right < s.size() && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
   return count;
}
int countSubstrings(string s) {
    int n = s.size();
    int count = 0;
    for (int i=0; i<n; i++) {
        count += expand(s, i, i);   // Odd length palindromes
        count += expand(s, i, i+1); // even length palindromes
    }
    return count;
}
int main()
{
    string s = "aaa";
    cout << countSubstrings(s);
    return 0;
}
