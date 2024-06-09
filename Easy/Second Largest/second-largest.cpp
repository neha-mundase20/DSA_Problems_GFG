//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    set<int>st; //set stores unique elements in sorted order;
	    
	    for(int i=0;i<n;i++){
	        st.insert(arr[i]);
	    }
	    
	    if(st.size()<2){
	        return -1;
	    }
	    
	    auto it=st.end();
	    it--;   //Move to the largest element
	    it--;   //Move to the second largest element
	    
	    return *it;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends