//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int low=0,high=n-1,mid=0;
	    int firstOccurence=0,lastOccurence=0;
	    
	    //Calculate First Occurence
	    
	    while(low<=high){
	        mid=low+((high-low)/2);
	        
	        if(arr[mid]>=x){   //Move left to find firstOccurence
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    
	    if(low<=n && arr[low]==x){ //Target element found
	        firstOccurence=low;
	    }
	    else{
	        return 0;
	    }
	    
	    //Calculate lastOccurence
	    
	    //Now low is set to firstOccurence so set high to n-1
	    
	    high=n-1;
	    
	    while(low<=high){
	        mid=low+((high-low)/2);
	        
	        if(arr[mid]>x){    //Move to left part to search for target
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    
	    lastOccurence=high;
	    
	    return lastOccurence-firstOccurence+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends