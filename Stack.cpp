#include<bits/stdc++.h>
using namespace std;

//LIFO - Last In First Out

int main(){
    stack<int> st;
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.push(3); //{3,2,1}
    cout<<st.top()<<endl;   //3
    st.pop();   //3
    
    return 0;
}