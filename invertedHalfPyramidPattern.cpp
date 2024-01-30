/*2) Given an integer ‘N’, print the corresponding Numeric Inverted Half Pyramid pattern
for ‘N’.
Example:
Input: 4 (Value of N)
Output:
1 2 3 4
1 2 3
1 2
1 */

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<endl<<"Enter the number:"<<endl;
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}

