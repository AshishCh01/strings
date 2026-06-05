#include <iostream>
#include <string>
using namespace std;
bool isFreqSame(int freq1[], int freq2[]) {
    for (int i=0; i<26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}
bool checkPermutation(string s1, string s2) {
    int freq[26] = {0};
    for (int i=0; i<s1.length(); i++) {
        // gives the index of any character using ASCII value. EX ASCII value of b = 98 and ASCII value of a = 97 
        int idx = s1[i] - 'a';      // i = 2 pointing B so, 98-97 = 1. Hence b is stored in index 1
        freq[idx]++;
    }  
    int windSize = s1.length();
    
    for (int i=0; i<s2.length(); i++) {
        int windIdx = 0, idx=i;
        int windFreq[26] = {0};
        
        while (windIdx < windSize && idx < s2.length()) {
            windFreq[s2[idx]-'a']++;
            windIdx++;
            idx++;
        }
        if (isFreqSame(freq, windFreq)) {   // found
            return true;
        }
    }
    return false;
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkPermutation(s1, s2);
    return 0;
}