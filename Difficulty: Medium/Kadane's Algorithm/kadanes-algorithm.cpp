//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // int n=arr.size();
        // int maxSum=INT_MIN;
        
        // for(int i=0;i<n;i++){
        //     int subarraySum=arr[i];
        //     for(int j=i+1;j<n;j++){
        //         subarraySum=subarraySum+arr[j];
        //         maxSum=max(subarraySum,maxSum);
        //     }
        // }
        // return maxSum;
        
        //Kadane's Algorithm
        int maxSum=INT_MIN;
        int currentSum=0;
        
        for(auto it:arr){
            currentSum=currentSum+it;
            if(currentSum>maxSum){   
                maxSum=currentSum;
            }
            if(currentSum<0){   //If current sum is -ve reset it to 0
                currentSum=0;
            }
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends