/*
Parenthesis Checker
Easy Accuracy: 28.56% Submissions: 538K+ Points: 2
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balanced pairs, with 0 number of 
unbalanced bracket.
Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.
Your Task:
This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.

Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 32000
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {   int flag = 1;
        stack<char>stk;
        if(x.size()%2!=0){    //odd number of elements in the string
            flag=0;
        }
        else{
            for(int i=0;i<x.size();){
                if(x[i]=='[' || x[i]=='{' || x[i]=='('){
                    stk.push(x[i]);
                    i++;
                }
                else{
                    if(!stk.empty() && ((stk.top()=='[' && x[i]==']') || (stk.top()=='{' && x[i]=='}') || (stk.top()=='(' && x[i]==')'))){
                        stk.pop();
                        i++;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
            }
        }

        if(flag==0){
            return false;
        }
        else{
            return true;
        }
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

/*
259 /261
For Input: 
[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[.................
 Input is too large Download Full File 
Your Code's output is: 
balanced
It's Correct output is: 
not balanced
Output Difference
not balanced
*/