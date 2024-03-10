//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        
        long long totalSum=0,leftSum=0;
        
        if(n==1){
            return a[0];
        }
        else{
            for(int i=0;i<n;i++){   //calculate total sum of the array
                totalSum=totalSum+a[i];
            }
            
            for(int i=0;i<n;i++){
                if(leftSum==(totalSum-a[i])){
                                                // Check if the sum of elements before the current index
                                                // is equal to the sum of elements after it
                    return i+1;
                    break;
                }
                leftSum=leftSum+a[i];
                totalSum=totalSum-a[i];
            }
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends