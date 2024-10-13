//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void f(vector<int>&temp, vector<int>&result, vector<int>&arr, int currentSubsetSum,int index){
        if(index>=arr.size()){
            result.push_back(currentSubsetSum);
            return;
        }
        
        temp.push_back(arr[index]);
        f(temp,result,arr,currentSubsetSum+arr[index],index+1);
        temp.pop_back();
        f(temp,result,arr,currentSubsetSum,index+1);
    }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>temp;
        vector<int>result;
        int currentSubsetSum=0,index=0;
        f(temp,result,arr,currentSubsetSum,index);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends