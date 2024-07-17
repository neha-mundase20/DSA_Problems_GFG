//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        int occurence=0,occurenceIndex=0;
        bool isFound=false;
        
        for(int i=0;s[i]!='\0';i++){
            if(s[i]==ch){
                occurence++;
            }
            
            if(occurence==count){
                isFound=true;
                occurenceIndex=i;
                break;
            }
        }
        
        
        if(isFound==false){
            return "";
        }
        string solution;
        for(int i=occurenceIndex+1;s[i]!='\0';i++){
            solution=solution+s[i];
        }
        
        return solution;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends