#include <iostream>
#include <unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLen = 0;
    for (int i=0; i<n; i++) {
        unordered_set<char> st;
        for (int j=i; j<n; j++){
            if(st.count(s[j])) break;
            st.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}
int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}