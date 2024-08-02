//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        /*vector<int>dp(arr.size(),0);
        dp[0]=0;
        dp[1]=abs(arr[0]-arr[1]);
        dp[2]=min(dp[0]+abs(arr[0]-arr[2]),dp[1]+abs(arr[1]-arr[2]));
        
        for(int i=3;i<=arr.size();i++){
            //Checking for all possible costs to reach i and then taking
            //min cost out of all the costs
            int cost=INT_MAX;
            for(int j=i-k;j<i;j++){
                cost=min(cost,dp[j]+abs(arr[j]-arr[i]));
            }
            dp[i]=cost;
        }
        return dp[arr.size()-1];*/
        
        vector<int>dp(arr.size(),0);
        dp[0]=0;
        //We are standing on first stone itself
        
        for(int i=1;i<arr.size();i++){
            //Checking for all possible costs to reach i and then taking
            //min cost out of all the costs
            int cost=INT_MAX;
            for(int j=max(0,i-k);j<i;j++){
                cost=min(cost,dp[j]+abs(arr[j]-arr[i]));
            }
            dp[i]=cost;
        }
        return dp[arr.size()-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends