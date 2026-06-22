#include <iostream>
#include <set>
using namespace std;
int longestKSubstr(string &s, int k) {
    int n = s.size();
    int maxLen = -1;
    for (int i=0; i<n; i++) {
        set<char> st;
        for (int j=i; j<n; j++) {
            st.insert(s[j]);
            if(st.size() > k) break;
            if(st.size() == k) {
                maxLen = max(maxLen, j-i+1);
            }
        }
    }
    return maxLen;
}
int main()
{
    string s = "aabacbebebe";
    int k = 3;
    cout << longestKSubstr(s, k);

    return 0;
}