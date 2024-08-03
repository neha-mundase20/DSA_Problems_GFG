//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        int m=arr[0].size();
        vector<vector<int>>answer(n,vector<int>(m));
        
        for(int j=0;j<m;j++){
            answer[0][j]=arr[0][j];
        }
        
        for(int i=1;i<n;i++){
            answer[i][0]=max(answer[i-1][1],answer[i-1][2])+arr[i][0];
            answer[i][1]=max(answer[i-1][0],answer[i-1][2])+arr[i][1];
            answer[i][2]=max(answer[i-1][0],answer[i-1][1])+arr[i][2];
        }
        
        int maxPoints=answer[n-1][0];
        
        for(int j=1;j<m;j++){
            maxPoints=max(maxPoints,answer[n-1][j]);
        }
        return maxPoints;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends