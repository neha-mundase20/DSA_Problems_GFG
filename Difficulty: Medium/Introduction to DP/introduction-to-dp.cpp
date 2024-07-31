//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    long long val=pow(10,9)+7;
    
    long long int tdown(int n,vector<long long int>&memo){
        if(memo[n]!=-1){
            return memo[n];
        }
        if(n<=1){
            return n;
        }
        memo[n]=(tdown(n-1,memo)+tdown(n-2,memo))%val;
        return memo[n];
    }
    
    long long int topDown(int n) {
        //Recursion or memoization
        
        vector<long long int>memo(n+1,-1);
        long long int answer=tdown(n,memo);
        return answer;
        
    }
    long long int bottomUp(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        long long prev1=1,prev2=0,curri=0;
        for(int i=2;i<=n;i++){
            curri=(prev1+prev2)%val;
            prev2=prev1;
            prev1=curri;
        }
        
        return prev1;
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
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends