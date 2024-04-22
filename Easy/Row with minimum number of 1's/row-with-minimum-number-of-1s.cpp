//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int prev_count=INT_MAX,curr_count=0;
        int prev_index=0,curr_index=0;
        for(int i=0;i<a.size();i++){
            curr_count=0;
            curr_index=i;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==1){
                    curr_count++;
                }
            }
            if(curr_count<prev_count){
                prev_count=curr_count;
                prev_index=curr_index+1;
            }
            else if(curr_count==prev_count){
                prev_index=min(prev_index,curr_index+1);
            }
        }
        return prev_index;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends