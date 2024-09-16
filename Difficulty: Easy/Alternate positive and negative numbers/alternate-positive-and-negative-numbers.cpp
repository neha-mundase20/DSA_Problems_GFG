//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int>negative;
        vector<int>positive;
        
        for(auto it:arr){
            if(it>=0){
                positive.push_back(it);
            }
            else{
                negative.push_back(it);
            }
        }
        
        int i=0,j=0,k=0;
        
        while(i<positive.size() && j<negative.size()){
            arr[k++]=positive[i++];
            arr[k++]=negative[j++];
        }
        
        while(i<positive.size()){
            arr[k++]=positive[i++];
        }
        
        while(j<negative.size()){
            arr[k++]=negative[j++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends