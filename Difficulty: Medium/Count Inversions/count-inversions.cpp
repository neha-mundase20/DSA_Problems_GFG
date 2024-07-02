//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(long long arr[],int low, int mid, int high, long long*inversionCount){
        
        vector<long long>temp;
        
        int left=low,right=mid+1;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{   //Inversion is found
                temp.push_back(arr[right]);
                right++;
                *inversionCount+=mid-left+1;
                /*This is because all remaining elements in the left 
                subarray are greater than the current element in the right subarray.*/
            }
        }
        
        while(left<=mid){   //If elements are left in the left array
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high){ //If elements are left in the right array
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long i=0;i<high-low+1;i++){
            arr[low+i]=temp[i];
        }
        
    }
    
    void mergeSort(long long arr[],int low,int high,long long*inversionCount){
        
        if(low>=high){
            return;
        }
        int mid=(low+((high-low)/2));
        
        mergeSort(arr,low,mid,inversionCount);
        mergeSort(arr,mid+1,high,inversionCount);
        
        merge(arr,low,mid,high,inversionCount);
        
    }
    
    long long int inversionCount(long long arr[], int n) {
        long long inversionCount=0;
        /*bool isSwapped=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    isSwapped=true;
                    inversionCount++;
                }
            }
            if(isSwapped==false){   //If no swapping i.e. array is sorted
                break;
            }
        }
        return inversionCount;*/
        
        int low=0,high=n-1;
        
        mergeSort(arr,low,high,&inversionCount);
        
        return inversionCount;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends