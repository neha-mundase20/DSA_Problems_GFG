//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int l=0,h=a.size()-1;
        
        while(l<h){
            int mid=l+((h-l)/2);
            
            if(a[mid]<a[mid+1]){    //peak is to the right of mid
                l=mid+1;
            }
            else{   //peak is to the left of mid or mid itself
                h=mid;
            }
        }
        return a[l];    //element found i.e. l=h
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends