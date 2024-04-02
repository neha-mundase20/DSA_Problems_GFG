//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        map<char,int> m1,m2;
        
        if(a.size()==b.size()){ //then only the strings can be anagrams
            for(int i=0;i<a.size();i++){
            m1[a[i]]++;
            }
        
            for(int i=0;i<b.size();i++){
                m2[b[i]]++;
            }
            
            for(auto it = m1.begin(); it!= m1.end(); ++it){
                //m1.begin() and m1.end() will return addresses hence 'it' is a pointer so we need to
                //access 'first' and 'second' properties using -> operator
                char key =it->first;
                int val1 =it->second;
                int val2=m2[key];
                
                if(val1 != val2){
                    return false;
                }
                
            }
            return true;
        }
        
        else{
             return false;
        }
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends