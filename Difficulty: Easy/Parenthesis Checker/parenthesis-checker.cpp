//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>stk;
        for(int i=0;x[i]!='\0';i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                stk.push(x[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                else{
                   if((stk.top()=='(' && x[i]==')') || (stk.top()=='{' && x[i]=='}')
                    || (stk.top()=='[' && x[i]==']')){
                        stk.pop();
                    }
                    else{
                        return false;   //mismatched closing brackets
                    }
                }
            }
        }
        return stk.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends