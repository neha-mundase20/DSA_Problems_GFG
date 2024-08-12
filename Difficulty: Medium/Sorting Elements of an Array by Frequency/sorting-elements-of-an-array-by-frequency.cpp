//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    
    struct Value{
        int num;
        int freq;
    };
    
    static bool sortVal(const Value&a,const Value&b){
        if(a.freq==b.freq){
            return a.num<b.num;
        }
        return a.freq>b.freq;
    }
    
    vector<int> sortByFreq(vector<int>& arr) {
        vector<Value>v;
        map<int,int>mp;
        vector<int>solution;
        
        for(auto it:arr){
            mp[it]++;
        }
        
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end(),sortVal);
        
        for(auto it:v){
            for(int i=0;i<it.freq;i++){
                solution.push_back(it.num);
            }
        }
        return solution;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends