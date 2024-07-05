//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    /*int floorValue=INT_MIN,ceilValue=INT_MAX,low=0,high=n-1;
    
    sort(arr,arr+n);
    
    while(low<=high){
        int mid=low+((high-low)/2);
        
        if(arr[mid]<x){
            floorValue=max(floorValue,arr[mid]);
            low=mid+1;
        }
        else if(arr[mid]>x){
            ceilValue=min(ceilValue,arr[mid]);
            high=mid-1;
        }
        else{
           floorValue=arr[mid];
           ceilValue=arr[mid];
           break;
        }
    }
    return {floorValue,ceilValue};*/
    
    int floorValue=-1,ceilValue=-1;
    
    for(int i=0;i<n;i++){
        if(arr[i]<x){
            floorValue=max(floorValue,arr[i]);
        }
        else if(arr[i]>x){
            if(ceilValue==-1){  //Very first ceil element
                ceilValue=arr[i];
            }
            ceilValue=min(ceilValue,arr[i]);
        }
        else{
            floorValue=arr[i];
            ceilValue=arr[i];
            return {floorValue,ceilValue};
        }
    }
    
    return {floorValue,ceilValue};
}