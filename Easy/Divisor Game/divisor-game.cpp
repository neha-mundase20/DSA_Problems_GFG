//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    /*if n=1, no available x so Alice loses
    if n=2,Alice chooses x=1,n=>n-x=2-1=1 Bob loses
    if n=3,Alice choose x=1,n=>n-x=3-1=2,Bob chooses x=1, n=>n-x=2-1=1 i.e. now Alice loses*/
    
    bool divisorGame(int n) {
        if(n%2==0){ //Alice wins for even numbers
            return true;
        }
        else{
            return false;
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

        Solution obj;
        bool ans = obj.divisorGame(n);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends