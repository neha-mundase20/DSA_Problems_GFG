//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int index,int target,int wt[], int val[], vector<vector<int>>&dp){
        
        if(index==0){
            if(target>=0){
                return (target/wt[0])*val[0];
            }
            return 0;   //Weight is greater than target
        }
        
        if(dp[index][target]!=-1){
            //Already Calculated
            return dp[index][target];
        }
        
        int notTake=0+f(index-1,target,wt,val,dp);
        int take=INT_MIN;
        if(wt[index]<=target){
            take=val[index]+f(index,target-wt[index],wt,val,dp);
        }
        
        return dp[index][target]=max(take,notTake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return f(N-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends