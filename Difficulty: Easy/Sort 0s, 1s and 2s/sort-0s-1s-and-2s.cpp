//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zeroCount=0,oneCount=0,twoCount=0;
        
        for(auto it:arr){
            if(it==0){
                zeroCount++;
            }
            else if(it==1){
                oneCount++;
            }
            else{
                twoCount++;
            }
        }
        
        int i=0;
        
        while(zeroCount>0){
            arr[i++]=0;
            zeroCount--;
        }
        
        while(oneCount>0){
            arr[i++]=1;
            oneCount--;
        }
        
        while(twoCount>0){
            arr[i++]=2;
            twoCount--;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends