//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long sum=0;           //initialize the sum to 0
        long long maxi=arr[0];     // initialize the maximum to 1st value
        
        for(int i=0;i<n;i++){
            sum=sum+arr[i];        // add current element too sum
            maxi=max(maxi,sum);    //update maximum
            
            if(sum<0){
                sum=0;
            }
            //If the sum becomes negative at any point within the loop, 
            //it means that continuing the current subarray would decrease the sum. 
            //In such cases, we reset sum to 0, effectively considering a new starting point for the subarray.
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends