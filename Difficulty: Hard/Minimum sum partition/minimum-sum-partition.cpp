//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    /*Recursion and Memoization Approach
    bool f(int index,int target,int arr[],vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        
        if(index==0){
            return (arr[index]==target);
        }
        
        if(dp[index][target]!=-1){
            //Already Calculated
            return dp[index][target];
        }
        
        bool notTake=f(index-1,target);
        bool take=false;
        if(arr[index]<=target){
            take=f(index-1,target-arr[index]);
        }
        
        return dp[index][target]=take||notTake;
    }*/
  
	int minDifference(int arr[], int n){
	    int totalSum=0;
	    
	    for(int i=0;i<n;i++){
	         totalSum=totalSum+arr[i];
	    }
	    
	    /*So now we came to know that the min target sum that we can obtain
	    from the array is 0 by selecting no elements and the max target sum
	    that we can obtain is totalSum of the array by selecting all the
	    elements*/
	    
	    vector<vector<bool>>dp(n,vector<bool>(totalSum+1,false));
	    
	    //Tabulation Approach
	    
	    for(int i=0;i<n;i++){
	        dp[i][0]=true;
	    }
	    
	    dp[0][arr[0]]=true;
	    
	    for(int i=1;i<n;i++){
	        for(int j=1;j<=totalSum;j++){
	            bool notTake=dp[i-1][j];
	            bool take=false;
	            
	            if(arr[i]<=j){
	                take=dp[i-1][j-arr[i]];
	            }
	            
	            dp[i][j]=take||notTake;
	        }
	    }
	    
	    int minDifference=INT_MAX;
	    
	    for(int j=0;j<=totalSum/2;j++){
	        if(dp[n-1][j]==true){
	            int s1=j;
	            int s2=totalSum-j;
	            minDifference=min(minDifference,abs(s1-s2));
	        }
	    }
	    
	   return minDifference; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends