/* 3) Write a program to input T numbers (N) from the user and find the reverse of the given
number.
Input: T (number of test cases)
N (integer number)
Example:
Input:
3
1234
1200
102
Output:
4321
21
201 */

#include<iostream>
using namespace std;

void reverse(char arr[]){
    int n;
    for(int i=0;;i++){
        if(arr[i]=='\0'){
            n=i;
            break;
        }
    }

    for (int i=0,j=n-1;i<j;i++,j--) {
        char temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    char arr[20];
    cout<<endl<<"Enter the number:"<<endl;
    cin>>arr;
    reverse(arr);
    int i=0;
    while(arr[i]!='\0'){
        cout<<arr[i];
        i++;
    }
    return 0;
}