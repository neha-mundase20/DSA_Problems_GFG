//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>hashmap;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            if(hashmap.find(arr[i])==hashmap.end()){    
                //If element hasn't occured already then store index coz we are 
                //searching for first occurence
                hashmap[arr[i]]=i+1;
            }
        }
        
        int repeatingElement=0;
        int index=INT_MAX;
        bool found=false;
        
        for(auto it:mp){
            if(it.second>1 && hashmap[it.first]<index){
                repeatingElement=it.first;
                index=hashmap[it.first];
                found=true;
            }
        }
        
        if(found==false){
            return -1;
        }
        return index;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.firstRepeated(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends