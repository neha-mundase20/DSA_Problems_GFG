/* 5) Given an array of length N that contains only integers, the task is to print the special
numbers of the array. A number in this array is called a Special number if it is divisible
by at least one other number in the array.
Example:
Input: 2 3 4 6 8 9
Output: 4 6 8 9 */

#include<iostream>
using namespace std;

void findSpecialNumber(int arr[],int n){
    int i=0;
    int j=0;

    cout<<endl<<"Special Numbers are:"<<endl;

    while(i<n && j<n){
        int isSpecial=0;

        if(arr[i]%arr[j]==0 && i!=j){
            isSpecial=1;
            cout<<endl<<arr[i]<<endl;
            i++;
            j=0;
        }
        else{
            j++;
        }
        if(isSpecial==0 && j==n-1){
            j=0;
            i++;
        }
    }
}

int main(){
    int n,arr[20];
    cout<<endl<<"Enter the size of the array:"<<endl;
    cin>>n;
    cout<<endl<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findSpecialNumber(arr,n);
    return 0;
}