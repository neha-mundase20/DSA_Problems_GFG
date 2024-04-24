//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    static const int MOD = 1000000007;
    int ways(int x, int y)
    {
        //Using dynamic programming
        long long dp[x+1][y+1]={0};
        
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 && j==0){
                    //Base case i.e. paths available from (i,j)=>(0,0) to (0,0)
                    dp[i][j]=1;
                }
                else if (i == 0) {
                    // Only one way to get to any (0, j), by moving down
                    dp[i][j]=dp[i][j-1];
                } 
                else if (j == 0) {
                    // Only one way to get to any (i, 0), by moving left
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                }
            }
        }
        return (dp[x][y]);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends