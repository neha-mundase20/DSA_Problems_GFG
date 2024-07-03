//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int>sumMap;
        int maxLength=0,currSum=0;
        
        for(int i=0;i<n;i++){
            currSum=currSum+arr[i];
            
            if(currSum==0){
                maxLength=i+1;  //Subarray till current element starting from 0
            }
            else if(sumMap.find(currSum)==sumMap.end()){
                sumMap[currSum]=i;  //Current sum specified along with the index
            }
            else{
                //The current sum has already occured before
                //and the subarray between its last ocuurence index
                //and current occurence index has sum 0
                //hence we need to update maxLength
                
                maxLength=max(maxLength,i-sumMap[currSum]);
            }
        }
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends