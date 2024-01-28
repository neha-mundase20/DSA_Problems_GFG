/*Subarray with given sum
Medium Accuracy: 16.5%Submissions: 1.5MPoints: 4

Given an unsorted array A of size N that contains only non negative integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.
Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N, and S as input parameters and returns an ArrayList containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the array should be according to 1-based indexing. If no such subarray is found, return an array consisting of only one element that is -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
0 <= Ai <= 109
0<= S <= 109 */

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//use dynamically sized sliding window concept

vector<int> subarraySum(vector<int>arr, int n, long long s)
    {   
        vector<int>v;
        
        int i=0;
        int sum=arr[i];
        int j=0;
        int flag=0;
        
        if(s==0){  //provided s value is 0
            for(int it=0;it<arr.size();it++){
                if(arr[it]==0){   //if the element 0 is found in the array
                    v.push_back(it+1);
                    v.push_back(it+1);
                    flag=1;
                }
            }
            if(flag==0){
                v.push_back(-1);   //if the element 0 isn't found in the array
            }
        }
        else{
            while(i<n && j<n){
                if(sum<s){   //sum of elements in window is less than required
                    j++;
                    if(j==n){
                        v.push_back(-1);
                        break;
                    }
                    sum=sum+arr[j];
                }
                else if(sum>s){   //sum of elements in window is greater than required
                    sum=sum-arr[i];
                    i++;
                }
                else if(sum==s){  //perfect subset with required sum
                    v.push_back(i+1);
                    v.push_back(j+1);
                    break;
                }
            }
        }
        return v;
    }

    int main(){
        vector<int> v1;
        int s=12;
        vector<int> arr={1,2,3,7,5};
        v1=subarraySum(arr,arr.size(),s);
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<"\t";
        }
        return 0;
    }

