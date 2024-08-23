//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int MOD=pow(10,9)+7;
  
    int f(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(index==0){
            if(target==0 && arr[0]==0) return 2; // both include and exclude
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        
        if(dp[index][target]!=-1){
            //Already Calculated
            return dp[index][target];
        }
        
        int notTake=f(index-1,target,arr,dp);
        int take=0;
        if(arr[index]<=target){
            take=f(index-1,target-arr[index],arr,dp);
        }
        
        return dp[index][target]=(take+notTake)%MOD;    //Count of susbsets
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        //S1-S2=d && S1+S2=totalSum => S1=(totalSum+d)/2;
        
        int totalSum=0;
        
        for(auto it:arr){
            totalSum=totalSum+it;
        }
        
        //Check if it is possible to have such partitions
        if ((totalSum+d)%2!=0) return 0;    //Odd sum
        
        int target=(totalSum+d)/2;
        
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        
        return f(n-1,target,arr,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends