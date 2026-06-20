#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    
    // Create a sorted copy of p for comparison
    string sortedP = p;
    sort(sortedP.begin(), sortedP.end());

    // Traverse all possible substrings of length m in s
    for (int i = 0; i <= n - m; i++) {
        
        // Extract substring of length m starting from index i
        string temp = s.substr(i, m);
        // Sort the current substring
        sort(temp.begin(), temp.end());
        
        // If sorted substring matches sorted p,
        // then current substring is an anagram of p
        if (temp == sortedP) {
            ans.push_back(i);
        }
    }
    // Return all starting indices of anagrams
    return ans;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}