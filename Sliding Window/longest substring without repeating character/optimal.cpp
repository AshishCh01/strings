#include <bits/stdc++.h>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1);   // Stores last index of each character

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        // If character already exists in current window
        if (hash[s[right]] >= left) {
            left = hash[s[right]] + 1;
        }

        // Update last occurrence of current character
        hash[s[right]] = right;

        // Update answer
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);

    return 0;
}