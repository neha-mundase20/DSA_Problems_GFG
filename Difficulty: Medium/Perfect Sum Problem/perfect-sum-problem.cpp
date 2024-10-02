//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int MOD=pow(10,9)+7;
	
	int f(int index,int arr[],int currentSum,int sum,int n,
	vector<vector<int>>&dp){
	    
        if(index>=n){
            if(currentSum==sum){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[index][currentSum]!=-1){
            return dp[index][currentSum];
        }
        
        int notTake=f(index+1,arr,currentSum,sum,n,dp); //not Take
        
        int take=0;
        if(currentSum+arr[index]<=sum){
            //take
            take=f(index+1,arr,currentSum+arr[index],sum,n,dp);
        }
        
        return dp[index][currentSum]=(take+notTake)%MOD;
    }
	
	int perfectSum(int arr[], int n, int sum)
	{
        int currentSum=0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(0,arr,currentSum,sum,n,dp)%MOD;
        
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