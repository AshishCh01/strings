#include <iostream>
using namespace std;
string largestOddNumber(string num) {
    
    int n = num.size();
    // Traverse the string from right to left
    for (int i = n-1; i >= 0; i--) {
        
        // If the current digit is odd
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    
    // No odd digit found
    return "";
}
int main()
{
    string num = "35427";
    cout << largestOddNumber(num);

    return 0;
}