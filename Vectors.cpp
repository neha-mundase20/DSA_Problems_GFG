#include<bits/stdc++.h>
using namespace std;

int main(){
    //Vectors can dynamically change their sizes unlike arrays

    vector<int> v1;
    v1.push_back(1);    //creates a copy and then inserts in the vector
    v1.emplace_back(2); //directly inserts without creating any copy

    vector<pair<int,int>>v2;    //vector of pairs
    v2.push_back({1,2});
    v2.emplace_back(3,4);

    vector<int>v3(5,100); //a vector of size 5 having 5 instances of 100
    //even if we add more elements size increases dynamically

    vector<int>v4(v3);  //copying vector 3 into vector 4

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<"\t";
    }
    cout<<"\n"; 

    //Iterators

    vector<int>::iterator it = v1.begin();  //'it' points to memory address of the first element of the vector
    cout<<(*it)<<endl;  //to retreive value at the memory address

    for(vector<int> :: iterator it=v1.begin();it!=v1.end();it++){
        cout<<*it<<"\t";
    }

    //for each loop
    for(auto it/*not an iterator*/:v1){    //auto automatically detects the datatype
        cout<<it<<"\t";
    }

    v1.pop_back();  //pops the elements from front end

    return 0;
}