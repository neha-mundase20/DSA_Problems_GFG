#include<bits/stdc++.h>
using namespace std;

int main(){
    //Map stores key value pairs in sorted key order
    map<int,string> mp;
    mp[0]="Blue";
    mp[1]="Pink";
    mp[2]="Blue";

    for(auto it:mp){
        cout<<it.first<<"\t"<<it.second<<endl;
    }
    return 0;
}