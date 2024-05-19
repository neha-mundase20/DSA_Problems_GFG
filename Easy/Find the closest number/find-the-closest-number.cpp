//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int l=0,h=n-1;
        int closestNumber=INT_MAX;
        int difference=INT_MAX;
        
        while(l<=h){
            int mid=l+((h-l)/2);
            
            if(abs(arr[mid]-k)==difference){
                closestNumber=max(closestNumber,arr[mid]);
            }
            else if(abs(arr[mid]-k)<difference){
                difference=abs(arr[mid]-k);
                closestNumber=arr[mid];
            }
            
            if(k>arr[mid]){ //search in right part
                l=mid+1;
            }
            else{   //search in left part
                h=mid-1;
            }
            
        }
        return closestNumber;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends