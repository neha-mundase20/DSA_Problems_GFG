//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) 
    { 
        //Using Binary Search
       int low=0;
       int high=N-1;
       bool flag=false;
       
       
       while(low<=high){
          int mid=low+((high-low)/2);
          
          if(arr[mid]==K){
              flag=true;
              break;
          }
          else if(K<arr[mid]){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
       }
       
       if(flag==true){
           return 1;
       }
       else{
           return -1;
       }
       
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends