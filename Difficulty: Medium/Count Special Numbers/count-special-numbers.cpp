//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        /*sort(arr.begin(),arr.end());
        int specialNumberCount=0;
        
        //Any number is divisible only by the number smaller than itself or
        either the number itself
        
        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    specialNumberCount++;
                    break;
                }
            }
        }
        return specialNumberCount;*/
        
        sort(arr.begin(),arr.end());
        int specialNumberCount=0;
        unordered_map<int,int>hashmap;
        
        for(int i=0;i<N;i++){
            hashmap[arr[i]]++;
        }
        
        for(int i=0;i<N;i++){
            if(hashmap[arr[i]]>1){
                specialNumberCount++;
            }
            else{
                for(int j=0;j<i;j++){
                    if(arr[i]%arr[j]==0){
                        specialNumberCount++;
                        break;
                    }
                }
            }
        }
        return specialNumberCount;
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
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends