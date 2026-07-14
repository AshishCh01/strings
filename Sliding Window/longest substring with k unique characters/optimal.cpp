#include <iostream>
#include <set>
#include <vector>
using namespace std;
int longestKSubstr(string s, int k) {
    vector<int> freq(26, 0);
    int left = 0, distinct = 0, ans = -1;

    for (int right = 0; right < s.size(); right++) {

        if (freq[s[right] - 'a'] == 0)
            distinct++;

        freq[s[right] - 'a']++;
        
        // Shrink window if distinct characters exceed k
        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0)
                distinct--;
            left++;
        }
         // Update answer when exactly k distinct characters exist
        if (distinct == k)
            ans = max(ans, right - left + 1);
    }
    return ans;
}
int main()
{
    string s = "aabacbebebe";
    int k = 3;
    cout << longestKSubstr(s, k);
    return 0;
}

// or
// #include <bits/stdc++.h>
// using namespace std;

// int longestKSubstr(string s, int k) {
//     int n = s.size();
//     int left = 0, ans = -1;

//     unordered_map<char, int> freq;

//     for (int right = 0; right < n; right++) {
//         freq[s[right]]++;

//         // Shrink window if distinct characters exceed k
//         while (freq.size() > k) {
//             freq[s[left]]--;

//             if (freq[s[left]] == 0)
//                 freq.erase(s[left]);

//             left++;
//         }

//         // Update answer when exactly k distinct characters exist
//         if (freq.size() == k) {
//             ans = max(ans, right - left + 1);
//         }
//     }

//     return ans;
// }