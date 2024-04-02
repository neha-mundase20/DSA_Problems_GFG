//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    string str;
	    set<char>st;    //set stores only unique values and in ordered format
	    
	    for(char c : S) {
	        if(st.find(c) == st.end()) {   // If the element isn't already present in the set
	            //st.find() will return adress of end element
	            st.insert(c);
	            str.push_back(c);
	        }
	    }
	    return str;  // Return the string without duplicates
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends