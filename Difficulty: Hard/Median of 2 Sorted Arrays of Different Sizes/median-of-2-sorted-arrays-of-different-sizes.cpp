//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int m=array1.size(),n=array2.size();
        int i=0,j=0,k=0;
        vector<int>answer(m+n);
        
        while(i<m && j<n){
            if(array1[i]<=array2[j]){
                answer[k]=array1[i];
                i++;
                k++;
            }
            else{
                answer[k]=array2[j];
                j++;
                k++;
            }
        }
        
        while(i<m){
            answer[k]=array1[i];
            i++;
            k++;
        }
        
        while(j<n){
            answer[k]=array2[j];
            j++;
            k++;
        }
        
        // Calculate the median
        int total=m+n;
        
        if(total%2==0) { // Even number of elements
            return (answer[(total/2)-1]+answer[total/2])/2.0;
        } 
        else{ // Odd number of elements
            return answer[total/2];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends