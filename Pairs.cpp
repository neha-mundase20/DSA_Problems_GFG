#include<bits/stdc++.h>
using namespace std;

int main(){
    pair <int,int> p1 = {1,3};
    cout<<p1.first<<endl;   //1
    cout<<p1.second<<endl;  //3

    pair<int,pair<int,int>> p2 = {1,{2,3}};
    cout<<p2.first<<endl;   //1
    cout<<p2.second.first<<endl;    //2
    cout<<p2.second.second<<endl;      //3

    //Array of pairs

    pair<int,string> arr[] = {{1,"Blue"},{2,"Lavender"}};

    cout<<arr[0].first<<endl;
    cout<<arr[0].second<<endl;

    return 0;
}