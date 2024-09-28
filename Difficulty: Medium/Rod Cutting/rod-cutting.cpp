//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int f(int index,int target,int price[],vector<vector<int>>&dp){
        
        if(target==0){
            return 0;
        }
        
        if(index==0){
            if(target%(index+1)==0){
                return (target/(index+1))*price[index];
            }
        }
        
        //Already calculated so no need to recalculate
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        int notTake=f(index-1,target,price,dp);
        int take=0;
        if((index+1)<=target){
            //length of piece is less than or equal to target
            take=price[index]+f(index,target-(index+1),price,dp);
            
        }
        return dp[index][target]=max(take,notTake);
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends