//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        string number=to_string(n);
        int solution=0;
        
        for(int i=0;number[i]!='\0';i++){
            solution=solution+pow(number[i]-'0',3);//e.g.'5' - '0' = 53 - 48 = 5
        }
        
        if(solution==n){
            return "true";
        }
        else{
            return "false";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends