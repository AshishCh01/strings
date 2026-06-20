#include <iostream>
#include <vector>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    vector<int> ans;

    int n = s.size();
    int m = p.size();

    // If p is longer than s, no anagrams are possible
    if (m > n)
        return ans;

    // Frequency arrays for p and current window in s
    vector<int> freqP(26, 0);
    vector<int> freqS(26, 0);

    // Fill frequencies for p and first window of s
    for (int i = 0; i < m; i++) {
        freqP[p[i] - 'a']++;
        freqS[s[i] - 'a']++;
    }

    // Check first window
    if (freqP == freqS)
        ans.push_back(0);

    // Slide the window
    for (int i = m; i < n; i++) {

        // Add new character entering the window
        freqS[s[i] - 'a']++;

        // Remove character leaving the window
        freqS[s[i - m] - 'a']--;

        // If frequencies match, current window is an anagram
        if (freqP == freqS) {
            ans.push_back(i - m + 1);
        }
    }

    return ans;
}
int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}