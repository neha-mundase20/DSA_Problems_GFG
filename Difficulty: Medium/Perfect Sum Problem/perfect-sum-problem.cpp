//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int MOD=pow(10,9)+7;
	
	int f(int index,int target,int arr[],vector<vector<int>>&dp){
	    if(index==0){
            if(target==0 && arr[0]==0) return 2; // both include and exclude
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
	    
	    if(dp[index][target]!=-1){
	        return dp[index][target];
	    }
	    
	    int notTake=f(index-1,target,arr,dp)%MOD;
	    int take=0;
	    if(arr[index]<=target){
	        take=f(index-1,target-arr[index],arr,dp)%MOD;
	    }
	    
	    return dp[index][target]=(take+notTake)%MOD;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return f(n-1,sum,arr,dp);
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends