//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> v;
        int i=0,j=0;
        
        sort(A,A+N);	//sort array A
        sort(B,B+M);	//sort array B
        
        while(i<N && j<M){
            if(j==M-1){	//if last element of the array B is reached
                if((A[i]+B[j])==X){
                    v.push_back({A[i],B[j]});
                    i=i+1;
                    j=0;
                }
                else{
                    i=i+1;
                    j=0;
                }
            }
            else{	//if last element of array B is not reached
                if((A[i]+B[j])==X){
                    v.push_back({A[i],B[j]});
                    j=j+1;
                }
                else{
                    j=j+1;
                }
            }
        }
        return v;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends
