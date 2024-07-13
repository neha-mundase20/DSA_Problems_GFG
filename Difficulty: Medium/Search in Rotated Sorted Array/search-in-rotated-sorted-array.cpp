//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int breakPoint=0,n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i%n]>arr[(i+1)%n]){
                breakPoint=i+1;
            }
        }
        
        int low=0,high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int realMid=(mid+breakPoint)%n;
            
            if(arr[realMid]==key){
                return realMid;
            }
            else if(arr[realMid]>key){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends