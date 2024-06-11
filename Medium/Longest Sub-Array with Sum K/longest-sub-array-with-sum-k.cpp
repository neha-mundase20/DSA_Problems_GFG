//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int>hashmap;    //stores the sum value occured at specified index
        int sum=0,maxLength=0;
        
        for(int i=0;i<N;i++){
            sum=sum+A[i];
            
            if(sum==K){     //If we obtained the required sum as 'K'
                maxLength=max(maxLength,i+1);
            }
            
            //To check if we obtained any subarray, as we want 'K' subarray we subtract 'K'
            //from sum and check if the remaining sum has already occured. If remaining sum
            //has already occured then what is left is the 'K' subarray
            
            int rem=sum-K;
            
            if(hashmap.find(sum)==hashmap.end()){   
                //storing sum value obtained at specified index
                hashmap[sum]=i;
            }
            if(hashmap.find(rem)!=hashmap.end()){   
                //If remaining sum subarray has already occured
                int len=i-hashmap[rem];
                maxLength=max(maxLength,len);
            }
        }
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends