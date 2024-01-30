/* 7) Write a program in C/C++ to print the characters that appear more than once in an
array.
Note: The maximum size of the array is 10.
Example:
Input: zzaabbcdbbaaz
Output: zab */

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    char arr[20];
    cout<<endl<<"Enter the characters of the array:"<<endl;
    cin>>arr;

    map<char,int>mp;
    for(int i=0;arr[i]!='\0';i++){
        mp[arr[i]]++;
    }

    for(auto it:mp){
        cout<<it.first<<"\t"<<it.second;
        cout<<endl;
    }

    cout<<endl<<"The characters that appear more than once in the array are:"<<endl;

    for(auto it:mp){
        if(it.second!=1){
            cout<<it.first<<"\t";
        }
    }

    return 0;
}