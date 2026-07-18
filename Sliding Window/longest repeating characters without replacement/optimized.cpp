#include <iostream>
#include <unordered_map>
using namespace std;
int characterReplacement(string s, int k) {
    unordered_map<char, int> freq;

    int left = 0;
    int maxFreq = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        // Include current character in the window
        freq[s[right]]++;

        // Update the maximum frequency in the current window
        maxFreq = max(maxFreq, freq[s[right]]);

        // Shrink the window if more than k replacements are required
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left]]--;
            left++;
        }

        // Update the answer
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
int main()
{
    string s = "AABABBA";
    int k = 2;
    cout << characterReplacement(s, k);
    return 0;
}