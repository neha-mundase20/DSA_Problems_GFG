//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        vector<int>solution;
        
        if(n==1){
            solution.push_back(n);
        }
        else{
            solution.push_back(n);
            while(n!=1){
                if(n%2==0){ //even number
                    int value=floor(pow(n,0.5));
                    solution.push_back(value);
                    n=value;
                }
                else{   //odd number
                    int value=floor(pow(n,1.5));
                    solution.push_back(value);
                    n=value;
                }
            }
        }
        return solution;
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
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends