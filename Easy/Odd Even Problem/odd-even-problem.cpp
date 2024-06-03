//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        map<char, int> mp;
        
        // Count the frequency of each character in the string
        for (char c : s) {
            mp[c]++;
        }
        
        int x=0, y=0;
        
        // Iterate through the map to determine the counts for x and y
        for (auto& entry : mp) {
            char c=entry.first;
            int frequency=entry.second;
            int pos=(int(c)-int('a')+1);
            
            if (pos%2==0 && frequency% 2==0) {
                // Even position and even frequency
                x++;
            } else if (pos%2!=0 && frequency%2!=0) {
                // Odd position and odd frequency
                y++;
            }
        }
        
        // Determine if the sum of x and y is even or odd
        if ((x+y)%2==0) {
            return "EVEN";
        } else {
            return "ODD";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends