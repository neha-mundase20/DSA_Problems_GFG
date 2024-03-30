//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int>v;
        unordered_map<int,int>mp;
        
        for(int i=0;i<k;i++){   //create a frequency map for first 'k' elements
            mp[A[i]]++;
        }
        
        // Add the count of distinct elements in the first window
        v.push_back(mp.size());

        //Now just slide the window and subtract the occurence of left element of the sliding window 
        //and add the occurence of right element of the sliding window
        // Slide the window and update the frequency map
        for (int i = k; i < n; ++i) {
        // Remove the element going out of the window
            mp[A[i - k]]--;
            if (mp[A[i - k]] == 0) {    //if occurence of element becomes '0', erase the element
                mp.erase(A[i - k]);
            }
        
        // Add the new element to the window
        mp[A[i]]++;
        
        // Add the count of distinct elements to the result
        v.push_back(mp.size());
    }

    return v;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends