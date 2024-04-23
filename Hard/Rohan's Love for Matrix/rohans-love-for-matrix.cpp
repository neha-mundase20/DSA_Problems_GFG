//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    const int MOD = 1000000007;
    int firstElement(int n) {
        int a1[1][2];   //Considered only the second row of the matrix that is required
        a1[0][0]=1;
        a1[0][1]=0;
        
        int a2[2][2];   //Entire matrix for multiplication purposes
        a2[0][0]=1;
        a2[0][1]=1;
        a2[1][0]=1;
        a2[1][1]=0;
        
        if(n==1){
            return 1;
        }
        else{
            int val1,val2;
            for(int i=0;i<(n-1);i++){
                val1=0;
                val2=0;
                val1=(int)(((long long)a1[0][0]*a2[0][0])+(long long)(a1[0][1]*a2[0][1]))%MOD;
                val2=(int)(((long long)a1[0][0]*a2[0][1])+(long long)(a1[0][1]*a2[1][1]))%MOD;
                a1[0][0]=val1;
                a1[0][1]=val2;
            }
            return (a1[0][0]);
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends